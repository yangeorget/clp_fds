/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_misc.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_misc.h"
#include "sfd_misc.usr"


#define ASCII_PRED "bt_inc"
#define PRED       X62745F696E63
#define ARITY      0

Begin_Public_Pred
      put_constant(X2462746E756D626572,2,"$btnumber")
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      math_load_x_value(0,0)
      function_1(inc,0,0)
      put_constant(X2462746E756D626572,1,"$btnumber")
      builtin_2(g_assign,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bt_reset"
#define PRED       X62745F7265736574
#define ARITY      0

Begin_Public_Pred
      put_constant(X2462746E756D626572,1,"$btnumber")
      put_integer(0,0)
      builtin_2(g_assign,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bt_get"
#define PRED       X62745F676574
#define ARITY      1

Begin_Public_Pred
      put_constant(X2462746E756D626572,1,"$btnumber")
      builtin_2(g_read,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bt_save"
#define PRED       X62745F73617665
#define ARITY      0

Begin_Public_Pred
      put_constant(X2462746E756D626572,2,"$btnumber")
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      put_constant(X2462746E756D62657273617665,1,"$btnumbersave")
      builtin_2(g_assign,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bt_restore"
#define PRED       X62745F726573746F7265
#define ARITY      0

Begin_Public_Pred
      put_constant(X2462746E756D62657273617665,2,"$btnumbersave")
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      put_constant(X2462746E756D626572,1,"$btnumber")
      builtin_2(g_assign,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_misc)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X62745F696E63,"bt_inc")
 Define_Atom(X2462746E756D626572,"$btnumber")
 Define_Atom(X62745F7265736574,"bt_reset")
 Define_Atom(X62745F676574,"bt_get")
 Define_Atom(X62745F73617665,"bt_save")
 Define_Atom(X2462746E756D62657273617665,"$btnumbersave")
 Define_Atom(X62745F726573746F7265,"bt_restore")


 Define_Pred(X62745F696E63,0,1)

 Define_Pred(X62745F7265736574,0,1)

 Define_Pred(X62745F676574,1,1)

 Define_Pred(X62745F73617665,0,1)

 Define_Pred(X62745F726573746F7265,0,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_misc)



End_Exec_Directives
