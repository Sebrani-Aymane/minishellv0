/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:46 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/23 18:42:28 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void valid_to_add(env_vars *env,char *str)
{
	char *temp;
	env_vars *tmp;
	env_vars *new;
	char *key;

	key = get_till(str,'=');
	tmp = env;
	new = malloc(sizeof(env_vars));
	temp = strchr(str, '=');
	if (check_key(key) && (temp + 1))
	{
		new-> vars = get_till(str,'=');
		new-> var_value = strdup(temp+1);
		add_to_list(&tmp,new);
		return;
	}
	else
		return;
}

env_vars *get_node(env_vars **list,char *str)
{
	while((*list))
	{
		if(strcmp((*list)->vars, str) == 0)
			return (*list);
		*list = (*list)->next;
	}
	return (NULL);
}

void 	export_it(env_vars *env,char *str)
{
	char *key;
	char *value;

	value = strchr(str,'=');
	key = get_till(str,'=');
	while(env && env->next)
	{
		if (ft_strcmp(env->vars,key) == 0 || ft_strcmp(env->next->vars,key) == 0 )
		{
			env->var_value = strdup(value);
			return;
		}
		else
		env = env->next;
	}
	free(key);
	valid_to_add(env, str);
}

void export_all(env_vars *env,char **av)
{
	int i=1;

	while (av[i])
	{
		if(strchr(av[i],'+'))
			export_with_plus(av[i],env);	
		else if (!(strchr(av[i],'=') ))
			first_in(av[i],env);
		else if (strchr(av[i],'='))
			export_it(env,av[i]);
		i++;
	}
}