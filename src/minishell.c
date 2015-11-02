#include <minishell.h>

static void	ignore_signal(int num)
{
	(void)num;
}

t_shell		*minishell(t_shell *shell)
{
	int		i;

	i = 0;
	signal(SIGINT, ignore_signal);
	ft_putstr("\033[34m");
	ft_putstr(shell->pwd);
	ft_putstr("\033[36m)>\033[0m ");
	shell->path = get_path(shell);
	if (get_next_line(0, &(shell)->line) > 0)
	{
		shell->line = ft_epur_str(shell->line);
		shell->cmd = ft_strsplit(shell->line, ';');
		while (shell->cmd[i])
		{
			shell->cmd[i] = ft_epur_str(shell->cmd[i]);
			shell = parse_line(shell, i);
			shell = exec_command(shell, i);
			i++;
		}
	}
	else
		free_exit(&shell);
	return (shell);
}
