#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#define EPS 0.00000005
#define F(x) (x) * log10(x) - 1.2
void Bisect();
int count = 1, n;
float root = 1;
void main()
{
    clrscr();
    printf("\n Solution by BISECTION method \n");
    printf("\n Equation is ");
    printf("\n\t\t\t x*log(x) - 1.2 = 0\n\n");
    printf("Enter the number of iterations:");
    scanf("%d", &n);
    Bisect();
    getch();
}
void Bisect()
{
    float x0, x1, x2;
    float f0, f1, f2;
    int i = 0;
    for (x2 = 1;; x2++)
    {
        f2 = F(x2);
        if (f2 > 0)
        {
            break;
        }
    }
    for (x1 = x2 - 1;; x2--)
    {
        f1 = F(x1);
        if (f1 < 0)
        {
            break;
        }
    }
    printf("\t\t-----------------------------------------");
    {
        f2 = F(x2);
        if (f2 > 0)
        {
            break;
        }
    }
    for (x1 = x2 - 1;; x2--)
    {
        f1 = F(x1);
        if (f1 < 0)
        {
            break;
        }
    }
    printf("\t\t-----------------------------------------");
    printf("\n\t\t----------------------------------------");
    printf("\n\t\t\t Root = %7.4f", x0);
    printf("\n\t\t\t Iterations = %d\n", count - 1);
    printf("\t\t------------------------------------------");
    getch();
}