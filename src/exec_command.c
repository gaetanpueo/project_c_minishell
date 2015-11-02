#include <minishell.h>

static t_shell	*set_command(t_shell *shell)
{
	int		i;

	i = 0;
	if (shell->path != NULL)
	{
		shell->absolute = ft_strdup(shell->line);
		if (access(shell->line, F_OK) == 0)
			return (shell);
		while (shell->path[i])
		{
			shell->absolute = ft_strjoin(shell->path[i], "/");
			shell->absolute = ft_strjoin(shell->absolute,
											shell->line);
			if (access(shell->absolute, F_OK) == 0)
				return (shell);
			i++;
		}
		if (shell->absolute)
			free(shell->absolute);
		shell->absolute = NULL;
		ft_putendl(ft_strjoin(shell->line, ": command not found"));
	}
	else
		ft_putendl("Path inexistant. Utilisateur con.");
	return (shell);
}

static t_shell	*exec_path(t_shell *shell)
{
	shell->pid = fork();
	if (shell->pid == -1)
		return (shell);
	if (shell->pid == 0)
	{
		shell = set_command(shell);
		execve(shell->absolute, shell->args, shell->env);
	}
	else
		waitpid(shell->pid, 0, 0);
	return (shell);
}

t_shell			*exec_command(t_shell *shell, int i)
{
	shell->line = ft_strdup(shell->cmd[i]);
	if (ft_strcmp(ft_strlower(shell->line), "exit") == 0)
		free_exit(&shell);
	else if (ft_strcmp(ft_strlower(shell->line), "env") == 0)
		print_env(shell);
	else if (ft_strcmp(ft_strlower(shell->line), "setenv") == 0)
		shell = set_env(shell);
	else if (ft_strcmp(ft_strlower(shell->line), "unsetenv") == 0)
		shell = unset_env(shell);
	else if (ft_strcmp(ft_strlower(shell->line), "cd") == 0)
		shell = cd(shell);
	else
		shell = exec_path(shell);
	return (shell);
}
