#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    float tval,aval;
    printf("\nEnter the true value and approximate value: ");
    scanf("%f %f",&tval,&aval);

    float abs_err = fabs(tval - aval);
    float rel_err = abs_err/tval;
    float per_err = rel_err*100;

    printf("\nAbsolute Error: %f",abs_err);
    printf("\nRelative Error: %f",rel_err);
    printf("\nPercentage Error: %f",per_err);

    return 0;
    
}
