#include <stdio.h>
int main()
{
 int n;
 printf("Enter an year:");
 scanf("%d",&n);
 int b =  n%4==0;
 switch(b){
        case 1:
                if(n%100==0)
                {
                  if(n%400==0)
                  {
                  printf("It is a leap year");
                  }
                  else
                  {
                    printf("It is not a leap year");
                  }
                }else{
                  printf("its a leap year");
                }
                break;
        case 0:
                
                printf("It is not a leap year");

                break;
         default:
                  printf("It is not a leap year");
}

return 0;
}