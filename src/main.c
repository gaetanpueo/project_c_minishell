#include <minishell.h>

int			main(int argc, char **argv, const char **environ)
{
	int		i;
	t_lazy	*shell;

	(void)ac;
	(void)av;
	i = 0;
	if ((shell = (t_lazy *)malloc(sizeof(t_lazy))))
	{
		shell->pid = 1;
		env_cpy(environ, &shell);
		shell->pwd = get_pwd();
		shell->expwd = NULL;
		while (shell->pid)
			shell = minishell(shell);
	}
	return (0);
}
