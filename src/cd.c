#include <minishell.h>

static t_lazy	*gil_scott_dilemma(t_lazy *shell)
{
	char	*home;
	int		i;
	char	*path;

	home = NULL;
	path = NULL;
	i = 0;
	while (shell->env[i] && ft_strncmp(shell->env[i], "HOME", 3) != 0)
		i++;
	home = ft_strsub(shell->env[i], 5, ft_strlen(shell->env[i]) - 4);
	path = ft_strsub(shell->args[1], 1, ft_strlen(shell->args[1]));
	home = ft_strjoin(home, path);
	if (access(home, F_OK) == 0 && access(home, R_OK) == 0)
		chdir(home);
	else
		ft_putendl("Cannot access directory.");
	return (shell);
}

static t_lazy	*home_sweet_home(t_lazy *shell)
{
	char	*home;
	int		i;

	home = NULL;
	i = 0;
	while (shell->env[i] && ft_strncmp(shell->env[i], "HOME", 3) != 0)
		i++;
	home = ft_strsub(shell->env[i], 5, ft_strlen(shell->env[i]) - 4);
	if (access(home, F_OK) == 0 && access(home, R_OK) == 0)
		chdir(home);
	else
		ft_putendl("Cannot access directory.");
	return (shell);
}

static t_lazy	*absolute(t_lazy *shell)
{
	if (access(shell->args[1], F_OK) == 0 && access(shell->args[1], R_OK) == 0)
		chdir(shell->args[1]);
	else
		ft_putendl("Cannot access directory.");
	return (shell);
}

static t_lazy	*go_back(t_lazy *shell)
{
	if (access(shell->expwd, F_OK) == 0 && access(shell->expwd, R_OK) == 0)
		chdir(shell->expwd);
	else
		ft_putendl("Cannot access directory.");
	return (shell);
}

t_lazy			*cd(t_lazy *shell)
{
	char	*path;

	path = NULL;
	if (!shell->args[1])
		shell = home_sweet_home(shell);
	else if (shell->args[1][0] == '-' && !shell->args[1][1])
		shell = go_back(shell);
	else if (shell->args[1][0] == '/')
		shell = absolute(shell);
	else if (shell->args[1][0] == '~')
		shell = gil_scott_dilemma(shell);
	else
	{
		path = ft_strjoin(shell->pwd, "/");
		path = ft_strjoin(path, shell->args[1]);
		if (access(path, F_OK) == 0 && access(path, R_OK) == 0)
			chdir(path);
		else
			ft_putendl("Cannot access directory.");
	}
	shell->expwd = ft_strdup(shell->pwd);
	shell->pwd = get_pwd();
	return (shell);
}
