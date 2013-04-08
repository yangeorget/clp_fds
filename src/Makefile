# /*-----------------------------------------------------------------------*/
# /*  clp(FD)                            INRIA Rocquencourt - CLoE Project */
# /*                                                           Daniel Diaz */
# /*                                                                       */
# /* Makefile                                                              */
# /*-----------------------------------------------------------------------*/

#############################################################################
# src Makefile
# Modified by Yan Georget
# June 1998
#############################################################################

#############################################################################
# variables
#############################################################################

COMPILER  = clp_fds
CC        = gcc
WCC       = wam_$(CC)
PLCOMP    = clp_fds
INCPATH   = `pwd`
LIBPATH   = `pwd`


CFLAGINLIN= -finline-functions
CFLAGS    = -O2
LFLAGS    = -s
#CFLAGS    = -g
#LFLAGS    = 

BMF       = bmf_$(COMPILER)
PLOBJLIB  = machine.o wam_engine.o atom_pred.o debugger.o hash.o malloc.o builtin.o
FDOBJLIB  = sfd_engine.o sfd_range.o sfd_vector.o
EXECS     = configure $(WCC) $(COMPILER) $(BMF)

#############################################################################
# entries
#############################################################################

all: $(WCC) lib$(COMPILER).a $(BMF) $(COMPILER)

#############################################################################
# execs
#############################################################################

configure: configure.c machine.h ../Makefile
	$(CC) $(CFLAGS) $(LFLAGS) -DCOMPILER='"'$(COMPILER)'"' \
		-DCC='"'$(CC)'"' -DWCC='"'$(WCC)'"' \
                -DINCPATH='"'$(INCPATH)'"' -DLIBPATH='"'$(LIBPATH)'"' \
                -o configure configure.c

$(WCC): configure archi.def
	configure
	chmod a+x $(WCC)

$(BMF): bmf.c
	$(CC) $(CFLAGS) $(LFLAGS)  \
		-DCOMPILER='"'$(COMPILER)'"' -DWCC='"'$(WCC)'"' \
		-o $(BMF) bmf.c

$(COMPILER): wamcc.o wamcc0.o wamcc1.o wamcc2.o wamcc3.o wamcc4.o wamcc5.o wamcc6.o wamcc7.o wamcc8.o lib$(COMPILER).a
	$(WCC) $(CFLAGS) $(LFLAGS) -o $(COMPILER) wamcc*.o -l$(COMPILER)

#############################################################################
# objects
#############################################################################

lib$(COMPILER).a: $(PLOBJLIB) $(FDOBJLIB)
	-rm lib$(COMPILER).a 
	ar rc lib$(COMPILER).a $(PLOBJLIB) $(FDOBJLIB)
	ranlib lib$(COMPILER).a

machine.o: machine.h archi.h wam_engine.h machine.c
	$(WCC) $(CFLAGS) -c machine.c

wam_engine.o: machine.h archi.h wam_engine.h atom_pred.h wam_engine.c 
	$(WCC) $(CFLAGS) -c wam_engine.c

atom_pred.o: machine.h archi.h wam_engine.h atom_pred.h atom_pred.c
	$(WCC) $(CFLAGS) -c atom_pred.c

debugger.o: machine.h archi.h wam_engine.h atom_pred.h debugger.c
	$(WCC) $(CFLAGS) -c debugger.c

hash.o: machine.h hash.c
	$(WCC) $(CFLAGS) -c hash.c

sfd_engine.o: machine.h archi.h wam_engine.h atom_pred.h \
             sfd_engine.h sfd_engine.c sfd_range.h sfd_vector.h sfd_semiring.h
	$(WCC) $(CFLAGS) $(CFLAGINLIN) -c sfd_engine.c

sfd_range.o: sfd_range.h sfd_vector.h sfd_semiring.h
	$(WCC) $(CFLAGS) $(CFLAGINLIN) -c sfd_range.c

sfd_vector.o: sfd_vector.h sfd_semiring.h
	$(WCC) $(CFLAGS) $(CFLAGINLIN) -c sfd_vector.c

wamcc.o: wamcc.c
	$(WCC) $(CFLAGS) -c wamcc.c
wamcc.c: wamcc.pl
	$(PLCOMP) wamcc.pl

wamcc0.o: wamcc0.c
	$(WCC) $(CFLAGS) -c wamcc0.c
wamcc0.c: wamcc0.pl
	$(PLCOMP) wamcc0.pl

wamcc1.o: wamcc1.c
	$(WCC) $(CFLAGS) -c wamcc1.c
wamcc1.c: wamcc1.pl
	$(PLCOMP) wamcc1.pl

wamcc2.o: wamcc2.c
	$(WCC) $(CFLAGS) -c wamcc2.c
wamcc2.c: wamcc2.pl
	$(PLCOMP) wamcc2.pl

wamcc3.o: wamcc3.c
	$(WCC) $(CFLAGS) -c wamcc3.c
wamcc3.c: wamcc3.pl
	$(PLCOMP) wamcc3.pl

wamcc4.o: wamcc4.c
	$(WCC) $(CFLAGS) -c wamcc4.c
wamcc4.c: wamcc4.pl
	$(PLCOMP) wamcc4.pl

wamcc5.o: wamcc5.c
	$(WCC) $(CFLAGS) -c wamcc5.c
wamcc5.c: wamcc5.pl
	$(PLCOMP) wamcc5.pl

wamcc6.o: wamcc6.c
	$(WCC) $(CFLAGS) -c wamcc6.c
wamcc6.c: wamcc6.pl
	$(PLCOMP) wamcc6.pl

wamcc7.o: wamcc7.c
	$(WCC) $(CFLAGS) -c wamcc7.c
wamcc7.c: wamcc7.pl
	$(PLCOMP) wamcc7.pl

wamcc8.o: wamcc8.c
	$(WCC) $(CFLAGS) -c wamcc8.c
wamcc8.c: wamcc8.pl
	$(PLCOMP) wamcc8.pl

#############################################################################
# clean
#############################################################################

clean:
	-rm *.o
	-rm *.a
	-rm $(EXECS)












