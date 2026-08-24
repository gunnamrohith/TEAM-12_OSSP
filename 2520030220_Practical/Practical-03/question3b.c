#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
pid_t pid;
printf("Before fork()\n");
printf("Current process PID : %d\n", getpid());
pid = fork();
 if (pid < 0)
    {
printf("Fork failed.\n");
 exit(1);
  }
else if (pid == 0){
printf("this is child procress\n");
printf("Status: Running\n");
printf("PID : %d\n", getpid());
printf("PPID    : %d\n", getppid());
printf("the child procress is completed");
exit(0);
}
else{
printf("Parent Process\n");
printf("State : Running\n");
printf("Parent PID : %d\n", getpid());
printf("Child PID  : %d\n", pid);
printf("Parent State : Waiting for Child\n");
wait(NULL);
printf("Child has terminated.\n");
printf("Parent State : Running\n");
printf("Parent process terminated.\n");
    }

    return 0;
}

