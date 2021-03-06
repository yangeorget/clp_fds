# /*-----------------------------------------------------------------------*/
# /*  clp(FD)                            INRIA Rocquencourt - CLoE Project */
# /*                                                           Daniel Diaz */
# /*                                                                       */
# /* Makefile                                                              */
# /*-----------------------------------------------------------------------*/

#############################################################################
# Main Makefile
# Modified by Yan Georget
# June 1998
#############################################################################

#############################################################################
# variables
#############################################################################

CC       = gcc
WCC      = wam_$(CC)

#############################################################################
# entries
#############################################################################

semiring:
	cd Builtin ; make
	cd src     ; make
install:
	cd Builtin ; touch *.c 
	cd src     ; touch *.c ; make $(WCC) 
	cd Builtin ; make
	cd src     ; make


#############################################################################
# clean
#############################################################################

clean:
	cd src     ; make clean
	cd Builtin ; make clean
