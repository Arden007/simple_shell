#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * NAME
       execve - execute program

 * SYNOPSIS/SYNTAX
       #include <unistd.h>

       int execve(const char *pathname, char *const argv[],
                  char *const envp[]);

 * DESCRIPTION
       execve()  executes  the  program referred to by path of the file.  This causes the program that is currently being run by
       the calling process to be replaced with a new program, with newly initialized stack, heap, and  (initialized  and
       uninitialized) data segments.

       argv is an array of argument strings passed to the new program.  By convention, the first of these strings (i.e.,
       argv[0]) should contain the filename associated with the file being executed.  envp is an array of strings,  con‐
       ventionally  of the form key=value, which are passed as environment to the new program.  The argv and envp arrays
       must each include a null pointer at the end of the array.

      The argument vector and environment can be accessed by the called program's main function, when it is defined as:

           int main(int argc, char *argv[], char *envp[])

      execve()  does  not return on success, and the text, initialized data, uninitialized data (bss), and stack of the
       calling process(executable file) are overwritten according to the contents of the newly loaded program. This an issue
       when writting a shell program to overcome this I will be creating a child process and you the wait() system call in the
       parent process as the child process returns to the parent when it's terminated.

 * RETURN VALUE
        On success, execve() does not return, on error -1 is returned, and errno is set appropriately.
 *
 *
 *
 */
int main()
{
    pid_t pid;

    /* Argv is an array of argument strings, By convention, the first of these strings (i.e.,
       argv[0]) should contain the filename associated with the file being executed*/
    char *argv[] = {"/bin/ls", "-l", NULL};

    /* Creation of a child process*/
    pid = fork();

    /* Checking if child process failed (return value of fail -1)*/
    if (pid == -1)
    {
        return -1;
    }

    /* Checking if we in the child process(return value of success 0)*/
    /* With this we can execute the execve system call and continue with rest of the could
        as only the child process gets overwriiten.
    */
    if (pid == 0)
    {
        int val = execve(argv[0], argv, NULL);

        /* Checking if the execve system fail (return value fail -1)*/
        if (val == -1)
            perror("Error");
    }
    /* Otherwise we'll be in the Parent process*/
    else
    {
        wait(NULL);
        printf("Done with execve\n");
    }

    return 0;
}