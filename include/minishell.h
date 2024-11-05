/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:16:37 by gdel-val          #+#    #+#             */
/*   Updated: 2024/10/21 21:16:42 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h> 
#include <termios.h>

# define READ 0
# define WRITE 1

# define IN 0
# define OUT 1

# define FILE "bash: no such file or directory: "
# define COMMAND "bash: command not found: "
# define ARGUMENTS "Error: bad number of arguments"
# define CD "Error: No such file or directory"
# define CHILD "child error"
# define PIPE "pipe error"
# define MALLOC "memory error"
# define FORK "fork error"
# define DUP "dup error"
# define WAIT "waitpid error"
# define ENV "env error"
# define TOKEN "bash: syntax error near unexpected token"
# define ENVERROR "Error initializing environment"

# define SIGINT_HD 1
# define SIGINT_CHILD 2
# define SIGINT_FATHER 3
# define SIGQUIT_CHILD 4

extern volatile int g_signal_status;

typedef struct s_arguments
{
	int		in_fd;
	char	*command_one;
	char	*command_two;
	char	**split_one;
	char	**split_two;
	int		out_fd;
}				t_arguments;

typedef struct s_arguments_bonus
{
	int		in_fd;
	char	**commands;
	char	***splits;
	int		out_fd;
	int		here_doc;
	char	**argv;
}				t_arguments_bonus;

typedef struct s_word_info 
{
	int start;
	int length;
}			t_word_info;

typedef struct s_env {
	char *key;
	char *value;
}			t_env;

typedef struct s_env_list {
	t_env *content;
	struct s_env_list *next;
}			t_env_list;

/*------SIGNALS.C------*/
void	ft_sigint_heredoc(int signal);
void	ft_sigint_child(int signal);
void	ft_sigint(int signal);
void	ft_sigquit(int signal);
void	signal_handler(void (*sigint_func)(int), void (*sigquit_func)(int));
void	write_signals(bool write_signal);
/*--------------------*/

/*------START.C------*/
char	*ft_get_env(char *get);
void	print_minishell(void);
char	*current_directory(void);
char	*first_line(void);
/*-------------------*/


/*------UTILS.C------*/
/*BORRARBORRARBORRARBORRARBORRAR*/
void	print_matrix(char **matrix);
/*BORRARBORRARBORRARBORRARBORRAR*/
void	ft_error(char *str, char *file);
char	*ft_threejoin(char const *s1, char const *s2, char const *s3);
char	*ft_strstrend(const char *haystack, const char *needle);
char	*ft_replace(const char *haystack, const char *needle, const char rplc);
char	*replace_pwd(void);
/*-------------------*/

/*------UTILS_TWO.C------*/
char	**ft_free(char **mat);
int		ft_fullcmp(const char *s1, const char *s2);
char	*ft_nulljoin(char *s1, char *s2);
size_t	dollar_size(char **mat, char *src, char **matqoute);
char	*copy_character(char *src, char c);
/*-----------------------*/

/*------LINE.C------*/
int		size_char(char *src, char c);
char	*delete_character(char *src, char c);
char	*clean_line(char *line);
char	**mini_change_mat(char **mat, int i, char **src);
/*------------------*/

/*-------CD.C-------*/
void	change_prev(void);
int		change_next(char *mat, char *cd, char *current);
void	full_directory(char *cd);
void	change_cd(char **command);
/*------------------*/

/*-------CD_TWO.C-------*/
char	*current_cd(void);
char	*previous_directory(void);
char	*next_directory(char *cd);
/*----------------------*/

/*-------ECHO.C-------*/
int		n_control(char *src);
void	ft_echo(char **mat);
/*--------------------*/

/*------UTILS_THREE.C------*/
size_t	ft_matlen(char **mat);
char	*dollar_digit(char *str);
char	*dollar_env(char *str);
void	concat_env(char **mat, char *change, size_t j, char **matqoute);
char	*change_dollar(char **mat, char *src, char **matqoute);
/*-------------------------*/

/*------UTILS_FOUR.c------*/
void	ft_pwd(void);
char	*search_op(char *src);
void	frees(char *s1, char *s2);
char	*shell_strnstr(char *stack, char *needle, size_t len, char *qte);
char	**split_pointer(char *src);
/*-------------------------*/

/*------UTILS_FIVE.C------*/
void	mini_qte_two(char *str, char *lit, int clsd, int clss);
char	*quote_line_two(char *str);
char	**qout_mat(char *src);
char	*mini_env_dollar(char *src);
char	*env_dollar(char *strg);
/*------------------------*/

/*-------LINE_TWO.C-------*/
char	**change_mat(char **mat);
char	**prepare_split(char *str);
char	**quote_split(char *str, char **qte_split);
char	**ft_quotesplit(char *str);
char	**quote_split_first(char *src);
/*----------------------*/

/*-------LINE_THREE.C-------*/
char	*mat_to_line(char **mat);
char	*dollar_line(char	*src);
char	**line_split(char *line);
/*--------------------------*/

/*-------SPACES.C-------*/
void	handle_quotes(char **input, char **temp, int *doubl, int *single);
void	handle_operators(char **ipt, char **temp);
char	*add_spaces(char *input);
/*----------------------*/

/*-------COMMAND.C-------*/
char	*check_first(char **env, char *arg);
void	ft_command(char	**mat, char **env);
/*-----------------------*/

/*-------OPERATORS.C-------*/
char	**clean_in(char **commands);
char	**clean_out(char **commands);
void	exec_opin(char **commands, char **env, int stdin_copy);
void	ft_stdin(char **commands, char **env);
void	exec_opout(char **commands, char **env, int stdout_copy);
void	ft_operator(char **commands, char *here, char **env);
/*-----------------------*/

/*-------OPERATORS_TWO.C-------*/
void	ft_stdout(char **commands, char **env);
void	exec_stdinout(char **commands, char **env, int stdin, int stdout);
void	mini_in(char *commands, int stdin_copy);
void	mini_out(char *commands, int stdout_copy);
/*-----------------------*/

/*-------OPERATORS_THREE.C-------*/
void	heredoc(char *del, int *fd, int stdin_copy);
void	mini_here(char *del, int stdin_copy);
void	ft_stdinout(char **commands, char **env);
void	ft_operator(char **commands, char *here, char **env);
/*-----------------------*/

/*-------QUOTES.C-------*/
int		quote_close(char *str);
void	mini_qte(char *str, char *lit, int clsd, int clss);
char	*quote_line(char *str);
char	*clean_qt(char *str);
/*----------------------*/

/*-------QUOTES_TWO.C----*/
char	*clean_other(char *str);
/*----------------------*/

/*-------PIPE_FUNCTIONS.C----*/
void create_pipes(int n, int pipes[][2]);
void close_all_pipes(int n, int pipes[][2]);
void redirect_io(int pipes[][2], int cmd_index, int total_cmds);
void close_pipes_in_parent(int pipes[][2], int cmd_index, int total_cmds);
pid_t fork_and_execute_multiple(char *cmd[], int pipes[][2], int cmd_index, int total_cmds);
/*----------------------*/

/*-------PIPE_FUNCTIONS_TWO.C----*/
void wait_for_processes(int n, pid_t pids[]);
void execute_multiple_pipes(char ***commands, int n);
/*----------------------*/

/*-------PARSE_PIPES.C----*/
int count_pipes(char *input);
char *trim_whitespace(char *str);
int count_words(char *command);
t_word_info get_word_info(char *command, int index);
char *allocate_and_copy_word(char *command, t_word_info word_info);
char **allocate_tokens(int num_words);
void fill_tokens(char *command, char **tokens);
char **split_command(char *command);
void extract_command(char *start, char **commands, int *cmd_index);
char ***allocate_commands(int num_commands);
void split_by_pipe(char *input, char ***commands, int *cmd_index);
char ***parse_input(char *input, int *num_commands);
void free_commands(char ***commands, int num_commands);
/*----------------------*/

/*-------ENV.C----*/
t_env *create_env_node(char *env_str);
char *create_env_value(char *env_str, int len);
t_env *create_env_node_from_key_value(char *key, char *value);
int set_env_var(t_env_list **env_list, char *key, char *value);
int update_existing_var(t_env_list *node, char *value);
int add_new_env_var(t_env_list **env_list, char *key, char *value);
int create_new_env(t_env_list **env_list, t_env *new_content);
/*----------------------*/

/*-------ENV_TWO.C----*/
int unset_env_var(t_env_list **env_list, char *key);
t_env_list *init_env_list(char **envp);
int add_env_from_envp(t_env_list **env_list, char *env_str);
int initialize_pwd(t_env_list **env_list);
int initialize_oldpwd(t_env_list **env_list);
/*----------------------*/

/*-------ENV_THREE.C----*/
int update_shlvl(t_env_list **env_list);
int increment_shlvl(t_env_list **env_list, char *shlvl_value);
int initialize_shlvl(t_env_list **env_list);
void free_env_list(t_env_list *env_list);
int already_exists(t_env_list **env_list, char *key);
/*----------------------*/

/*-------ENV_FOUR.C----*/
char *get_env_value(t_env_list **env_list, char *key);
int initialize_environment(t_env_list **env_list, char **envp, char *shell_path);
/*----------------------*/

/*-------SIGNAL.C----*/
void ft_sigint_heredoc(int signal);
void ft_sigint_child(int signal);
void ft_sigint(int signal);
void ft_sigquit(int signal);
void signal_handler(void (*sigint_func)(int), void (*sigquit_func)(int));
/*----------------------*/

/*-------SIGNAL_TWO.C----*/
void write_signals(bool write_signal);
/*----------------------*/

/*-------PIPEX-------*/
char	**path_env(char **env);
size_t	where_path(char **env);
char	*first_word(char *arg);
char	*command(char **env, char *arg);
t_arguments	check_arg(int argn, char **argv, char **env);
t_arguments_bonus	check_here(int argn, char **argv);
t_arguments_bonus	check_arg_bonus(int argn, char **argv, char **env);
void				free_arguments_bonus(t_arguments_bonus *args);
void				pipex_free(int **fds, pid_t *pid, int i, int x);
int					**piping(t_arguments_bonus arguments, int argn);
void				fds_free(int **fds, int i, int x);
void				ft_wait(t_arguments_bonus arguments, int argn, pid_t *pid, int **fds);
void				here_doc(char **argv, int *fd);
void				dup_here(char **argv);
/*----------------------*/

#endif
