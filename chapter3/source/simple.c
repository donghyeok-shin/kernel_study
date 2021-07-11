#include <stdio.h>
#include <stdlib.h>

int glob;

int main(){
    int local, *dynamic;
    dynamic = malloc(1383);

    printf("local = %p\n", &local);
    printf("dynamic = %p\n", dynamic);
    printf("global = %p\n", &glob);
    printf("main = %p\n", main);
    return 0;
}