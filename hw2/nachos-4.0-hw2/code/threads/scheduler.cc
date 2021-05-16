// scheduler.cc 
//	Routines to choose the next thread to run, and to dispatch to
//	that thread.
//
// 	These routines assume that interrupts are already disabled.
//	If interrupts are disabled, we can assume mutual exclusion
//	(since we are on a uniprocessor).
//
// 	NOTE: We can't use Locks to provide mutual exclusion here, since
// 	if we needed to wait for a lock, and the lock was busy, we would 
//	end up calling FindNextToRun(), and that would put us in an 
//	infinite loop.
//
// 	Very simple implementation -- no priorities, straight FIFO.
//	Might need to be improved in later assignments.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "debug.h"
#include "scheduler.h"
#include "main.h"

//----------------------------------------------------------------------
// Scheduler::Scheduler
// 	Initialize the list of ready but not running threads.
//	Initially, no ready threads.
//----------------------------------------------------------------------



//<TODO>
// Declare sorting rule of SortedList for L1 & L2 ReadyQueue
// Hint: Funtion Type should be "static int"
static int compareL1(Thread* x, Thread* y)
{
//		returns -1 if x < y
//		returns 0 if x == y
//		returns 1 if x > y
    if (x->get_RemainingBurstTime() > y->get_RemainingBurstTime()) {
        return -1;
    } else if (x->get_RemainingBurstTime()  ==  y->get_RemainingBurstTime()) {
        return 0;
    } else if (x->get_RemainingBurstTime() < y->get_RemainingBurstTime()) {
        return 1;
    }
}

static int compareL2(Thread* x, Thread* y)
{
//		returns -1 if x < y
//		returns 0 if x == y
//		returns 1 if x > y
    if (x->getID() > y->getID()) {
        return -1;
    } else if (x->getID()  ==  y->getID()) {
        return 0;
    } else if (x->getID() < y->getID()) {
        return 1;
    }
}
//<TODO>

Scheduler::Scheduler()
{
//	schedulerType = type;
    // readyList = new List<Thread *>; 
    //<TODO>
    // Initialize L1, L2, L3 ReadyQueue
    L1ReadyQueue = new SortedList<Thread *>(&compareL1); 
    L2ReadyQueue = new SortedList<Thread *>(&compareL2);
    L3ReadyQueue = new List<Thread *>;
    //<TODO>
	toBeDestroyed = NULL;
} 

//----------------------------------------------------------------------
// Scheduler::~Scheduler
// 	De-allocate the list of ready threads.
//----------------------------------------------------------------------

Scheduler::~Scheduler()
{ 
    //<TODO>
    delete L1ReadyQueue;
    delete L2ReadyQueue;
    delete L3ReadyQueue;
    //<TODO>
    // delete readyList; 
} 

//----------------------------------------------------------------------
// Scheduler::ReadyToRun
// 	Mark a thread as ready, but not running.
//	Put it on the ready list, for later scheduling onto the CPU.
//
//	"thread" is the thread to be put on the ready list.
//----------------------------------------------------------------------

void
Scheduler::ReadyToRun (Thread *thread)
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);
    // DEBUG(dbgThread, "Putting thread on ready list: " << thread->getName());

    Statistics* stats = kernel->stats;
    //<TODO>
    int queuelevel = 0;
    // According to priority of Thread, put them into corresponding ReadyQueue.
    // After inserting Thread into ReadyQueue, don't forget to reset some values.
    // Hint: L2 ReadyQueue is preemptive priority.
    // When putting a new thread into L1 ReadyQueue, you need to check whether preemption or not.
    thread->setStatus(READY);
    if (thread->get_Priority() >= 0 && thread->get_Priority() <= 49) {
        L3ReadyQueue->Append(thread);
        queuelevel = 3;
    } else if (thread->get_Priority() >= 50 && thread->get_Priority() <= 99) {
        L2ReadyQueue->Insert(thread);
        queuelevel = 2;
    } else if (thread->get_Priority() >= 100 && thread->get_Priority() <= 149) {
        L1ReadyQueue->Insert(thread);
        queuelevel = 1;
    } else {
        cout << "NOT VALID PRIORITY" << endl;
    }
    DEBUG(dbgMLFQ, "[InsertToQueue] Tick ["<< stats->totalTicks << "]: Thread [" << thread->getID() <<"] is inserted into queue L" <<queuelevel);
    //<TODO>
    // readyList->Append(thread);
}

//----------------------------------------------------------------------
// Scheduler::FindNextToRun
// 	Return the next thread to be scheduled onto the CPU.
//	If there are no ready threads, return NULL.
// Side effect:
//	Thread is removed from the ready list.
//----------------------------------------------------------------------

Thread *
Scheduler::FindNextToRun ()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    /*if (readyList->IsEmpty()) {
    return NULL;
    } else {
        return readyList->RemoveFront();
    }*/

    //<TODO>
    Statistics* stats = kernel->stats;
    Thread* thread;
    // a.k.a. Find Next (Thread in ReadyQueue) to Run
    if (! L1ReadyQueue->IsEmpty()) {
        thread = L1ReadyQueue->RemoveFront();
	DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << thread->getID() <<"] is removed from queue L1");
        return thread;
    } else if (! L2ReadyQueue->IsEmpty()) {
        thread = L2ReadyQueue->RemoveFront();
	DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << thread->getID() <<"] is removed from queue L2");
        return thread;
    } else if (! L3ReadyQueue->IsEmpty()) {
	thread = L3ReadyQueue->RemoveFront();
        DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << thread->getID() <<"] is removed from queue L3");
        return thread;
    } else {
        return NULL;
    }
    //<TODO>
}

//----------------------------------------------------------------------
// Scheduler::Run
// 	Dispatch the CPU to nextThread.  Save the state of the old thread,
//	and load the state of the new thread, by calling the machine
//	dependent context switch routine, SWITCH.
//
//      Note: we assume the state of the previously running thread has
//	already been changed from running to blocked or ready (depending).
// Side effect:
//	The global variable kernel->currentThread becomes nextThread.
//
//	"nextThread" is the thread to be put into the CPU.
//	"finishing" is set if the current thread is to be deleted
//		once we're no longer running on its stack
//		(when the next thread starts running)
//----------------------------------------------------------------------

void
Scheduler::Run (Thread *nextThread, bool finishing)
{
    Thread *oldThread = kernel->currentThread;
 
//	cout << "Current Thread" <<oldThread->getName() << "    Next Thread"<<nextThread->getName()<<endl;
   
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    if (finishing) {	// mark that we need to delete current thread
         ASSERT(toBeDestroyed == NULL);
	     toBeDestroyed = oldThread;
    }
   
#ifdef USER_PROGRAM			// ignore until running user programs 
    if (oldThread->space != NULL) {	// if this thread is a user program,

        oldThread->SaveUserState(); 	// save the user's CPU registers
	    oldThread->space->SaveState();
    }
#endif
    
    oldThread->CheckOverflow();		    // check if the old thread
					    // had an undetected stack overflow

    kernel->currentThread = nextThread;  // switch to the next thread
    nextThread->setStatus(RUNNING);      // nextThread is now running
    
    // DEBUG(dbgThread, "Switching from: " << oldThread->getName() << " to: " << nextThread->getName());
    
    // This is a machine-dependent assembly language routine defined 
    // in switch.s.  You may have to think
    // a bit to figure out what happens after this, both from the point
    // of view of the thread and from the perspective of the "outside world".

    cout << "Switching from: " << oldThread->getID() << " to: " << nextThread->getID() << endl;
    SWITCH(oldThread, nextThread);

    // we're back, running oldThread
      
    // interrupts are off when we return from switch!
    ASSERT(kernel->interrupt->getLevel() == IntOff);

    DEBUG(dbgThread, "Now in thread: " << kernel->currentThread->getID());

    CheckToBeDestroyed();		// check if thread we were running
					// before this one has finished
					// and needs to be cleaned up
    
#ifdef USER_PROGRAM
    if (oldThread->space != NULL) {	    // if there is an address space
        oldThread->RestoreUserState();     // to restore, do it.
	    oldThread->space->RestoreState();
    }
#endif
}

//----------------------------------------------------------------------
// Scheduler::CheckToBeDestroyed
// 	If the old thread gave up the processor because it was finishing,
// 	we need to delete its carcass.  Note we cannot delete the thread
// 	before now (for example, in Thread::Finish()), because up to this
// 	point, we were still running on the old thread's stack!
//----------------------------------------------------------------------

void
Scheduler::CheckToBeDestroyed()
{
    if (toBeDestroyed != NULL) {
        DEBUG(dbgThread, "toBeDestroyed->getID(): " << toBeDestroyed->getID());
        delete toBeDestroyed;
	    toBeDestroyed = NULL;
    }
}
 
//----------------------------------------------------------------------
// Scheduler::Print
// 	Print the scheduler state -- in other words, the contents of
//	the ready list.  For debugging.
//----------------------------------------------------------------------
void
Scheduler::Print()
{
    cout << "Ready list contents:\n";
    // readyList->Apply(ThreadPrint);
    L1ReadyQueue->Apply(ThreadPrint);
    L2ReadyQueue->Apply(ThreadPrint);
    L3ReadyQueue->Apply(ThreadPrint);
}

Thread *
Scheduler::TotalFront ()
{
    ASSERT(kernel->interrupt->getLevel() == IntOff);
    Thread * thread;

    if (! L1ReadyQueue->IsEmpty()) {
        thread = L1ReadyQueue->Front();
        return thread;
    } else if (! L2ReadyQueue->IsEmpty()) {
        thread = L2ReadyQueue->Front();
        return thread;
    } else if (! L3ReadyQueue->IsEmpty()) {
	thread = L3ReadyQueue->Front();
        return thread;
    } else {
        return NULL;
    }

    //TODO>
}

// <TODO>

// Function 1. Function definition of sorting rule of L1 ReadyQueue

// Function 2. Function definition of sorting rule of L2 ReadyQueue

// Function 3. Scheduler::UpdatePriority()
// Hint:
// 1. ListIterator can help.
// 2. Update WaitTime and priority in Aging situations
// 3. After aging, Thread may insert to different ReadyQueue

void 
Scheduler::UpdatePriority()
{
    //ListIterator<Thread*> *iter2(L2ReadyQueue);
    // cout << "UpdatePriority\n";
    Thread* ReadyThread;
    ListIterator<Thread *> *iter1 = new ListIterator<Thread *>(L1ReadyQueue);
    ListIterator<Thread *> *iter2 = new ListIterator<Thread *>(L2ReadyQueue);
    Statistics* stats = kernel->stats;

    for (; !iter1->IsDone(); iter1->Next()) {
        ReadyThread = iter1->Item();
        ReadyThread->set_WaitTime(ReadyThread->get_WaitTime() + 100);
        if (ReadyThread->get_WaitTime() > 400) {
            
            ReadyThread->set_WaitTime(0);
	    if (ReadyThread->get_Priority() < 140) {
            
                DEBUG(dbgMLFQ, "[UpdatePriority] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] changes its priority from ["<<ReadyThread->get_Priority() <<"] to [" << ReadyThread->get_Priority() + 10 << "]");
                ReadyThread->set_Priority(ReadyThread->get_Priority() + 10);
                L1ReadyQueue->Remove(ReadyThread);
                DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is removed from queue L1");
                L1ReadyQueue->Insert(ReadyThread);
                DEBUG(dbgMLFQ, "[InsertToQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is inserted into queue L1");
            }
        }
    }


    for (; !iter2->IsDone(); iter2->Next()) {
        ReadyThread = iter2->Item();
        ReadyThread->set_WaitTime(ReadyThread->get_WaitTime() + 100);
        if (ReadyThread->get_WaitTime() > 400) {
            DEBUG(dbgMLFQ, "[UpdatePriority] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] changes its priority from ["<<ReadyThread->get_Priority() <<"] to [" << ReadyThread->get_Priority() + 10 << "]");
            ReadyThread->set_Priority(ReadyThread->get_Priority() + 10);
            ReadyThread->set_WaitTime(0);
            if (ReadyThread->get_Priority() >= 100) {
                L2ReadyQueue->Remove(ReadyThread);
                DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is removed from queue L2");
                L1ReadyQueue->Insert(ReadyThread);
                DEBUG(dbgMLFQ, "[InsertToQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is inserted into queue L1");
            }
            else {
                L2ReadyQueue->Remove(ReadyThread);
                DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is removed from queue L2");
                L2ReadyQueue->Insert(ReadyThread);
                DEBUG(dbgMLFQ, "[InsertToQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is inserted into queue L2");
            }
        }
    }

   // ListIterator<Thread*> *iter3(L3ReadyQueue);
   ListIterator<Thread *> *iter3 = new ListIterator<Thread *>(L3ReadyQueue);

    for (; !iter3->IsDone(); iter3->Next()) {
        ReadyThread = iter3->Item();
        ReadyThread->set_WaitTime(ReadyThread->get_WaitTime() + 100);
        if (ReadyThread->get_WaitTime() > 400) {
            DEBUG(dbgMLFQ, "[UpdatePriority]Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] changes its priority from ["<<ReadyThread->get_Priority() <<"] to [" << ReadyThread->get_Priority() + 10 << "]");
            ReadyThread->set_Priority(ReadyThread->get_Priority() + 10);
            ReadyThread->set_WaitTime(0);
            if (ReadyThread->get_Priority() >= 50) {
                L3ReadyQueue->Remove(ReadyThread);
                DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is removed from queue L3");
                L2ReadyQueue->Insert(ReadyThread);
                DEBUG(dbgMLFQ, "[InsertToQueue]Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is inserted into queue L2");
            }
            else {
                L3ReadyQueue->Remove(ReadyThread);
                DEBUG(dbgMLFQ, "[RemoveFromQueue] Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is removed from queue L3");
                L3ReadyQueue->Append(ReadyThread);
                DEBUG(dbgMLFQ, "[InsertToQueue]Tick ["<< stats->totalTicks << "]: Thread [" << ReadyThread->getID() <<"] is inserted into queue L3");
            }
        }
    } 
}

// <TODO>
