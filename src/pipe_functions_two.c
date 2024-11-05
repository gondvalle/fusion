#include "../include/minishell.h"

void wait_for_processes(int n, pid_t pids[])
{
    int i;
    i = 0;
    while (i < n)
    {
        waitpid(pids[i], NULL, 0);
        i++;
    }
}

void execute_multiple_pipes(char ***commands, int n)
{
    int i;
    int pipes[n-1][2];
    pid_t pids[n];

    create_pipes(n, pipes);

    i = 0;
    while (i < n)
    {
        pids[i] = fork_and_execute_multiple(commands[i], pipes, i, n);
        i++;
    }
    close_all_pipes(n - 1, pipes);
    wait_for_processes(n, pids);
}