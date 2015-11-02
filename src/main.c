#include <minishell.h>

int			main(int argc, char **argv, const char **environ)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	if ((shell = (t_shell *)malloc(sizeof(t_shell))))
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
