// addrspace.cc
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -n -T 0 option
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "addrspace.h"
#include "machine.h"
#include "noff.h"

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void
SwapHeader(NoffHeader *noffH)
{
    noffH->noffMagic = WordToHost(noffH->noffMagic);
    noffH->code.size = WordToHost(noffH->code.size);
    noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
    noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
    noffH->initData.size = WordToHost(noffH->initData.size);
    noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
    noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
    noffH->uninitData.size = WordToHost(noffH->uninitData.size);
    noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
    noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Set up the translation from program memory to physical
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//----------------------------------------------------------------------

AddrSpace::AddrSpace()
{
    ID = (kernel->machine->ID_num) + 1;
    kernel->machine->ID_num = kernel->machine->ID_num + 1;
    /*    pageTable = new TranslationEntry[NumPhysPages];
    for (unsigned int i = 0; i < NumPhysPages; i++) {
	pageTable[i].virtualPage = i;	// for now, virt page # = phys page #
	pageTable[i].physicalPage = i;
//	pageTable[i].physicalPage = 0;
	pageTable[i].valid = TRUE;
//	pageTable[i].valid = FALSE;
	pageTable[i].use = FALSE;
	pageTable[i].dirty = FALSE;
	pageTable[i].readOnly = FALSE;  
    }
*/
    // zero out the entire address space
    //    bzero(kernel->machine->mainMemory, MemorySize);
}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{
    delete pageTable;
}

//----------------------------------------------------------------------
// AddrSpace::Load
// 	Load a user program into memory from a file.
//
//	Assumes that the page table has been initialized, and that
//	the object code file is in NOFF format.
//
//	"fileName" is the file containing the object code to load into memory
//----------------------------------------------------------------------

bool AddrSpace::Load(char *fileName)
{
    OpenFile *executable = kernel->fileSystem->Open(fileName);
    NoffHeader noffH;

    unsigned int size, k;

    if (executable == NULL)
    {
        cerr << "Unable to open file " << fileName << "\n";
        return FALSE;
    }
    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) &&
        (WordToHost(noffH.noffMagic) == NOFFMAGIC))
        SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

    cout << "size for code, inidata, and uninitdata: " << noffH.code.size << ", " << noffH.initData.size << ", " << noffH.uninitData.size << endl;

    // how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize; // we need to increase the size
                                                                                          // to leave room for the stack
    numPages = divRoundUp(size, PageSize);
    //	cout << "number of pages of " << fileName<< " is "<<numPages<<endl;

    pageTable = new TranslationEntry[numPages];

    size = numPages * PageSize;

    //   ASSERT(numPages <= NumPhysPages);		// check we're not trying
    // to run anything too big --
    // at least until we have
    // virtual memory

    //   DEBUG(dbgAddr, "Initializing address space: " << numPages << ", " << size);

    // then, copy in the code and data segments into memory

    int PageIndex = 0;
    while ((PageIndex + 1) * PageSize < noffH.code.size)
    {
        PutInPageTable(PageIndex, executable, pageTable, noffH.code.inFileAddr, 0, PageIndex);
        PageIndex++;
    }

    int offset = noffH.code.size - PageIndex * PageSize;
    // cout << "offset = " << offset << endl;

    if (noffH.initData.size == 0)
    {
        while (PageIndex < numPages)
        {
            PutInPageTable(PageIndex, executable, pageTable, noffH.code.inFileAddr, 0, PageIndex);
            PageIndex++;
        }
    }
    else
    {
        PutInPageTableWithOffset(PageIndex, executable, pageTable, noffH.code.inFileAddr, noffH.initData.inFileAddr, offset);
        PageIndex++;

        int InitDataPageIndex = PageIndex;
        while ((PageIndex + 1) * PageSize < noffH.code.size + noffH.initData.size)
        {
            PutInPageTable(PageIndex, executable, pageTable, noffH.initData.inFileAddr, PageSize - offset, PageIndex - InitDataPageIndex);
            printf("Put page %d of InitData + %d at Page %d.\n", PageIndex - InitDataPageIndex, PageSize - offset, PageIndex);
            PageIndex++;
        }

        cout << "test, NewOffset = " << offset << endl;

        PutInPageTableWithOffset2(PageIndex, executable, pageTable, noffH.initData.inFileAddr + PageSize - offset, noffH.code.inFileAddr, offset, PageIndex - InitDataPageIndex);
        PageIndex++;

        cout << "test2" << endl;

        while (PageIndex < numPages)
        {
            PutInPageTable(PageIndex, executable, pageTable, noffH.code.inFileAddr, offset, PageIndex);
            PageIndex++;
        }
    }

    // if (noffH.code.size > 0)
    // {
    //     //        DEBUG(dbgAddr, "Initializing code segment.");
    //     //	DEBUG(dbgAddr, noffH.code.virtualAddr << ", " << noffH.code.size);

    //     for (unsigned int i = 0; i < numPages; i++)
    //     {
    //         PutInPageTable(i, executable, pageTable, noffH.code.inFileAddr);
    //     }
    // }

    // if (noffH.initData.size > 0)
    // {
    //     //        DEBUG(dbgAddr, "Initializing data segment.");
    //     //	DEBUG(dbgAddr, noffH.initData.virtualAddr << ", " << noffH.initData.size);
    //     executable->ReadAt(
    //         &(kernel->machine->mainMemory[noffH.initData.virtualAddr]),
    //         noffH.initData.size, noffH.initData.inFileAddr);
    // }

    delete executable; // close file
    return TRUE;       // success
}

void AddrSpace::PutInPageTable(int i, OpenFile *executable, TranslationEntry *pageTable, int Addr, int Start, int i_2)
{
    int j = 0;
    while (kernel->machine->usedPhyPage[j] != FALSE && j < NumPhysPages)
    {
        j++;
    }

    //if memory is enough,just put data in without using virtual memory
    if (j < NumPhysPages)
    {
        kernel->machine->usedPhyPage[j] = TRUE;
        kernel->machine->PhyPageName[j] = ID;
        kernel->machine->main_tab[j] = &pageTable[i];
        pageTable[i].physicalPage = j;
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
        pageTable[i].ID = ID;
        pageTable[i].count++;               //for LRU,count+1 when save in memory
        pageTable[i].reference_bit = FALSE; //for second chance algo.
        executable->ReadAt(&(kernel->machine->mainMemory[j * PageSize]), PageSize, Start + Addr + (i_2 * PageSize));
    }
    //Use virtual memory when memory isn't enough
    else
    {
        char *buf;
        buf = new char[PageSize];
        int k = 0;
        while (kernel->machine->usedvirPage[k] != FALSE)
        {
            k++;
        }

        kernel->machine->usedvirPage[k] = true;
        pageTable[i].virtualPage = k; //record which virtualpage you save
        pageTable[i].valid = FALSE;   //not load in main_memory
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
        pageTable[i].ID = ID;
        executable->ReadAt(buf, PageSize, Start + Addr + (i_2 * PageSize));
        kernel->vm_Disk->WriteSector(k, buf); //call virtual_disk write in virtual memory
    }
}

void AddrSpace::PutInPageTableWithOffset(int i, OpenFile *executable, TranslationEntry *pageTable, int Addr, int Addr2, int offset)
{
    int j = 0;
    while (kernel->machine->usedPhyPage[j] != FALSE && j < NumPhysPages)
    {
        j++;
    }

    //if memory is enough,just put data in without using virtual memory
    if (j < NumPhysPages)
    {
        kernel->machine->usedPhyPage[j] = TRUE;
        kernel->machine->PhyPageName[j] = ID;
        kernel->machine->main_tab[j] = &pageTable[i];
        pageTable[i].physicalPage = j;
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
        pageTable[i].ID = ID;
        pageTable[i].count++;               //for LRU,count+1 when save in memory
        pageTable[i].reference_bit = FALSE; //for second chance algo.
        executable->ReadAt(&(kernel->machine->mainMemory[j * PageSize]), offset, Addr + (i * PageSize));
        executable->ReadAt(&(kernel->machine->mainMemory[j * PageSize + offset]), PageSize - offset, Addr2);
        // cout << "first read at: " << j * PageSize << " for " << offset << " bits, " << endl;
        // cout << "then read at: " << j * PageSize + offset << " for " << PageSize - offset << " bits, " << endl;
    }
    //Use virtual memory when memory isn't enough
    else
    {
        char *buf, *buf1, *buf2;
        buf1 = new char[offset];
        buf2 = new char[PageSize - offset];
        int k = 0;
        while (kernel->machine->usedvirPage[k] != FALSE)
        {
            k++;
        }

        kernel->machine->usedvirPage[k] = true;
        pageTable[i].virtualPage = k; //record which virtualpage you save
        pageTable[i].valid = FALSE;   //not load in main_memory
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
        pageTable[i].ID = ID;
        executable->ReadAt(buf1, offset, Addr + (i * PageSize));
        executable->ReadAt(buf2, PageSize - offset, Addr2);
        buf = concat(buf1, buf2, offset);
        kernel->vm_Disk->WriteSector(k, buf); //call virtual_disk write in virtual memory
    }
}

void AddrSpace::PutInPageTableWithOffset2(int i, OpenFile *executable, TranslationEntry *pageTable, int Addr, int Addr2, int offset, int i_2)
{
    int j = 0;
    while (kernel->machine->usedPhyPage[j] != FALSE && j < NumPhysPages)
    {
        j++;
    }

    //if memory is enough,just put data in without using virtual memory
    if (j < NumPhysPages)
    {
        kernel->machine->usedPhyPage[j] = TRUE;
        kernel->machine->PhyPageName[j] = ID;
        kernel->machine->main_tab[j] = &pageTable[i];
        pageTable[i].physicalPage = j;
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
        pageTable[i].ID = ID;
        pageTable[i].count++;               //for LRU,count+1 when save in memory
        pageTable[i].reference_bit = FALSE; //for second chance algo.
        executable->ReadAt(&(kernel->machine->mainMemory[j * PageSize]), offset, Addr + (i_2 * PageSize));
        executable->ReadAt(&(kernel->machine->mainMemory[j * PageSize + offset]), PageSize - offset, Addr2 + (i * PageSize));
        cout << "first read at: " << j * PageSize << " for " << offset << " bits, at page " << i_2 << endl;
        cout << "then read at: " << j * PageSize + offset << " for " << PageSize - offset << " bits, at page " << i << endl;
    }
    //Use virtual memory when memory isn't enough
    else
    {
        char *buf, *buf1, *buf2;
        buf1 = new char[offset];
        buf2 = new char[PageSize - offset];
        int k = 0;
        while (kernel->machine->usedvirPage[k] != FALSE)
        {
            k++;
        }

        kernel->machine->usedvirPage[k] = true;
        pageTable[i].virtualPage = k; //record which virtualpage you save
        pageTable[i].valid = FALSE;   //not load in main_memory
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
        pageTable[i].ID = ID;
        executable->ReadAt(buf1, offset, Addr + (i_2 * PageSize));
        executable->ReadAt(buf2, PageSize - offset, Addr2 + (i * PageSize));
        buf = concat(buf1, buf2, offset);
        cout << "first read at: " << j * PageSize << " for " << offset << " bits, at page " << i_2 << endl;
        cout << "then read at: " << j * PageSize + offset << " for " << PageSize - offset << " bits, at page " << i << endl;
        kernel->vm_Disk->WriteSector(k, buf); //call virtual_disk write in virtual memory
    }
}

char *AddrSpace::concat(const char *s1, const char *s2, int offset)
{
    char *result = new char[PageSize];
    memcpy(result, s1, offset);
    memcpy(result + offset, s2, PageSize - offset);
    return result;
}

//----------------------------------------------------------------------
// AddrSpace::Execute
// 	Run a user program.  Load the executable into memory, then
//	(for now) use our own thread to run it.
//
//	"fileName" is the file containing the object code to load into memory
//----------------------------------------------------------------------

void AddrSpace::Execute(char *fileName)
{
    pt_is_load = FALSE;
    if (!Load(fileName))
    {
        cout << "inside !Load(FileName)" << endl;
        return; // executable not found
    }

    //kernel->currentThread->space = this;
    this->InitRegisters(); // set the initial register values
    this->RestoreState();  // load page table register
    pt_is_load = TRUE;
    kernel->machine->Run(); // jump to the user progam

    ASSERTNOTREACHED(); // machine->Run never returns;
                        // the address space exits
                        // by doing the syscall "exit"
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void AddrSpace::InitRegisters()
{
    Machine *machine = kernel->machine;
    int i;

    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

    // Set the stack register to the end of the address space, where we
    // allocated the stack; but subtract off a bit, to make sure we don't
    // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG(dbgAddr, "Initializing stack pointer: " << numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, don't need to save anything!
//----------------------------------------------------------------------

void AddrSpace::SaveState()
{
    if (pt_is_load)
    {
        pageTable = kernel->machine->pageTable;
        numPages = kernel->machine->pageTableSize;
    }
}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState()
{
    kernel->machine->pageTable = pageTable;
    kernel->machine->pageTableSize = numPages;
}