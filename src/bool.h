/*-------------------------------------------------------------------------*/
/* Boolean Type Definition                              Daniel Diaz - 1991 */
/*                                                                         */
/* bool.h                                                                  */
/*-------------------------------------------------------------------------*/

#ifndef TYPE_BOOL
#define TYPE_BOOL

#ifdef FALSE

#    if FALSE!=0
#        error "FALSE already defined with a value != 1"
#    endif
#else

#define FALSE 0

#endif

#ifdef TRUE

#    if TRUE!=1
#        error "TRUE already defined with a value != 1"
#    endif
#else

#define TRUE 1

#endif
typedef int Bool;

#endif
