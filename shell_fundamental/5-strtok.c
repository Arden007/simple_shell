#include <stdio.h>
#include <string.h>
/**
 * NAME
       strtok, strtok_r - extract tokens from strings

 * SYNOPSIS
       #include <string.h>

       char *strtok(char *str(pointer to string you want to extract/seperate), const char *delim(delimetor it seperates 1 or more strings));

       char *strtok_r(char *str, const char *delim, char **saveptr);

 * DESCRIPTION
       The  strtok()  function breaks a string into a sequence of zero or more nonempty tokens. On the first call to strtok(),
       the string to be parsed should be specified in str.  In each subsequent(after the first call to strtok()) call that
       should parse the same string, str MUST BE NULL. The end of each token is found by scanning forward until either the next delimiter byte is found or until the
       terminating  null byte ('\0') is encountered. If a delimiter byte is found, it is overwritten with a null byte to terminate the
       current token, and strtok() saves a pointer to the following byte; that pointer will be used as the starting point  when
       searching for the next token.  In this case, strtok() returns a pointer to the start of the found token.

 * RETURN VALUE
       The strtok() and strtok_r() functions return a pointer to the next token, or NULL if there are no more tokens.
 *
 */

int main()
{
    char str[] = "Coding loves you";
    char *delim = " ";
    char *token;

    token = strtok(str, delim);

    while (token != NULL)
    {
        printf("%s", token);
        token = strtok(NULL, delim);
    }

    return 0;
}