#include "../include/pipex.h"

static char *ft_get_cmd(char **path, char *cmd)
{
    char    *tmp;
    char    *ptr;
    int     i;

    i = 0;
    while(path[i])
    {
        tmp = ft_strjoin(path[i], "/");
        ptr = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(ptr, X_OK) == 0)
            return (ptr);
        free(ptr);
        i++;
    }
    return (NULL);
}

void    first_child(t_pipex pipex, char **av, char **env)
{
    dup2(pipex.infile, 0);
    dup2(pipex.pipe[1], 1);
    printf("%d\n", pipex.infile);
    pipex.command = ft_split(av[2], ' ');
    pipex.cmd = ft_get_cmd(pipex.cmd_path, pipex.command[0]);
    execve(pipex.cmd, pipex.command, env);

}

void    second_child(t_pipex pipex, char **av, char **env)
{
    dup2(pipex.outfile, 1);
    dup2(pipex.pipe[0], 0);
    pipex.command = ft_split(av[3], ' ');
    pipex.cmd = ft_get_cmd(pipex.cmd_path, pipex.command[0]);
    execve(pipex.cmd, pipex.command, env);

}