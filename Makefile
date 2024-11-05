NAME = minishell

SRC_DIR = src
PIPEX_DIR = $(SRC_DIR)/Pipex
OBJ_DIR = objs

SRC_FILES =	main.c					\
			start.c					\
			utils.c					\
			line.c					\
			cd.c					\
			utils_two.c				\
			cd_two.c				\
			echo.c					\
			utils_three.c			\
			utils_four.c			\
			utils_five.c			\
			line_two.c				\
			line_three.c			\
			spaces.c				\
			command.c				\
			operator.c				\
			operator_two.c			\
			quotes_two.c			\
			quotes.c				\
			parse_pipes.c			\
			pipe_functions.c		\
			pipe_functions_two.c	\
			signal.c 				\
			signal_two.c 			\
			env.c 					\
			env_two.c 				\
			env_three.c 			\
			env_four.c 				\


PIPEX_FILES =	pipex_bonus.c		\
				pipex_utils_bonus.c	\
				checker_bonus.c		\
				checker.c			\
				pipex_utils.c		\
				here_doc.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
      $(addprefix $(PIPEX_DIR)/, $(PIPEX_FILES))

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I includes
DEBUG = -g -fsanitize=address
RM = rm -rf

LIBFT_DIR = libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) -lft
READLINE = -lreadline

RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) --silent
	@echo "$(GREEN)Compiling the MINISHELL program.$(CLEAR)"
	$(CC) $(FLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "$(BLUE)Removing compiled files.$(CLEAR)"
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --silent
	@echo "$(BLUE)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@echo "$(BLUE)Removing exec. files.$(CLEAR)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent
	@echo "$(BLUE)Object files and binary removed correctly\n$(CLEAR)"

debug: $(OBJS)
	@make -C $(LIBFT_DIR) --silent
	@echo "$(PINK)Compiling for debugging the MINISHELL program.$(CLEAR)"
	$(CC) $(DEBUG) $(INCLUDE) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)
	@echo "$(PINK)[OK]\n$(CLEAR)$(PINK)Success!$(CLEAR)\n"

re: fclean all

.PHONY: all clean fclean debug re
