#include "pipex.h"

static int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void    exec(char *cmd, char **envp)
{
    char **args;
    int i; 

    i = 0;
    while (envp[i])
    {
        if (ft_strcmp(envp[i], "PATH") == 0)
            break;
        i++;
        if (envp[i] == NULL)
        {
            write(2, "Error: PATH not found\n", 26);
            exit(1);
        }
    }
    char **path_env = ft_split(envp[i], ':');
    i = 0;
    while (path_env[i])
    {
        path_env[i] = ft_strjoin(path_env[i], "/");
        path_env[i] = ft_strjoin(path_env[i], cmd);
        if (access(path_env[i], F_OK) == 0)
            break;
        i++;
    }
    args = ft_split(cmd, ' ');
    if (execve(args[0], args, envp) == -1)
    {
        write(2, "Error: Command not found\n", 26);
        exit(1);
    }
}