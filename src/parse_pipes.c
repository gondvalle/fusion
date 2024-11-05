#include "../include/minishell.h"

int count_pipes(char *input)
{
    int count = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] == '|')
            count++;
        i++;
    }
    return (count + 1);
}

char *trim_whitespace(char *str)
{
    char *end;

    while (*str == ' ')
        str++;
    if (*str == '\0')
        return str;

    end = str + strlen(str) - 1;
    while (end > str && *end == ' ')
    {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

int count_words(char *command)
{
    int i = 0;
    int in_word = 0;
    int count = 0;

    while (command[i] != '\0')
    {
        if (command[i] != ' ' && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (command[i] == ' ')
        {
            in_word = 0;
        }
        i++;
    }
    return count;
}

t_word_info get_word_info(char *command, int index)
{
    t_word_info word_info;
    int i = index;

    word_info.start = index;
    while (command[i] != '\0' && command[i] != ' ')
        i++;
    word_info.length = i - word_info.start;
    return word_info;
}

char *allocate_and_copy_word(char *command, t_word_info word_info)
{
    char *word = malloc((word_info.length + 1) * sizeof(char));
    int j;

    if (!word)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (j = 0; j < word_info.length; j++)
    {
        word[j] = command[word_info.start + j];
    }
    word[word_info.length] = '\0';
    return word;
}

char **allocate_tokens(int num_words)
{
    char **tokens = malloc((num_words + 1) * sizeof(char *));

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return tokens;
}

void fill_tokens(char *command, char **tokens)
{
    int token_index = 0;
    int i = 0;
    t_word_info word_info;

    while (command[i] != '\0')
    {
        if (command[i] != ' ')
        {
            word_info = get_word_info(command, i);
            tokens[token_index] = allocate_and_copy_word(command, word_info);
            token_index++;
            i += word_info.length;
        }
        else
        {
            i++;
        }
    }
    tokens[token_index] = NULL;
}

char **split_command(char *command)
{
    int num_words = count_words(command);
    char **tokens = allocate_tokens(num_words);

    fill_tokens(command, tokens);
    return tokens;
}

void extract_command(char *start, char **commands, int *cmd_index)
{
    char *cleaned_command = trim_whitespace(start);
    int i  = 0;

    if (*cleaned_command != '\0')
    {
        i = ft_strlen(commands[i]);
        //commands[*cmd_index] = split_command(cleaned_command);
        (*cmd_index)++;
    }
}

char ***allocate_commands(int num_commands)
{
    char ***commands = malloc(num_commands * sizeof(char **));
    if (!commands)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return commands;
}

void split_by_pipe(char *input, char ***commands, int *cmd_index)
{
    //char *start = input;
    char *end = input;
    int i;

    i = 0;
    i = ft_strlen(commands[i][i]);
    i = cmd_index[0];
    while (*end != '\0')
    {
        if (*end == '|')
        {
            *end = '\0';
            //extract_command(start, commands, cmd_index);
            //start = end + 1;
        }
        end++;
    }
    //extract_command(start, commands, cmd_index);
}

char ***parse_input(char *input, int *num_commands)
{
    char ***commands;
    int cmd_index = 0;

    if (!input || *input == '\0')
        return NULL;

    *num_commands = count_pipes(input);
    commands = allocate_commands(*num_commands);
    if (!commands)
        return NULL;

    //split_by_pipe(input, commands, &cmd_index);

    if (cmd_index != *num_commands)
        *num_commands = cmd_index; // Ajustar si hay comandos vacíos

    return commands;
}

void free_commands(char ***commands, int num_commands)
{
    if (!commands)
        return;

    for (int i = 0; i < num_commands; i++)
    {
        char **command = commands[i];
        if (command)
        {
            for (int j = 0; command[j] != NULL; j++)
            {
                free(command[j]);
            }
            free(command);
        }
    }
    free(commands);
}


