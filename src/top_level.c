/****************************************************************************
Prolog to Wam Compiler - Version 1.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : top_level.c
Main : main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "top_level.h"
#include "top_level.usr"


#define ASCII_PRED "$exe_1"
#define PRED       X246578655F31
#define ARITY      0

Begin_Private_Pred
      put_constant(X74727565,0,"true")
      put_constant(X74727565,1,"true")
      execute(Pred_Name(X746F705F6C6576656C,2),0,"top_level",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(top_level)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X246578655F31,"$exe_1")
 Define_Atom(X74727565,"true")


 Define_Pred(X246578655F31,0,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(top_level)


 Exec_Directive(1,Pred_Name(X246578655F31,0))

End_Exec_Directives


/*** MAIN ***/

int main(int argc,char *argv[])

{
 unix_argc=argc;
 unix_argv=argv;


 Init_Wam_Engine();

 Init_Tables_Of_Module(Builtin)
 Init_Tables_Of_Module(top_level)

 Exec_Directives_Of_Module(Builtin)
 Exec_Directives_Of_Module(top_level)

 Term_Wam_Engine();

 return 0;
}
