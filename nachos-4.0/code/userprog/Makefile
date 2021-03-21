# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the multiprogramming assignment
#    Defines set up assuming multiprogramming is done before the file system.
#    If not, use the "filesys first"  defines below. 
#
#
# Copyright (c) 1992-1996 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DTHREADS -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB
INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine -I../lib
HFILES = $(THREAD_H) $(USERPROG_H)
CFILES = $(THREAD_C) $(USERPROG_C)
C_OFILES = $(THREAD_O) $(USERPROG_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
bitmap.o: ../lib/bitmap.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../lib/bitmap.h
debug.o: ../lib/debug.cc ../lib/copyright.h ../lib/utility.h \
 ../lib/debug.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h
hash.o: ../lib/hash.cc ../lib/copyright.h
libtest.o: ../lib/libtest.cc ../lib/copyright.h ../lib/libtest.h \
 ../lib/bitmap.h ../lib/utility.h ../lib/list.h ../lib/debug.h \
 ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../lib/list.cc ../lib/hash.h ../lib/hash.cc
list.o: ../lib/list.cc ../lib/copyright.h
sysdep.o: ../lib/sysdep.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/unistd.h \
 /usr/include/sys/access.h /usr/include/sys/time.h \
 /usr/include/sys/signal.h /usr/include/machine/signal.h \
 /usr/include/sys/procset.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/time.h \
 /usr/include/sys/timers.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/file.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/param.h \
 /usr/include/machine/machparam.h /usr/include/machine/endian.h \
 /usr/include/sys/fcntl.h /usr/include/sys/mode.h \
 /usr/include/signal.h /usr/include/sys/mman.h
interrupt.o: ../machine/interrupt.cc ../lib/copyright.h \
 ../machine/interrupt.h ../lib/list.h ../lib/debug.h ../lib/utility.h \
 ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../lib/list.cc ../machine/callback.h ../threads/main.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../machine/stats.h ../threads/alarm.h \
 ../machine/timer.h
stats.o: ../machine/stats.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../machine/stats.h
timer.o: ../machine/timer.cc ../lib/copyright.h ../machine/timer.h \
 ../lib/utility.h ../machine/callback.h ../threads/main.h \
 ../lib/debug.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../lib/list.h ../lib/list.cc \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h
alarm.o: ../threads/alarm.cc ../lib/copyright.h ../threads/alarm.h \
 ../lib/utility.h ../machine/callback.h ../machine/timer.h \
 ../threads/main.h ../lib/debug.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../lib/list.h ../lib/list.cc \
 ../machine/interrupt.h ../machine/stats.h
kernel.o: ../threads/kernel.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../threads/main.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../machine/callback.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h \
 ../threads/synch.h ../threads/synchlist.h ../threads/synchlist.cc \
 ../lib/libtest.h ../machine/elevatortest.h
main.o: ../threads/main.cc ../lib/copyright.h ../threads/main.h \
 ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h
scheduler.o: ../threads/scheduler.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../threads/scheduler.h ../lib/list.h ../lib/list.cc \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../machine/callback.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/main.h \
 ../userprog/userkernel.h ../threads/kernel.h ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h
synch.o: ../threads/synch.cc ../lib/copyright.h ../threads/synch.h \
 ../threads/thread.h ../lib/utility.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../lib/list.h ../lib/debug.h ../lib/list.cc \
 ../threads/main.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h
synchlist.o: ../threads/synchlist.cc ../lib/copyright.h \
 ../threads/synchlist.h ../lib/list.h ../lib/debug.h ../lib/utility.h \
 ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../lib/list.cc ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/main.h ../userprog/userkernel.h \
 ../threads/kernel.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h \
 ../threads/synchlist.cc
thread.o: ../threads/thread.cc ../lib/copyright.h ../threads/thread.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/switch.h ../threads/synch.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../threads/main.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h \
 ../machine/timer.h
elevatortest.o: ../machine/elevatortest.cc ../lib/copyright.h \
 ../machine/elevatortest.h ../machine/elevator.h ../lib/utility.h \
 ../machine/callback.h ../lib/list.h ../lib/debug.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../lib/list.cc ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/main.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h
elevator.o: ../machine/elevator.cc ../lib/copyright.h \
 ../machine/elevator.h ../lib/utility.h ../machine/callback.h \
 ../lib/list.h ../lib/debug.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../lib/list.cc ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h ../threads/main.h \
 ../userprog/userkernel.h
addrspace.o: ../userprog/addrspace.cc ../lib/copyright.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h ../bin/noff.h
exception.o: ../userprog/exception.cc ../lib/copyright.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h ../userprog/syscall.h
synchconsole.o: ../userprog/synchconsole.cc ../lib/copyright.h \
 ../userprog/synchconsole.h ../lib/utility.h ../machine/callback.h \
 ../machine/console.h ../threads/synch.h ../threads/thread.h \
 ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../threads/main.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h \
 ../machine/timer.h
userkernel.o: ../userprog/userkernel.cc ../lib/copyright.h \
 ../userprog/userkernel.h ../threads/kernel.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../machine/callback.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h
console.o: ../machine/console.cc ../lib/copyright.h \
 ../machine/console.h ../lib/utility.h ../machine/callback.h \
 ../threads/main.h ../lib/debug.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../lib/list.h ../lib/list.cc \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h \
 ../machine/timer.h
machine.o: ../machine/machine.cc ../lib/copyright.h \
 ../machine/machine.h ../lib/utility.h ../machine/translate.h \
 ../machine/disk.h ../machine/callback.h ../threads/main.h \
 ../lib/debug.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../lib/list.h ../lib/list.cc \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h \
 ../machine/timer.h
mipssim.o: ../machine/mipssim.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../machine/mipssim.h ../threads/main.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../lib/list.h ../lib/list.cc \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h \
 ../machine/timer.h
translate.o: ../machine/translate.cc ../lib/copyright.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/sww/lib/g++-include/iostream.h \
 /usr/sww/lib/g++-include/streambuf.h /usr/sww/lib/g++-include/libio.h \
 /usr/sww/lib/g++-include/_G_config.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdarg.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/va-alpha.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdlib.h \
 /usr/include/standards.h /usr/include/getopt.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/types.h \
 /usr/include/mach/machine/vm_types.h /usr/include/sys/select.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/stdio.h \
 /usr/include/sys/seek.h /usr/include/va_list.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/sys/limits.h \
 /usr/include/machine/machlimits.h /usr/include/sys/syslimits.h \
 /usr/include/machine/machtime.h /usr/include/sys/rt_limits.h \
 /usr/sww/lib/gcc-lib/alpha-dec-osf3.0/2.7.2/include/string.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../machine/callback.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/timer.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
