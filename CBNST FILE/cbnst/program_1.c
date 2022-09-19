#include <stdio.h>
#include <math.h>

int main()
{
    float trueValue, approximateValue;

    printf("\nEnter True Value : ");
    scanf("%f", &trueValue);

    printf("Enter Approximate Value : ");
    scanf("%f", &approximateValue);

    float absoluteError, relativeError, percentageError;
    absoluteError = fabs(trueValue - approximateValue);
    relativeError = fabs(absoluteError / trueValue);
    percentageError = relativeError * 100;

    printf("\nAbsolute Error is: %f\n", absoluteError);
    printf("Relative Error is: %f\n", relativeError);
    printf("Percentage Error is:  %f\n\n ", percentageError);

    return 0;
}

// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>

// int main()
// {
//     float tval,aval;
//     printf("\nEnter the true value and approximate value: ");
//     scanf("%f %f",&tval,&aval);

//     float abs_err = fabs(tval - aval);
//     float rel_err = abs_err/tval;
//     float per_err = rel_err*100;

//     printf("\nAbsolute Error: %f",abs_err);
//     printf("\nRelative Error: %f",rel_err);
//     printf("\nPercentage Error: %f",per_err);

//     return 0;

// // }