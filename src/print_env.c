#include <minishell.h>

void		print_env(t_lazy *shell)
{
	int		i;

	i = 0;
	while (shell->env[i])
		ft_putendl(shell->env[i++]);
}
