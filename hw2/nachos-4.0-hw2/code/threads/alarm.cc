// alarm.cc
//	Routines to use a hardware timer device to provide a
//	software alarm clock.  For now, we just provide time-slicing.
//
//	Not completely implemented.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "alarm.h"
#include "main.h"

//----------------------------------------------------------------------
// Alarm::Alarm
//      Initialize a software alarm clock.  Start up a timer device
//
//      "doRandom" -- if true, arrange for the hardware interrupts to
//		occur at random, instead of fixed, intervals.
//----------------------------------------------------------------------

Alarm::Alarm(bool doRandom)
{
    timer = new Timer(doRandom, this);
}

//----------------------------------------------------------------------
// Alarm::CallBack
//	Software interrupt handler for the timer device. The timer device is
//	set up to interrupt the CPU periodically (once every TimerTicks).
//	This routine is called each time there is a timer interrupt,
//	with interrupts disabled.
//
//	Note that instead of calling Yield() directly (which would
//	suspend the interrupt handler, not the interrupted thread
//	which is what we wanted to context switch), we set a flag
//	so that once the interrupt handler is done, it will appear as
//	if the interrupted thread called Yield at the point it is
//	was interrupted.
//
//	For now, just provide time-slicing.  Only need to time slice
//      if we're currently running something (in other words, not idle).
//	Also, to keep from looping forever, we check if there's
//	nothing on the ready list, and there are no other pending
//	interrupts.  In this case, we can safely halt.
//----------------------------------------------------------------------

void Alarm::CallBack()
{
    Interrupt *interrupt = kernel->interrupt;
    MachineStatus status = interrupt->getStatus();

    //<TODO>

    // In each 100 ticks,

    // 1. Update Priority

    // 2. Update RunTime & RRTime

    // 3. Check Round Robin

    Statistics *stats = kernel->stats;

    if (kernel->currentThread != NULL)
    {
        kernel->currentThread->set_RunTime(kernel->currentThread->get_RunTime() + 100);
        kernel->currentThread->set_RRTime(kernel->currentThread->get_RRTime() + 100);

        if (kernel->currentThread->get_Priority() >= 100 && kernel->scheduler->TotalFront() != NULL && kernel->scheduler->TotalFront()->get_Priority() >= 100 &&
            (kernel->currentThread->get_RemainingBurstTime() > kernel->scheduler->TotalFront()->get_RemainingBurstTime()))
        {
            kernel->interrupt->YieldOnReturn();
            // DEBUG(dbgMLFQ, "[L1 preemptive] Tick ["<< stats->totalTicks << "]: Thread [" << kernel->currentThread->getID() <<"] preemptived by Thread [" << kernel->scheduler->TotalFront()->getID() << "]" );
            // DEBUG(dbgMLFQ, "RemainingBurstTime1 : " << kernel->currentThread->get_RemainingBurstTime() << ", RemainingBurstTime2 : " << kernel->scheduler->TotalFront()->get_RemainingBurstTime());
        }

        if (kernel->currentThread->get_Priority() >= 50 && kernel->currentThread->get_Priority() < 100 && kernel->scheduler->TotalFront() != NULL &&
            kernel->scheduler->TotalFront()->get_Priority() >= 100)
        {
            kernel->interrupt->YieldOnReturn();
            // DEBUG(dbgMLFQ, "[L2 preemptive] Tick ["<< stats->totalTicks << "]: Thread [" << kernel->currentThread->getID() <<"] preemptived by Thread [" << kernel->scheduler->TotalFront()->getID() << "]" );
        }

        if (kernel->currentThread->get_Priority() >= 0 && kernel->currentThread->get_Priority() <= 49 && kernel->scheduler->TotalFront() != NULL &&
            (kernel->currentThread->get_RRTime() >= 200 || kernel->scheduler->TotalFront()->get_Priority() >= 50))
        { // L3: RR and preemptive
            // kernel->currentThread->Yield();
            kernel->interrupt->YieldOnReturn();
            // DEBUG(dbgMLFQ, "[L3 preemptive] Tick ["<< stats->totalTicks << "]: Thread [" << kernel->currentThread->getID() <<"] preemptived by Thread [" << kernel->scheduler->TotalFront()->getID() << "]" );
        }

        kernel->scheduler->UpdatePriority();
    }

    //<TODO>

    //    if (status == IdleMode) {    // is it time to quit?
    //        if (!interrupt->AnyFutureInterrupts()) {
    //        timer->Disable(); // turn off the timer
    // }
    //    } else {         // there's someone to preempt
    //    interrupt->YieldOnReturn();
    //    }
}
