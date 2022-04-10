#include<stdio.h>
#define CLEARBIT(MASK,BIT) ((MASK)  &= (~(1 << (BIT))))
#define CHANGEBIT(MASK,BIT) ((MASK) ^= (1 << (BIT)))
#define SETBIT(MASK,BIT) ((MASK) |= (1 << (BIT)))
#define CHECKBIT(MASK,BIT) (!!((MASK) & (1 << (BIT)))) 
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MAX3(A,B,C) (MAX(MAX((A),(B)),(C))
#define MIN(A,B) ((A)>(B)?(A):(B))
#define MIN3(A,B,C) (MIN(MIN((A),(B)),(C))
#define SWAPVARS(A,B,TYPE) (TYPE TEMP = (A); (A)=(B);(B)=TEMP;)


int main()
{
    int mask = 0x00;
    int bit = 1;
  

    SETBIT(mask,bit);
    printf("%d \n",mask);

    CLEARBIT(mask,bit);
    printf("%d \n",mask);

     if (CHECKBIT(mask,bit) == 0){
        printf("0\n");
    } else {
        printf("1\n");
    }

    CHANGEBIT(mask,bit);
    printf("%d \n",mask);

    if (CHECKBIT(mask,bit)== 0){
        printf("0");
    } else {
        printf("1");
    }
   
return 0;