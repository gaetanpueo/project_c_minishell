#include <minishell.h>

t_shell		*parse_line(t_shell *shell, int i)
{
	int		j;

	j = 0;
	shell->args = ft_strsplit(shell->cmd[i], ' ');
	while (!ft_isspace(shell->cmd[i][j]) && shell->cmd[i][j])
		j++;
	shell->cmd[i][j] = '\0';
	return (shell);
}
