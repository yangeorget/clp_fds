#define A_NAME        "Sets 4"

#define AddA(x,y)       ((x)|(y))
#define MulA(x,y)       ((x)&(y))

#define A_SIZE        4
#define A_SIZE_BITS   2
#define A_WD_SZ_BITS  3  
#define A_MASK        0xF

#define A_FORMAT      "%x" 

#define GreaterOrEqualA(x,y)   (AddA(x,y) == x) 
#define GreaterA(x,y)          ((x != y) && (AddA(x,y) == x))  
#define LessOrEqualA(x,y)      (AddA(x,y) == y) 
#define LessA(x,y)             ((x != y) && (AddA(x,y) == y))
