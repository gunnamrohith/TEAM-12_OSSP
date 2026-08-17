#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
char command[10];
int pid;

printf("Enter a  command: ");
scanf("%s", command);
pid = fork();
if (pid < 0)
    {
        printf("Child process creation failed.\n");
    }
    else if (pid == 0)
    {
printf(" Child Procress\n");
printf("Child PID : %d\n", getpid());
printf("Parent PID: %d\n", getppid());
execlp(command, command, NULL);
        printf("Invalid command.\n");
        exit(1);
    }
    else
    {
printf(" Parent Process\n");
printf("Parent PID is: %d\n", getpid());
printf("Child PID is : %d\n", pid);
 wait(NULL);
        printf("Child process completed.\n");
        printf("Parent process completed.\n");
        exit(0);
    }
    return 0;
}
