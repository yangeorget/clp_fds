#include "wam_engine.h"

#define  DEBUG_LEVEL         0
#define  NB_OF_PRIVATE_PREDS 0

static char *module_name="Builtin";
static int   module_nb= -1;

Begin_Init_Tables(Builtin)

 Init_Tables_Of_Module(inline)
 Init_Tables_Of_Module(read)
 Init_Tables_Of_Module(write)
 Init_Tables_Of_Module(format)
 Init_Tables_Of_Module(dec10io)
 Init_Tables_Of_Module(const)
 Init_Tables_Of_Module(term)
 Init_Tables_Of_Module(misc)
 Init_Tables_Of_Module(call)
 Init_Tables_Of_Module(oper)
 Init_Tables_Of_Module(list)
 Init_Tables_Of_Module(trace)
 Init_Tables_Of_Module(assert)
 Init_Tables_Of_Module(setof)
 Init_Tables_Of_Module(bits)
 Init_Tables_Of_Module(sfd_arithmetic)
 Init_Tables_Of_Module(sfd_arithmetic_complex)
 Init_Tables_Of_Module(sfd_bool)
 Init_Tables_Of_Module(sfd_domain)
 Init_Tables_Of_Module(sfd_enumeration)
 Init_Tables_Of_Module(sfd_meta)
 Init_Tables_Of_Module(sfd_misc)
 Init_Tables_Of_Module(sfd_optimization)
 Init_Tables_Of_Module(sfd_relation)
 Init_Tables_Of_Module(sfd_semiring)
 Init_Tables_Of_Module(sfd_retraction)
 Init_Tables_Of_Module(sfd_srg_sets)
 Init_Tables_Of_Module(sfd_srg_bool)

End_Init_Tables

Begin_Exec_Directives(Builtin)

 Exec_Directives_Of_Module(inline)
 Exec_Directives_Of_Module(read)
 Exec_Directives_Of_Module(write)
 Exec_Directives_Of_Module(format)
 Exec_Directives_Of_Module(dec10io)
 Exec_Directives_Of_Module(const)
 Exec_Directives_Of_Module(term)
 Exec_Directives_Of_Module(misc)
 Exec_Directives_Of_Module(call)
 Exec_Directives_Of_Module(oper)
 Exec_Directives_Of_Module(list)
 Exec_Directives_Of_Module(trace)
 Exec_Directives_Of_Module(assert)
 Exec_Directives_Of_Module(setof)
 Exec_Directives_Of_Module(bits)
 Exec_Directives_Of_Module(sfd_arithmetic)
 Exec_Directives_Of_Module(sfd_arithmetic_complex)
 Exec_Directives_Of_Module(sfd_bool)
 Exec_Directives_Of_Module(sfd_domain)
 Exec_Directives_Of_Module(sfd_enumeration)
 Exec_Directives_Of_Module(sfd_meta)
 Exec_Directives_Of_Module(sfd_misc)
 Exec_Directives_Of_Module(sfd_optimization)
 Exec_Directives_Of_Module(sfd_relation)
 Exec_Directives_Of_Module(sfd_semiring)
 Exec_Directives_Of_Module(sfd_retraction)
 Exec_Directives_Of_Module(sfd_srg_sets)
 Exec_Directives_Of_Module(sfd_srg_bool)

End_Exec_Directives

