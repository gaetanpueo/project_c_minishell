#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>

typedef struct		s_shell
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
}					t_shell;

t_shell				*minishell(t_shell *shell);
t_shell				*parse_line(t_shell *shell, int i);
t_shell				*exec_command(t_shell *shell, int i);
t_shell				*set_env(t_shell *shell);
t_shell				*unset_env(t_shell *shell);
t_shell				*cd(t_shell *shell);
void				env_cpy(const char **environ, t_shell **shell);
void				free_exit(t_shell **shell);
void				print_env(t_shell *shell);
char				**get_path(t_shell *shell);
char				*get_pwd(void);
int					equal_key(char *s, char *new);

#endif
