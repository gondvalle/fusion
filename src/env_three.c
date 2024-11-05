#include "../include/minishell.h"

bool ft_isdigit_str(const char *str)
{
    int i = 0;

    // Manejar cadenas vacías
    if (!str || str[i] == '\0')
        return false;

    // Verificar cada carácter en la cadena
    while (str[i] != '\0')
    {
        if (!isdigit((unsigned char)str[i]))
            return false;
        i++;
    }

    return true;
}


int update_shlvl(t_env_list **env_list)
{
	char *shlvl_value = get_env_value(env_list, "SHLVL");

	if (!shlvl_value || !ft_isdigit_str(shlvl_value))
		return initialize_shlvl(env_list);

	return increment_shlvl(env_list, shlvl_value);
}

int increment_shlvl(t_env_list **env_list, char *shlvl_value)
{
	int shlvl = ft_atoi(shlvl_value) + 1;
	char *new_shlvl_str = ft_itoa(shlvl);

	if (!new_shlvl_str)
		return perror("malloc failed"), 1;

	if (set_env_var(env_list, "SHLVL", new_shlvl_str))
		return free(new_shlvl_str), 1;

	free(new_shlvl_str);
	return(0);
}

int initialize_shlvl(t_env_list **env_list)
{
	t_env *new_env = create_env_node_from_key_value("SHLVL", "1");
	if (!new_env)
		return(1);

	return create_new_env(env_list, new_env);
}

void free_env_list(t_env_list *env_list)
{
	t_env_list *tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;

		if (tmp->content->key)
			free(tmp->content->key);

		if (tmp->content->value)
			free(tmp->content->value);

		free(tmp->content);
		free(tmp);
	}
}

int already_exists(t_env_list **env_list, char *key)
{
	t_env_list *tmp = *env_list;

	while (tmp)
	{
		if (strcmp(tmp->content->key, key) == 0)
			return 1;
		tmp = tmp->next;
	}
	return(0);
}
