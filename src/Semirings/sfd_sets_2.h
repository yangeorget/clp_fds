#define A_NAME        "Sets 2"

#define AddA(x,y)       ((x)|(y))
#define MulA(x,y)       ((x)&(y))

#define A_SIZE        2
#define A_SIZE_BITS   1
#define A_WD_SZ_BITS  4  
#define A_MASK        0x3

#define A_FORMAT      "%i" 

#define GreaterOrEqualA(x,y)   (AddA(x,y) == x) 
#define GreaterA(x,y)          ((x != y) && (AddA(x,y) == x))
#define LessOrEqualA(x,y)      (AddA(x,y) == y) 
#define LessA(x,y)             ((x != y) && (AddA(x,y) == y)) 
