#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int pipefd[2];
    pid_t producer, consumer;

   
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("Starting Producer-Consumer Communication...\n");

    
    producer = fork();

    if (producer < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (producer == 0)
    {
        
        close(pipefd[0]);

        dup2(pipefd[1], STDOUT_FILENO);

        close(pipefd[1]);

      
        execlp("ls", "ls", "-l", (char *)NULL);

        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    consumer = fork();

    if (consumer < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (consumer == 0)
    {
       
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);

        close(pipefd[0]);

 
        execlp("grep", "grep", ".c", (char *)NULL);

    
        perror("execlp grep");
        exit(EXIT_FAILURE);
    }


    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(producer, NULL, 0);
    waitpid(consumer, NULL, 0);

    printf("\nProducer-consumer communication completed.\n");

    return 0;
}