#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * NAME
       getline, getdelim - delimited/gets string input
 * SYNOPSIS/SYNTAX
       #include <stdio.h>

       ssize_t getline(char **lineptr(stores the address of the buffer being created) , size_t *n(the buffer that is created by the text will be store here) , FILE *stream(where we getting our text from));

       ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
 * DESCRIPTION
       getline()  reads  an  entire line from stream, storing the address of the buffer containing the text into *lineptr.  The
       buffer is null-terminated and includes the newline character, if one was found.

       If *lineptr is set to NULL and *n is set 0 before the call, then getline() will allocate a buffer for storing the line.  This  buffer  should
       be freed by the user program even if getline() failed.
       If the buffer is
       not large enough to hold the line, getline() resizes it with realloc(3), updating *lineptr and *n as necessary.. If the user creates a buffer and size is to small
       then under the hood getline will allocate enough memory to hold the buffer, to odo this just set buffer to NULL
 *
 */

int main()
{
    /* The size of the buffer*/
    size_t n = 10;

    /* Creation of the buffer and allocation of memory*/
    char *buf = malloc(sizeof(char) * n);

    /* Promote to the user*/
    printf("Enter name: ");

    /* the text to be stored in the buffer*/
    /* 1st arg is the address of the buffer, 2nd the size , 3rd the input we receiving from*/
    getline(&buf, &n, stdin);

    printf("Name: %sBuffer size is %ld\n", buf, n);

    /* Lets free the space we allocated to make sure there are no memory leaks*/
    free(buf);

    return 0;
}