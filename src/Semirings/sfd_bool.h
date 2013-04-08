#define A_NAME        "Bool"

#define AddA(x,y)     ((x)|(y))  
#define MulA(x,y)     ((x)&(y))  

#define A_SIZE        1    
#define A_SIZE_BITS   0    
#define A_WD_SZ_BITS  5     
#define A_MASK        0x01
  
#define A_FORMAT      "%i"  

#define GreaterOrEqualA(x,y)   (x) 
#define GreaterA(x,y)          (x & !y)
#define LessOrEqualA(x,y)      (y)
#define LessA(x,y)             (y & !x)


