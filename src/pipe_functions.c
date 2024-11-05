#include "../include/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_pipes(int n, int pipes[][2])
{
    int i;
    i = 0;
    while (i < n - 1)
    {
        if (pipe(pipes[i]) == -1)
        {  
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

void close_all_pipes(int n, int pipes[][2])
{
    int i;
    i = 0;
    while (i < n)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
}

void redirect_io(int pipes[][2], int cmd_index, int total_cmds)
{
    if (cmd_index > 0)
    {
        if (dup2(pipes[cmd_index - 1][0], STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
    }
    if (cmd_index < total_cmds - 1)
    {
        if (dup2(pipes[cmd_index][1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
    }
}

void close_pipes_in_parent(int pipes[][2], int cmd_index, int total_cmds)
{
    if (cmd_index > 0)
    {
        close(pipes[cmd_index - 1][0]);
    }
    if (cmd_index < total_cmds - 1)
    {
        close(pipes[cmd_index][1]);
    }
}

pid_t fork_and_execute_multiple(char *cmd[], int pipes[][2], int cmd_index, int total_cmds)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        redirect_io(pipes, cmd_index, total_cmds);
        close_all_pipes(total_cmds - 1, pipes);
        execvp(cmd[0], cmd);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        close_pipes_in_parent(pipes, cmd_index, total_cmds);
    }
    return pid;
}
