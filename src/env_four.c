#include "../include/minishell.h"

char *get_env_value(t_env_list **env_list, char *key)
{
    t_env_list *tmp = *env_list;

    while (tmp)
    {
        if (strcmp(tmp->content->key, key) == 0)
            return tmp->content->value;
        tmp = tmp->next;
    }
    return(NULL);
}

int initialize_environment(t_env_list **env_list, char **envp, char *shell_path)
{
    if (!envp || !shell_path)
    {
        perror("Invalid environment or shell path");
        return 1;
    }

    // Initialize environment list with envp (simplified)
    *env_list = init_env_list(envp);
    if (!*env_list)
    {
        perror("Failed to initialize environment list");
        return 1;
    }

    // Initialize essential variables
    if (add_new_env_var(env_list, "PWD", getenv("PWD")))
        perror("Failed to initialize PWD");

    if (add_new_env_var(env_list, "OLDPWD", NULL))
        perror("Failed to initialize OLDPWD");

    if (update_shlvl(env_list))
        perror("Failed to update SHLVL");

    if (add_new_env_var(env_list, "_", shell_path))
        perror("Failed to initialize _");

    return 0;
}