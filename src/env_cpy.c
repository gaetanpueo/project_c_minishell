#include <minishell.h>

void		env_cpy(const char **environ, t_lazy **shell)
{
	int		i;

	i = 0;
	while (environ[i])
		i++;
	(*shell)->env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		(*shell)->env[i] = ft_strdup(environ[i]);
		i++;
	}
	(*shell)->env[i] = 0;
}
