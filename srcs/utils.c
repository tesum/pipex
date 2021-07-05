#include "../pipex.h"

void	create_pipes(t_pipex *pipex, int count)
{
	int	i;

	i = 0;
	while (i < count + 1)
	{
		pipe(pipex->pipes[i]);
		i++;
	}
}

void	get_path(t_pipex *pipex, char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if ((ft_strncmp(env[i], "PATH=", 5)) == 0)
		{
			pipex->path = ft_split(env[i] + 5, ':');
			return ;
		}
		i++;
	}
}

void	exc_dup(t_pipex *pipex, int argc)
{
	if (pipex->iter == 0)
	{
		dup2(pipex->pipes[0][0], 1);
	}
	else if (pipex->iter < argc - 2)
	{
		if (pipex->iter != 1)
			close(pipex->pipes[pipex->iter - 1][1]);
		dup2(pipex->pipes[pipex->iter - 1][0], 0);
		close(pipex->pipes[pipex->iter][0]);
		dup2(pipex->pipes[pipex->iter][1], 1);
	}
	else
	{
		close(pipex->pipes[pipex->iter - 1][1]);
		dup2(pipex->pipes[pipex->iter - 1][0], 0);
		close(pipex->pipes[pipex->iter - 1][0]);
	}
}

void	check_cmd(t_pipex *pipex, char *cmd)
{
	int		i;
	int		file;
	char	*path_cmd;

	i = 0;
	while (pipex->path[i])
	{
		path_cmd = ft_strjoin(pipex->path[i], "/");
		pipex->cmd = ft_strjoin(path_cmd, cmd);
		file = open(pipex->cmd, O_RDONLY);
		if (file != -1)
			return ;
		i++;
	}
	if (file == -1)
	{
		perror("Invalid command\n");
		exit (1);
	}
}

void	exc_cmd(t_pipex *pipex, char **env, char *cmd, int argc)
{
	pid_t	pid;
	int		exe;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	check_cmd(pipex, split_cmd[0]);
	pid = fork();
	if (pid != 0)
	{
		waitpid(-1, 0, 0);
		close(pipex->pipes[pipex->iter][1]);
	}
	else
	{
		exc_dup(pipex, argc);
		if (pipex->iter == argc - 3)
			dup2(pipex->pipes[argc - 2][1], 1);
		exe = execve(pipex->cmd, split_cmd, env);
		if (exe == -1)
			perror("Error execute command\n");
		exit (1);
	}
}
