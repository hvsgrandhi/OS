#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Reversed Array:\n");
    for (int i = argc - 1; i > 0; i--)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}


//to run:
//gcc 2b_parent.c -o p
//gcc 2b_child.c -o p1
// ./p ./p1