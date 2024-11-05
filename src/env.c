#include "../include/minishell.h"

t_env *create_env_node(char *env_str)
{
    t_env *new_env;
    int len;

    len = 0;
    while (env_str[len] && env_str[len] != '=')
        len++;

    new_env = malloc(sizeof(t_env));
    if (!new_env)
        return (perror("malloc failed"), NULL);

    new_env->key = strndup(env_str, len);
    if (!new_env->key)
        return (perror("malloc failed"), free(new_env), NULL);

    new_env->value = create_env_value(env_str, len);
    if (!new_env->value)
    {
        free(new_env->key);
        free(new_env);
        return NULL;
    }
    return(new_env);
}

char *create_env_value(char *env_str, int len)
{
    if (env_str[len] == '=')
        return strdup(env_str + len + 1);
    return strdup("");
}

int set_env_var(t_env_list **env_list, char *key, char *value)
{
    t_env_list *tmp;

    if (!key || !value)
        return (perror("Invalid key or value"), 1);

    tmp = *env_list;
    while (tmp)
    {
        if (strcmp(tmp->content->key, key) == 0)
            return update_existing_var(tmp, value);
        tmp = tmp->next;
    }

    return add_new_env_var(env_list, key, value);
}

int update_existing_var(t_env_list *node, char *value)
{
    free(node->content->value);
    node->content->value = strdup(value);
    if (!node->content->value)
        return (perror("malloc failed"), 1);
    return(0);
}

t_env *create_env_node_from_key_value(char *key, char *value)
{
    t_env *new_node;

    new_node = (t_env *)malloc(sizeof(t_env));
    if (!new_node)
    {
        perror("malloc");
        return NULL;
    }
    new_node->key = strdup(key);  // Duplica la clave
    if (!new_node->key)
    {
        free(new_node);
        perror("strdup");
        return NULL;
    }
    new_node->value = strdup(value);  // Duplica el valor
    if (!new_node->value)
    {
        free(new_node->key);
        free(new_node);
        perror("strdup");
        return NULL;
    }
    return (new_node);
}

int add_new_env_var(t_env_list **env_list, char *key, char *value)
{
    t_env *new_content = create_env_node_from_key_value(key, value);
    return create_new_env(env_list, new_content);
}

int create_new_env(t_env_list **env_list, t_env *new_content)
{
    t_env_list *new_node;
    t_env_list *tmp;

    new_node = malloc(sizeof(t_env_list));
    if (!new_node)
        return (free(new_content), 1);
    new_node->content = new_content;
    new_node->next = NULL;

    if (!*env_list)
        *env_list = new_node;
    else
    {
        tmp = *env_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    return(0);
}
