#include "../include/minishell.h"

void ft_sigint_heredoc(int signal)
{
    (void)signal;
    g_signal_status = SIGINT_HD;
    write(STDERR_FILENO, "\n", 1);
    close(STDIN_FILENO);
}

void ft_sigint_child(int signal)
{
    (void)signal;
    g_signal_status = SIGINT_CHILD;
    write(STDERR_FILENO, "\n", 1);
}

void ft_sigint(int signal)
{
    (void)signal;
    g_signal_status = SIGINT_FATHER;
    write(STDERR_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void ft_sigquit(int signal)
{
    (void)signal;
    g_signal_status = SIGQUIT_CHILD;
    write(STDERR_FILENO, "Quit: 3\n", 8);
}

void signal_handler(void (*sigint_func)(int), void (*sigquit_func)(int))
{
    struct sigaction sa;

    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    sa.sa_handler = sigint_func;
    sigaction(SIGINT, &sa, NULL);

    sa.sa_handler = sigquit_func;
    sigaction(SIGQUIT, &sa, NULL);
}
