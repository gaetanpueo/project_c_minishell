#include <minishell.h>

int		equal_key(char *s, char *new)
{
	int		i;
	char	*cpy;
	char	*cpyarg;

	i = 0;
	if (s)
		cpy = ft_strdup(s);
	if (new)
		cpyarg = ft_strdup(new);
	if (!new || !s)
		return (0);
	while (cpyarg[i] != '=' && cpyarg[i])
		i++;
	cpyarg[i] = '\0';
	i = 0;
	while (cpy[i] != '=')
		i++;
	cpy[i] = '\0';
	i = 0;
	while (cpy[i] == cpyarg[i] && cpy[i] && cpyarg[i])
		i++;
	if (!cpy[i] && !cpyarg[i])
		return (1);
	return (0);
}
