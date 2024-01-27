
#include "../include/pipex.h"

void    error_msg(char *str)
{
    perror(str);
    exit(1);
}
int     print_msg(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write (2, &str[i], 1);
        i++;
    }
    return (1);
}