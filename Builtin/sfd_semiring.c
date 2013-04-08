/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_semiring.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_semiring.h"
#include "sfd_semiring.usr"


#define ASCII_PRED "semiring_mul"
#define PRED       X73656D6972696E675F6D756C
#define ARITY      3

Begin_Public_Pred
      pragma_c(Semiring_Mul_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_add"
#define PRED       X73656D6972696E675F616464
#define ARITY      3

Begin_Public_Pred
      pragma_c(Semiring_Add_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_unity"
#define PRED       X73656D6972696E675F756E697479
#define ARITY      1

Begin_Public_Pred
      pragma_c(Semiring_Unity_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_null"
#define PRED       X73656D6972696E675F6E756C6C
#define ARITY      1

Begin_Public_Pred
      pragma_c(Semiring_Null_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_greater"
#define PRED       X73656D6972696E675F67726561746572
#define ARITY      2

Begin_Public_Pred
      pragma_c(Semiring_Greater_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_greatereq"
#define PRED       X73656D6972696E675F677265617465726571
#define ARITY      2

Begin_Public_Pred
      pragma_c(Semiring_GreaterEq_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_less"
#define PRED       X73656D6972696E675F6C657373
#define ARITY      2

Begin_Public_Pred
      pragma_c(Semiring_Less_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_lesseq"
#define PRED       X73656D6972696E675F6C6573736571
#define ARITY      2

Begin_Public_Pred
      pragma_c(Semiring_LessEq_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_size"
#define PRED       X73656D6972696E675F73697A65
#define ARITY      1

Begin_Public_Pred
      pragma_c(Semiring_Size_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "semiring_value_write"
#define PRED       X73656D6972696E675F76616C75655F7772697465
#define ARITY      1

Begin_Public_Pred
      pragma_c(Semiring_Value_Write_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_semiring)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X73656D6972696E675F6D756C,"semiring_mul")
 Define_Atom(X73656D6972696E675F616464,"semiring_add")
 Define_Atom(X73656D6972696E675F756E697479,"semiring_unity")
 Define_Atom(X73656D6972696E675F6E756C6C,"semiring_null")
 Define_Atom(X73656D6972696E675F67726561746572,"semiring_greater")
 Define_Atom(X73656D6972696E675F677265617465726571,"semiring_greatereq")
 Define_Atom(X73656D6972696E675F6C657373,"semiring_less")
 Define_Atom(X73656D6972696E675F6C6573736571,"semiring_lesseq")
 Define_Atom(X73656D6972696E675F73697A65,"semiring_size")
 Define_Atom(X73656D6972696E675F76616C75655F7772697465,"semiring_value_write")


 Define_Pred(X73656D6972696E675F6D756C,3,1)

 Define_Pred(X73656D6972696E675F616464,3,1)

 Define_Pred(X73656D6972696E675F756E697479,1,1)

 Define_Pred(X73656D6972696E675F6E756C6C,1,1)

 Define_Pred(X73656D6972696E675F67726561746572,2,1)

 Define_Pred(X73656D6972696E675F677265617465726571,2,1)

 Define_Pred(X73656D6972696E675F6C657373,2,1)

 Define_Pred(X73656D6972696E675F6C6573736571,2,1)

 Define_Pred(X73656D6972696E675F73697A65,1,1)

 Define_Pred(X73656D6972696E675F76616C75655F7772697465,1,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_semiring)



End_Exec_Directives
