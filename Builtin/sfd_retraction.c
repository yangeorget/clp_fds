/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
File : sfd_retraction.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"
#include "sfd_engine.h"

#include "sfd_retraction.h"
#include "sfd_retraction.usr"


#define ASCII_PRED "cstrs_block_start"
#define PRED       X63737472735F626C6F636B5F7374617274
#define ARITY      0

Begin_Public_Pred
      pragma_c(Cstrs_Block_Start_0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cstrs_block_start"
#define PRED       X63737472735F626C6F636B5F7374617274
#define ARITY      1

Begin_Public_Pred
      pragma_c(Cstrs_Block_Start_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cstrs_block_end"
#define PRED       X63737472735F626C6F636B5F656E64
#define ARITY      1

Begin_Public_Pred
      pragma_c(Cstrs_Block_End_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cstrs_block_retract"
#define PRED       X63737472735F626C6F636B5F72657472616374
#define ARITY      1

Begin_Public_Pred
      pragma_c(Cstrs_Block_Retract_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cstrs_block_tell"
#define PRED       X63737472735F626C6F636B5F74656C6C
#define ARITY      1

Begin_Public_Pred
      pragma_c(Cstrs_Block_Tell_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cstrs_block_size"
#define PRED       X63737472735F626C6F636B5F73697A65
#define ARITY      2

Begin_Public_Pred
      pragma_c(Cstrs_Block_Size_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fdv_cstrs_block_put"
#define PRED       X6664765F63737472735F626C6F636B5F707574
#define ARITY      2

Begin_Public_Pred
      pragma_c(Fdv_Cstrs_Block_Put_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fdv_cstrs_block_get"
#define PRED       X6664765F63737472735F626C6F636B5F676574
#define ARITY      2

Begin_Public_Pred
      pragma_c(Fdv_Cstrs_Block_Get_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fdv_cstrs_block_clear"
#define PRED       X6664765F63737472735F626C6F636B5F636C656172
#define ARITY      1

Begin_Public_Pred
      put_integer(0,1)
      execute(Pred_Name(X6664765F63737472735F626C6F636B5F707574,2),1,"fdv_cstrs_block_put",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fdv_cstrs_block_retract"
#define PRED       X6664765F63737472735F626C6F636B5F72657472616374
#define ARITY      1

Begin_Public_Pred
      allocate(1)
      put_y_variable(0,1)
      call(Pred_Name(X6664765F63737472735F626C6F636B5F676574,2),1,1,"fdv_cstrs_block_get",2)          /* begin sub 1 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X63737472735F626C6F636B5F72657472616374,1),1,"cstrs_block_retract",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fdv_cstrs_block_tell"
#define PRED       X6664765F63737472735F626C6F636B5F74656C6C
#define ARITY      1

Begin_Public_Pred
      allocate(1)
      put_y_variable(0,1)
      call(Pred_Name(X6664765F63737472735F626C6F636B5F676574,2),1,1,"fdv_cstrs_block_get",2)          /* begin sub 1 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X63737472735F626C6F636B5F74656C6C,1),1,"cstrs_block_tell",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(sfd_retraction)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X63737472735F626C6F636B5F7374617274,"cstrs_block_start")
 Define_Atom(X63737472735F626C6F636B5F656E64,"cstrs_block_end")
 Define_Atom(X63737472735F626C6F636B5F72657472616374,"cstrs_block_retract")
 Define_Atom(X63737472735F626C6F636B5F74656C6C,"cstrs_block_tell")
 Define_Atom(X63737472735F626C6F636B5F73697A65,"cstrs_block_size")
 Define_Atom(X6664765F63737472735F626C6F636B5F707574,"fdv_cstrs_block_put")
 Define_Atom(X6664765F63737472735F626C6F636B5F676574,"fdv_cstrs_block_get")
 Define_Atom(X6664765F63737472735F626C6F636B5F636C656172,"fdv_cstrs_block_clear")
 Define_Atom(X6664765F63737472735F626C6F636B5F72657472616374,"fdv_cstrs_block_retract")
 Define_Atom(X6664765F63737472735F626C6F636B5F74656C6C,"fdv_cstrs_block_tell")


 Define_Pred(X63737472735F626C6F636B5F7374617274,0,1)

 Define_Pred(X63737472735F626C6F636B5F7374617274,1,1)

 Define_Pred(X63737472735F626C6F636B5F656E64,1,1)

 Define_Pred(X63737472735F626C6F636B5F72657472616374,1,1)

 Define_Pred(X63737472735F626C6F636B5F74656C6C,1,1)

 Define_Pred(X63737472735F626C6F636B5F73697A65,2,1)

 Define_Pred(X6664765F63737472735F626C6F636B5F707574,2,1)

 Define_Pred(X6664765F63737472735F626C6F636B5F676574,2,1)

 Define_Pred(X6664765F63737472735F626C6F636B5F636C656172,1,1)

 Define_Pred(X6664765F63737472735F626C6F636B5F72657472616374,1,1)

 Define_Pred(X6664765F63737472735F626C6F636B5F74656C6C,1,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(sfd_retraction)



End_Exec_Directives
