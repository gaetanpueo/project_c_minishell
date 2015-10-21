#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>

typedef struct		s_lazy
{
	char			**path;
	pid_t			pid;
	char			*pwd;
	char			*expwd;
	char			**env;
	char			*line;
	char			**args;
	int				flag;
	char			*absolute;
	char			**cmd;
}					t_lazy;

void				env_cpy(const char **environ, t_lazy **shell);
char				**get_path(t_lazy *shell);
t_lazy				*minishell(t_lazy *shell);
void				free_exit(t_lazy **shell);
t_lazy				*parse_line(t_lazy *shell, int i);
t_lazy				*exec_command(t_lazy *shell, int i);
void				print_env(t_lazy *shell);
t_lazy				*set_env(t_lazy *shell);
t_lazy				*unset_env(t_lazy *shell);
char				*get_pwd(void);
t_lazy				*cd(t_lazy *shell);
int					equal_key(char *s, char *new);

#endif
