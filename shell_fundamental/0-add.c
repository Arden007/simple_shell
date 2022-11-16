#include <stdio.h>
#include <unistd.h>

/**
 * @brief : Every time this program is executed we should be printing out a unique Process Id to the console.
 *
 * @return : The unique Process Id
 */

int main()
{
    int a = 3;
    int b = 5;

    int sum = a + b;
    printf("Sum is: %d\n", sum);

    /* Pid_t : Is a signed integer data type that is capable of representing a process ID (Unique ID) */
    pid_t pid;

    /* Getpid : Returns the process ID, lets store it in variable pid we create above */
    pid = getpid();
    printf("Process Id is: %u\n", pid);

    /* Pid_t : Is a signed integer data type that is capable of representing a parent process ID (Constant ID) */
    pid_t ppid;

    /* Getppid : Returns the parent process ID, lets store it in variable ppid we create above */
    ppid = getppid();
    printf("Parent Process Id is: %u\n", ppid);

    return 0;
}