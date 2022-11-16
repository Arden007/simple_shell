#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid_t ppid;
    /*written before fork was called*/

    /*called frok*/
    pid = fork();

    if (pid == -1)
    {
        perror("fork unsucessful\n");
        return 1;
    }

    /**
     * @Enter man fork in terminal
     * RETURN VALUE
           On  success,  the PID of the child process is returned in the parent, and 0 is returned in the child.  On failure, -1 is
           returned in the parent, no child process is created, and errno is set appropriately.
     */
    if (pid == 0)
    {
        sleep(40);
        printf("I am the child process\n");
    }
    else
    {
        ppid = getppid();
        printf("I am the parent process: %u\n", ppid);
    }

    /*ps command - report a snapshot of the current process(Process Table)*/

    /**
     * In Terminal type the command ps -eaf | grep -e "fork" (to filter out the fork process)
     *
     */

    return 0;

    /*
     * @How our code runs
     *
     * Parent executes and terminates before child executes
     * Child become an orphan because it's parent died while it was still alive(executing)
     * The init process(mother of all processes(when you start your computer)) adopts the child
     *      and becomes it's parent until it terminates(die)
     * This adoption changes the ppid of the child to 1(the ppid of the int process) during it's execution
     * The inti process then removes the child from the proccess table after it's execution.
     * This explian why you can't find the child process in the proccess table with the "ps -eaf" command
     *
     *
     * @Orphan Process - This is a running process whose parent has fini or terminated
     *
     ** Init process(The first process)
            Init is the parent of all processes, executed by the kernel during the booting of the computer
            It has a pid of 1 (command ps -eaf)

     ** Process Table (ps -eaf)
     *      This is a data structure in the RAM of a computer that holds information about the processes
     *      currently being handled by the Operating System
     *
     ** Process Entry
     *      This is created when the process is created by the fork() system call
     *
     */
}