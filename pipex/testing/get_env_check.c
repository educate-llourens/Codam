#include "../pipex.h"

extern char **environ;

int	main(void)
{
	char	*env_directories = ft_get_env(environ);
	printf("%s", env_directories);

	return (0);
}