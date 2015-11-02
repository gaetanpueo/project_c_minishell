#include <minishell.h>

static char		**ft_realloc_s(char **env, char *arg)
{
	char		**dup;
	int			i;
	int			k;

	i = 0;
	while (env[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		dup[i] = ft_strdup(env[i]);
	dup[i] = NULL;
	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
	env = (char **)malloc(sizeof(char *) * i);
	i = -1;
	k = 0;
	while (dup[++i])
		if (equal_key(dup[i], arg) == 0)
			env[k++] = ft_strdup(dup[i]);
	env[k] = NULL;
	return (env);
}

t_shell			*unset_env(t_shell *shell)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	shell->env = ft_realloc_s(shell->env, shell->args[1]);
	return (shell);
}