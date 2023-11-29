#include <stdio.h>
#include <unistd.h>

int main(){

    printf("Page size is %ld bytes \n", sysconf(_SC_PAGESIZE));

    return 0;
}