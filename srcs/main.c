#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	create_pipes(&pipex, argc);
	get_path(&pipex, env);
	pipex.iter = 0;
	pipex.pipes[0][0] = open(argv[1], O_APPEND | O_RDONLY, 0777);
	pipex.pipes[argc - 2][1] = \
		open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	exc_dup(&pipex, argc);
	while (++pipex.iter < argc - 2)
	{
		exc_cmd(&pipex, env, argv[pipex.iter + 1], argc);
	}
	close(pipex.pipes[0][0]);
	close(pipex.pipes[argc - 2][1]);
	return (0);
}
