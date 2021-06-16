// addrspace.h
//	Data structures to keep track of executing user programs
//	(address spaces).
//
//	For now, we don't keep any information about address spaces.
//	The user level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include <string.h>

#define UserStackSize 8192 // increase this as necessary!

class AddrSpace
{
public:
  AddrSpace();  // Create an address space.
  ~AddrSpace(); // De-allocate an address space

  void Execute(char *fileName); // Run the the program
                                // stored in the file "executable"

  void SaveState();    // Save/restore address space-specific
  void RestoreState(); // info on a context switch
  int ID;

  void reset_VirPages() {
        
    for (int page_i = 0; page_i < numPages; page_i++) {
        // pageTable[page_i].valid = FALSE;   //not load in main_memory
        // pageTable[page_i].use = FALSE;
        // pageTable[page_i].dirty = FALSE;
        // pageTable[page_i].readOnly = FALSE;                    
        pageTable[page_i].count = 0;   //for LFU
        pageTable[page_i].reference_bit = true; //for second chance algo.
        pageTable[page_i].demand_time = 0;
    }
      
  };

private:
  TranslationEntry *pageTable;

  // Assume linear page table translation
  // for now!
  
  unsigned int numPages; // Number of pages in the virtual
                         // address space

  bool Load(char *fileName); // Load the program into memory
                             // return false if not found
  void PutInPageTable(int i, OpenFile *executable, TranslationEntry *pageTable, int Addr, int Start, int i_2);
  void PutInPageTableWithOffset(int i, OpenFile *executable, TranslationEntry *pageTable, int Addr, int Addr2, int offset);

  char *concat(const char *s1, const char *s2, int offset);

  void InitRegisters(); // Initialize user-level CPU registers,
                        // before jumping to user code
  bool pt_is_load;
};

#endif // ADDRSPACE_H
