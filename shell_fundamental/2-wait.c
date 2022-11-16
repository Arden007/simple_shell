#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * @Wait() System Call(man wait) - wait for the process to change states, prevents zombie state
 *
 ** Orphan Process - Parent terminates before child process
 *
 ** Zombie Process - Child terminates before parent process
 */

int main(void)
{
    /* Type declaration*/
    pid_t pid;
    pid_t ppid;

    /*child process is created*/
    pid = fork();

    /* if fork fails */
    if (pid == -1)
    {
        perror("fork unsucessful\n");
        return 1;
    }

    /* in child process */
    if (pid == 0)
    {
        printf("I am the child process\n");
    }
    else
    {
        /* synopsis pid_t wait(int *status); - it normally points to a status*/
        /*we not intersted status why we using NULL*/
        wait(NULL);
        // sleep(3);
        printf("I am the parent process: %u\n", ppid);
    }

    return 0;

    /**
     * @Wait Description- A state change is considered to be: the  child  terminated;  the
       child was stopped by a signal; or the child was resumed by a signal.  In the case of a terminated child, perform‐
       ing a wait allows the system to release the resources associated with the child; if a wait is not performed, then
       the terminated child remains in a "zombie" state
     *
     */
}