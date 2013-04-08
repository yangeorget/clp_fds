/****************************************************************************
Prolog to Wam Compiler - Version 2.0
Daniel Diaz, Yan Georget
1998 - INRIA Rocquencourt - LOCO Project
file : wamcc1.h
****************************************************************************/

#define NB_OF_PRIVATE_PREDS    59

static char    *module_name="wamcc1";
static int      module_nb;

static AtomInf *X5B5D;
static AtomInf *X73756372655F73796E74617869717565;
static AtomInf *X73756372655F73796E746178697175655F2461757833;
static AtomInf *X6E6F5F696E6C696E65;
static AtomInf *X66;
static AtomInf *X73756372655F73796E746178697175655F2461757832;
static AtomInf *X64796E;
static AtomInf *X6E625F636C617573655F64796E;
static AtomInf *X2464796E5F;
static AtomInf *X6173736572747A;
static AtomInf *X73756372655F73796E746178697175655F2461757831;
static AtomInf *X3A2D;
static AtomInf *X6E6F726D616C6973655F63757473;
static AtomInf *X6E6F726D616C6973655F637574735F2461757834;
static AtomInf *X74;
static AtomInf *X2C;
static AtomInf *X246765745F62635F726567;
static AtomInf *X6E6F726D616C6973655F6375747331;
static AtomInf *X63616C6C;
static AtomInf *X3B;
static AtomInf *X2D3E;
static AtomInf *X24637574;
static AtomInf *X6661696C;
static AtomInf *X5C2B;
static AtomInf *X74727565;
static AtomInf *X21;
static AtomInf *X6E6F726D616C6973655F63757473315F2461757835;
static AtomInf *X6E6F726D616C6973655F616C7473;
static AtomInf *X6465627567;
static AtomInf *X6E6F726D616C6973655F616C74735F2461757836;
static AtomInf *X6E6F726D616C6973655F616C74735F2461757837;
static AtomInf *X646566;
static AtomInf *X246462675F74727565;
static AtomInf *X6E6F726D616C6973655F616C747331;
static AtomInf *X617578;
static AtomInf *X24617578;
static AtomInf *X5F;
static AtomInf *X6E6F726D616C6973655F616C7473315F2461757838;
static AtomInf *X5F24617578;
static AtomInf *X6C696E656172697365;
static AtomInf *X6C696E6561726973655F2461757839;
static AtomInf *X6C696E65617269736531;
static AtomInf *X6C696E656172697365315F246175783130;
static AtomInf *X6C73745F766172;
static AtomInf *X6C73745F7661725F61726773;
static AtomInf *X6C73745F7661725F617267735F246175783131;
static AtomInf *X6E6F726D616C6973655F666463;
static AtomInf *X6E6F726D616C6973655F6664635F246175783132;
static AtomInf *X2466645F7365745F4146;
static AtomInf *X6E6F726D616C6973655F66646331;
static AtomInf *X696E;
static AtomInf *X6E6F5F666463;
static AtomInf *X6676;
static AtomInf *X63737472;
static AtomInf *X233D;
static AtomInf *X235C3D;
static AtomInf *X233E3D;
static AtomInf *X233E;
static AtomInf *X233C3D;
static AtomInf *X233C;
static AtomInf *X6E6F726D616C6973655F666463315F246175783134;
static AtomInf *X2466645F63737472;
static AtomInf *X6E6F726D616C6973655F666463315F246175783133;
static AtomInf *X6E6F5F6F707432;
static AtomInf *X6E6F726D616C6973655F666463315F246175783135;
static AtomInf *X766572626F7365;
static AtomInf *X6E6F726D616C6973655F666463315F246175783136;
static AtomInf *X6E6F726D616C6973655F666463315F246175783137;
static AtomInf *X6E6F726D616C6973655F666463315F246175783138;
static AtomInf *X6E6F726D616C6973655F666463315F246175783139;
static AtomInf *X6E6F726D616C6973655F666463315F246175783230;
static AtomInf *X7472616974655F66645F617267;
static AtomInf *X6670;
static AtomInf *X7472616974655F66645F6172675F246175783231;
static AtomInf *X72;
static AtomInf *X7472616974655F66645F6172675F246175783232;
static AtomInf *X7472616974655F66645F6172675F246175783233;
static AtomInf *X7369676D61;
static AtomInf *X6D696E;
static AtomInf *X6D6178;
static AtomInf *X76616C;
static AtomInf *X6E6F5F66645F617267;
static AtomInf *X617267;
static AtomInf *X637265655F66645F415F6672616D65;
static AtomInf *X637265655F66645F415F6672616D655F246175783235;
static AtomInf *X637265655F66645F415F6672616D655F246175783234;
static AtomInf *X2466645F6670;
static AtomInf *X2466645F6676;
static AtomInf *X7472616E73665F6571;
static AtomInf *X7472616E73665F6E65;
static AtomInf *X70616320783C3E79;
static AtomInf *X7472616E73665F6765;
static AtomInf *X70616320783E3D79;
static AtomInf *X7472616E73665F67;
static AtomInf *X70616320783E79;
static AtomInf *X65715F766172;
static AtomInf *X2A;
static AtomInf *X65715F7661725F246175783236;
static AtomInf *X70616320782B633D79;
static AtomInf *X7061632061782B633D79;
static AtomInf *X65715F7661725F246175783237;
static AtomInf *X7061632061783D79;
static AtomInf *X65715F7661725F246175783238;
static AtomInf *X7061632061782B792B633D7A;
static AtomInf *X7061632061782B62792B633D7A;
static AtomInf *X65715F7661725F246175783239;
static AtomInf *X7061632061782B793D7A;
static AtomInf *X7061632061782B62793D7A;
static AtomInf *X65715F7661725F246175783330;
static AtomInf *X70616320782B793D7A;
static AtomInf *X65715F7661725F246175783331;
static AtomInf *X70616320782B792B633D7A;
static AtomInf *X65715F7661725F246175783332;
static AtomInf *X7061632061782B792B7A3D74;
static AtomInf *X7061632061782B62792B7A3D74;
static AtomInf *X65715F7661725F246175783333;
static AtomInf *X70616320782B792B7A3D74;
static AtomInf *X6E6F726D616C697A65;
static AtomInf *X2D;
static AtomInf *X6E6F726D616C697A655F246175783334;
static AtomInf *X6E6F726D616C697A6531;
static AtomInf *X2B;
static AtomInf *X6E6F726D616C697A65315F246175783335;
static AtomInf *X617070656E645F776974685F616464;
static AtomInf *X73756D5F696E5F6C697374;
static AtomInf *X73706C6974;
static AtomInf *X72657665727365;

static SwtTbl   Swt_Table_Name(X6E6F726D616C6973655F6375747331,4,2,stc);
static SwtTbl   Swt_Table_Name(X6E6F726D616C6973655F616C747331,7,2,stc);
static SwtTbl   Swt_Table_Name(X6E6F726D616C6973655F66646331,7,1,stc);
