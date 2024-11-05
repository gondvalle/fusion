#include "../include/minishell.h"

int unset_env_var(t_env_list **env_list, char *key)
{
    t_env_list *tmp;
    t_env_list *prev;

    tmp = *env_list;
    prev = NULL;
    while (tmp)
    {
        if (strcmp(tmp->content->key, key) == 0)
        {
            if (prev)
                prev->next = tmp->next;
            else
                *env_list = tmp->next;

            free(tmp->content->key);
            free(tmp->content->value);
            free(tmp->content);
            free(tmp);
            return 0;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return(1);
}

t_env_list *init_env_list(char **envp)
{
    t_env_list *env_list = NULL;
    int i = 0;

    while (envp[i])
    {
        if (add_env_from_envp(&env_list, envp[i]))
            return free_env_list(env_list), NULL;
        i++;
    }
    return(env_list);
}

int add_env_from_envp(t_env_list **env_list, char *env_str)
{
    t_env *new_env = create_env_node(env_str);
    if (!new_env)
        return 1;

    if (create_new_env(env_list, new_env))
        return free_env_list(*env_list), 1;

    return(0);
}

int initialize_pwd(t_env_list **env_list)
{
    char cwd[PATH_MAX];
    t_env *new_env;

    if (already_exists(env_list, "PWD"))
        return 0;

    if (!getcwd(cwd, sizeof(cwd)))
        return perror("getcwd failed"), 1;

    new_env = create_env_node_from_key_value("PWD", cwd);
    if (!new_env)
        return(1);

    return create_new_env(env_list, new_env);
}

int initialize_oldpwd(t_env_list **env_list)
{
    t_env *new_env;

    if (already_exists(env_list, "OLDPWD"))
        return 0;

    new_env = create_env_node_from_key_value("OLDPWD", "");
    if (!new_env)
        return 1;

    return create_new_env(env_list, new_env);
}
