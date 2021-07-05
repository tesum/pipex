#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		pipes[100][2];
	int		iter;
	char	**path;
	char	*cmd;
}			t_pipex;

void	create_pipes(t_pipex *pipex, int count);
void	get_path(t_pipex *pipex, char **env);
void	exc_dup(t_pipex *pipex, int argc);
void	exc_cmd(t_pipex *pipex, char **env, char *cmd, int argc);

// utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif