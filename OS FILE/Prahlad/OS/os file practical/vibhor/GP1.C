#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("\n Name- Gajendra Babu \n Sec- A \n Student Id- 2018337 \n\n");
    fork();
    int P_id = getpid(); // To get process id
    printf(" Use of fork function\n Process Id : %d\n", P_id);
    return 0;
}
