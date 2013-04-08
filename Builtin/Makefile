# /*-----------------------------------------------------------------------*/
# /*  clp(FD)                            INRIA Rocquencourt - CLoE Project */
# /*                                                           Daniel Diaz */
# /*                                                                       */
# /* Makefile                                                              */
# /*-----------------------------------------------------------------------*/

#############################################################################
# Builtin Makefile
# Modified by Yan Georget
# June 1998
#############################################################################

#############################################################################
# variables
#############################################################################

COMPILER  = ../src/clp_fds
CC        = gcc
WCC       = ../src/wam_$(CC)

PFLAGS    = 
CFLAGS    = -O2 -I../src
LFLAGS    = -s
#CFLAGS    = -g -I../src
#LFLAGS    = 

PLBIPS    = inline.o read.o write.o format.o dec10io.o const.o term.o \
	    misc.o call.o oper.o list.o trace.o assert.o setof.o bits.o

SFDBIPS   = sfd_arithmetic.o sfd_arithmetic_complex.o sfd_bool.o \
	    sfd_domain.o sfd_enumeration.o sfd_meta.o sfd_misc.o \
	    sfd_optimization.o sfd_relation.o sfd_semiring.o sfd_retraction.o \
	    sfd_srg_sets.o sfd_srg_bool.o

OTHERS    = lib_inline.o

#############################################################################
# rules
#############################################################################

.SUFFIXES:
.SUFFIXES: .o .usr .c .pl $(SUFFIXES)

.pl.c:
	$(COMPILER) $(PFLAGS) -c $*.pl
.pl.usr:
	if [ -f $*.usr ]; then \
	touch $*.usr; \
	else \
	$(COMPILER) $(PFLAGS) -c $*.pl; \
	fi
.usr.o:
	$(WCC) $(CFLAGS) -c $*.c
.c.o:
	$(WCC) $(CFLAGS) -c $*.c

#############################################################################
# entries
#############################################################################

all: ../src/builtin.o

#############################################################################
# execs
#############################################################################

build_starter: build_starter.c
	$(CC) $(CFLAGS) $(LFLAGS) -o build_starter build_starter.c

#############################################################################
# objects
#############################################################################

../src/builtin.o: build_starter starter.o $(PLBIPS) $(SFDBIPS) $(OTHERS)
	ld -r -o ../src/builtin.o starter.o $(PLBIPS) $(SFDBIPS) $(OTHERS)

starter.c: build_starter 
	build_starter $(PLBIPS) $(SFDBIPS) > starter.c

# plbips
inline.o   : inline.c inline.usr
read.o     : read.c read.usr
write.o    : write.c write.usr
format.o   : format.c format.usr
dec10io.o  : dec10io.c dec10io.usr
const.o    : const.c const.usr
term.o     : term.c term.usr
misc.o     : misc.c misc.usr
call.o     : call.c call.usr
oper.o     : oper.c oper.usr
list.o     : list.c list.usr
trace.o    : trace.c trace.usr
assert.o   : assert.c assert.usr
setof.o    : setof.c setof.usr
bits.o     : bits.c bits.usr

# sfdbips
sfd_arithmetic.o  	: sfd_arithmetic.c sfd_arithmetic.usr\
			  ../src/sfd_semiring.h
sfd_arithmetic_complex.o: sfd_arithmetic_complex.c sfd_arithmetic_complex.usr\
			  ../src/sfd_semiring.h
sfd_bool.o 	  	: sfd_bool.c sfd_bool.usr\
			  ../src/sfd_semiring.h
sfd_domain.o 	  	: sfd_domain.c sfd_domain.usr\
			  ../src/sfd_semiring.h
sfd_enumeration.o 	: sfd_enumeration.c sfd_enumeration.usr\
			  ../src/sfd_semiring.h
sfd_meta.o 	  	: sfd_meta.c sfd_meta.usr\
			  ../src/sfd_semiring.h
sfd_misc.o 	  	: sfd_misc.c sfd_misc.usr\
			  ../src/sfd_semiring.h
sfd_optimization.o	: sfd_optimization.c sfd_optimization.usr\
			  ../src/sfd_semiring.h
sfd_relation.o 	  	: sfd_relation.c sfd_relation.usr\
			  ../src/sfd_semiring.h
sfd_semiring.o    	: sfd_semiring.c sfd_semiring.usr\
			 ../src/sfd_semiring.h	 	
sfd_retraction.o        : sfd_retraction.c sfd_retraction.usr\
			 ../src/sfd_semiring.h
sfd_srg_sets.o	  	: sfd_srg_sets.c sfd_srg_sets.usr\
			 ../src/sfd_semiring.h
sfd_srg_bool.o	  	: sfd_srg_bool.c sfd_srg_bool.usr\
			 ../src/sfd_semiring.h

#############################################################################
# clean
#############################################################################

clean:
	-rm *.o build_starter








