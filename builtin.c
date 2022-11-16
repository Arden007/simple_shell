#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
    int check;

    if (info->argv[1])
    {
        check = _erratoi(info->argv[1]);
        if (check == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }
        info->err_num = _erratoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/**
 * _cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _cd(info_t *info)
{
    char *p, *directory, buffer[1024];
    int chdir_ret;

    p = getcwd(buffer, 1024);
    if (!p)
        _puts("Error: Failed to fetch current working directory\n");
    if (!info->argv[1])
    {
        directory = _getenv(info, "HOME=");
        if (!directory)
        {
            chdir_ret = chdir((directory = _getenv(info, "PWD=")) ? directory : "/");
        }
        else
        {
            chdir_ret = chdir(directory);
        }
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(p);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((directory = _getenv(info, "OLDPWD=")) ? directory : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_error(info, "can't change directory ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _help(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("work in progress \n");
    if (0)
    {
        _puts(*arg_array);
    }
    return (0);
}
