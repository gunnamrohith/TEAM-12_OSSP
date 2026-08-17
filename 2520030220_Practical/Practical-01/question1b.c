#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("CPU\n");
    system("lscpu");

    printf("Memory\n");
    system("free -h");

    printf(" Storage \n");
    system("lsblk");

    printf(" Process\n");
    system("ps aux");

    printf("System Information \n");
    system("uname -a");

    printf("I/O and Process Activity \n");
    system("top -b -n 1");

    return 0;
}
