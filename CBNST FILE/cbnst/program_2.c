#include <stdio.h>
#include <math.h>

float fun(float x)
{
    return (x * x * x - 5 * x + 1);
    // return (x - cos(x));
}

int main()
{
    float x, b;
    float e;

    // printf("(x*x*x - 5*x + 1)\n");
    // printf("(x - cos(x))\n");
    printf("\nEnter the first value: ");
    scanf("%f", &x);
    printf("Enter the second value: ");
    scanf("%f", &b);

    printf("Enter the allowed error: ");
    scanf("%f", &e);

    if (fun(x) * fun(b) < 0)
    {
        printf("\nRoots are %f and %f \n", x, b);
    }

    else
    {
        printf("\nWrong answer, try again \n");
    }

    float root;
    int count = 0;

    do
    {
        ++count;
        root = (x + b) / 2;
        if (fun(x) * fun(root) < 0)
        {
            b = root;
        }
        else
        {
            x = root;
        }

        printf("Iteration no %d:  root value is : %f at x = %f and b = %f\n", count, root, x, b);
    } while (fabs(fun(root)) > e);
    printf("\n");
    return 0;
}

// #include<stdio.h>
// #include<math.h>
// #define f(x) (x*x*x)-(5*x)+1
// int main()
// {
//     float x0,x1,x2,f0,f1,f2,e;
//     int i=0;
//     printf("Enter the value of x0 : ");
//     scanf("%f",&x0);
//     printf("Enter the value of x1 : ");
//     scanf("%f",&x1);
//     printf("Enter the allowed error : ");
//     scanf("%f",&e);
//     if(f(x0)*f(x1)<0)
//     {
//         printf("Roots found\n");
//     }
//     else
//     {
//         printf("Wrong interval\n");
//         return 0;
//     }
//     do
//     {
//         f0=f(x0);
//         f1=f(x1);
//         x2=(x0+x1)/2;
//         f2=f(x2);
//         if(f0*f2<0)
//         {
//             x1=x2;
//         }
//         else
//         {
//             x0=x2;
//         }
//         i++;
//         printf("No of iteration = %d ",i);
//         printf("and Root = %f\n",x2);
//     }while(fabs(f2)>e);
//     printf("\nFinal root after %d iteration = %f\n",i,x2);
//     return 0;
// }