#define A_NAME        "Sets 32"

#define AddA(x,y)       ((x)|(y))
#define MulA(x,y)       ((x)&(y))

#define A_SIZE        32
#define A_SIZE_BITS   5
#define A_WD_SZ_BITS  0  
#define A_MASK        ((VecWord) 0xFFFFFFFF) 

#define A_FORMAT      "%8x" 

#define GreaterOrEqualA(x,y)   (AddA(x,y) == x) 
#define GreaterA(x,y)          ((x != y) && (AddA(x,y) == x))   
#define LessOrEqualA(x,y)      (AddA(x,y) == y)  
#define LessA(x,y)             ((x != y) && (AddA(x,y) == y))  
