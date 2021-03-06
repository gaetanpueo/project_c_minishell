LIB_NAME	=	project_c_libft
LIB_DIR		=	../$(LIB_NAME)/
LIB_BDIR	=	$(LIB_DIR)/bin/
LIB_HDIR	=	$(LIB_DIR)/inc/

NAME		=	minishell
BDIR		=	bin/
SDIR		=	src/
ODIR		=	obj/
HDIR		=	inc/

SRCS		=	cd.c \
				env_cpy.c \
				equal_key.c \
				exec_command.c \
				free_exit.c \
				get_path.c \
				get_pwd.c \
				main.c \
				minishell.c \
				parse_line.c \
				print_env.c \
				set_env.c \
				unset_env.c
_OBJS		=	$(SRCS:.c=.o)
OBJS		=	$(patsubst %,$(ODIR)%,$(_OBJS))

CC			=	gcc
FLAGS 		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-I $(HDIR) -I $(LIB_HDIR)

all: complib scmsg $(NAME)
	@echo "\n--------------------------------------------------------------------------------"

scmsg:
	@echo "------------------------- Start compilation minishell --------------------------\n"

scemsg:
	@echo "\033[34;1m>> \033[0mCompilation files ..."

$(NAME): mkdir scemsg $(OBJS)
	@$(CC) -o $(BDIR)$(NAME) $(OBJS) -L $(LIB_BDIR) -lft
	@echo "\n\033[73G\033[37;1m[\033[34mDone !\033[37m]\033[0m"

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $(FLAGS) $(LDFLAGS) -o $@ -c $<
	@echo "|\c)"

mkdir:
	@if [ -d $(BDIR) ]; then \
		echo "\033[34;1m>> \033[0mBinaries directory already exist ...\033[73G"; \
	else \
		echo "\033[34;1m>> \033[0mCreating binaries directory ...\033[73G\c"; \
		mkdir $(BDIR); \
		echo "\033[37;1m[\033[34mDone !\033[37m]\033[0m"; \
	fi
	@if [ -d $(ODIR) ]; then \
		echo "\033[34;1m>> \033[0mObjects directory already exist ...\033[73G"; \
	else \
		echo "\033[34;1m>> \033[0mCreating objects directory ...\033[73G\c"; \
		mkdir $(ODIR); \
		echo "\033[37;1m[\033[34mDone !\033[37m]\033[0m"; \
	fi

complib:
	@make -C $(LIB_DIR)

cleanobj:
	@echo "--------------------------- Deleting files minishell ---------------------------\n"
	@echo "\033[34;1m>> \033[0mRemoving object files ...\033[73G\c"
	@rm -f $(OBJS)
	@echo "\033[37;1m[\033[34mDone !\033[37m]\033[0m"
	@echo "\033[34;1m>> \033[0mRemoving objects directory ...\033[73G\c"
	@rm -rf $(ODIR)
	@echo "\033[37;1m[\033[34mDone !\033[37m]\033[0m"

clean: cleanobj
	@echo "\n--------------------------------------------------------------------------------"
	@make -C $(LIB_DIR) clean

fclean: cleanobj
	@echo "\033[34;1m>> \033[0mRemoving : $(NAME) ...\033[73G\c"
	@rm -f $(BDIR)$(NAME)
	@echo "\033[37;1m[\033[34mDone !\033[37m]\033[0m"
	@echo "\033[34;1m>> \033[0mRemoving binaries directory ...\033[73G\c"
	@rm -rf $(BDIR)
	@echo "\033[37;1m[\033[34mDone !\033[37m]\033[0m"
	@echo "\n--------------------------------------------------------------------------------"
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
