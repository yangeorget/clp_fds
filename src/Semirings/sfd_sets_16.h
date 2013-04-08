#define A_NAME        "Sets 16"

#define AddA(x,y)     ((x)|(y))
#define MulA(x,y)     ((x)&(y))

#define A_SIZE        16
#define A_SIZE_BITS   4
#define A_WD_SZ_BITS  1  
#define A_MASK        ((VecWord) 0xFFFF) 

#define A_FORMAT      "%4x" 

#define GreaterOrEqualA(x,y)   (AddA(x,y) == x) 
#define GreaterA(x,y)          ((x != y) && (AddA(x,y) == x))  
#define LessOrEqualA(x,y)      (AddA(x,y) == y)  
#define LessA(x,y)             ((x != y) && (AddA(x,y) == y))  
