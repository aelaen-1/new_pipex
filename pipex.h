#ifndef PIPEX_H
 #define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

char	**ft_split(char *s, char c);
void    exec(char *cmd, char **envp);
char	*ft_strjoin(char *s1, char const *s2);

#endif