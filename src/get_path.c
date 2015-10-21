#include <minishell.h>

char		**get_path(t_lazy *shell)
{
	int		i;
	int		len;
	char	*cpy;

	i = -1;
	len = 0;
	cpy = NULL;
	while (shell->env[++i])
	{
		if (ft_strncmp(shell->env[i], "PATH", 3) == 0)
		{
			len = ft_strlen(shell->env[i]) - 4;
			cpy = ft_strsub(ft_strdup(shell->env[i]), 5, len);
			return (ft_strsplit(cpy, ':'));
		}
	}
	return (NULL);
}
