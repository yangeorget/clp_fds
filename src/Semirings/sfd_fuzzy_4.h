#define A_NAME        "Fuzzy 4"

#define AddA(x,y)     (math_max((x),(y)))  
#define MulA(x,y)     (math_min((x),(y)))  

#define A_SIZE        4    
#define A_SIZE_BITS   2     
#define A_WD_SZ_BITS  3     
#define A_MASK        0x0F  

#define A_FORMAT      "%x" 

#define GreaterOrEqualA(x,y)   ((x) >= (y))
#define GreaterA(x,y)          ((x) > (y)) 
#define LessOrEqualA(x,y)      ((x) <= (y))
#define LessA(x,y)             ((x) < (y))

