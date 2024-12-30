#include "pipex.h"


void child_process(int *fd, char **av, char **envp)
{
    int fd_infile;

    fd_infile = open(av[1], O_RDONLY);
    if (fd_infile == -1)
    {
        write(2, "Error: File not found\n", 22);
        return;   
    }
    close(fd[0]);
    dup2(fd_infile, 0);
    dup2(fd[1], 1);
    exec(av[2], envp);
    close(fd[1]);
}

void parent_process(int *fd, char **av, char **envp)
{
    int fd_outfile;
    int status;

    waitpid(0, &status, 0);
    fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_outfile == -1)
    {
        write(2, "Error: File not found\n", 22);
        return;
    }
    close(fd[1]);
    dup2(fd[0], 0);
    dup2(fd_outfile, 1);
    exec(av[3], envp);
    close(fd[0]);
}

int main(int ac, char **av, char **envp)
{
    int fd[2];
    int pid;

    if (ac != 5)
        return(write(2, "Error: Wrong number of arguments\n", 34), 1);
    if (pipe(fd) == -1)
        return(write(2, "Error: Pipe failed\n", 19), 1);
    pid = fork();
    if (pid < 0)
        return (write(2, "Error: Fork failed\n", 19), 1);
    else if (pid == 0)
        child_process(fd, av, envp);
    else
        parent_process(fd, av, envp);
    return (0);
}