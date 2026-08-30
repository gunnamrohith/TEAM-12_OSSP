#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int a, b;
    char buffer[100];
    int n;

    a = open("source.txt", O_RDONLY);
    b = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    n = read(a, buffer, 100);
    write(b, buffer, n);

    close(a);
    close(b);

    printf("File copied successfully\n");

    return 0;
}
