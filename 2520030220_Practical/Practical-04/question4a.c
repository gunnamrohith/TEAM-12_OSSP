#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pids[3];
    int status;

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();

        if (pids[i] < 0) {
            perror("fork failed");
            exit(1);
        } else if (pids[i] == 0) {
            printf("Child %d (PID: %d) sleeping for %d seconds\n", i + 1, getpid(), (3 - i) * 2);
            sleep((3 - i) * 2);
            printf("Child %d (PID: %d) exiting\n", i + 1, getpid());
            exit(i + 1);
        }
    }

    printf("Parent waiting specifically for Child 2 (PID: %d) using waitpid()...\n", pids[1]);
    waitpid(pids[1], &status, 0);
    if (WIFEXITED(status)) {
        printf("Reaped Child 2 (PID: %d) with exit code %d\n", pids[1], WEXITSTATUS(status));
    }

    printf("Parent reaping remaining children using wait()...\n");
    pid_t reaped_pid;
    while ((reaped_pid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("Reaped Child (PID: %d) with exit code %d\n", reaped_pid, WEXITSTATUS(status));
        }
    }

    return 0;
}