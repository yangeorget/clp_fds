#include "wam_engine.h"


#define Pl_Init_Wam_And_Module(argc,argv,m)                                 \
    {                                                                       \
     unix_argc=argc;                                                        \
     unix_argv=argv;                                                        \
                                                                            \
                                                                            \
     Init_Wam_Engine();                                                     \
                                                                            \
     Init_Tables_Of_Module(Builtin)                                         \
     Init_Tables_Of_Module(m)                                               \
                                                                            \
     Exec_Directives_Of_Module(Builtin)                                     \
     Exec_Directives_Of_Module(m)                                           \
    }




#define Pl_ReInit_Wam                                                       \
     Reinit_Wam_Engine();




#define Pl_Term_Wam                                                         \
     Term_Wam_Engine();




#define Pl_Query(predhex,arity,code_else)                                   \
    {                                                                       \
     Prototype(Prefix(Pred_Name(predhex,arity)))                            \
     if (!Call_Prolog((CodePtr) Prefix(Pred_Name(predhex,arity))))          \
         {code_else}                                                        \
    }


#define Pl_Next_Solution(code_else)                                         \
     if (!Call_Prolog_Next_Sol())                                           \
         {code_else}                                                        \



#define Put_Nil(a)  Put_Constant(atom_nil,a)
