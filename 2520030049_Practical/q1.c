#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char cmd[100];

    printf("Enter Linux command: ");
    scanf("%s", cmd);

    int pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        execlp(cmd, cmd, NULL);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child completed\n");
    }

    return 0;
}
