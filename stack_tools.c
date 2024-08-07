/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:34 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/05 23:30:47 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

env_vars	*ft_lstlast(env_vars *lst)
{
	if (lst && lst->next)
	{
		while (lst && lst->next)
			lst = lst->next;
	}
	return (lst);
}
void	ft_lstadd_back(env_vars **lst, env_vars *new)
{
	env_vars *position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast(*lst);
		position->next = new;
	}
}
/*
env_vars *export_plus(char **envp,char **av)
{
	env_vars *tmp;
	env_vars *list;
    env_vars *new_var;
	
    char **temp;
    list = list_init(envp);
    if (!list)
        return NULL;
	tmp = list;
    temp = split(av[1], '=');
    if (!temp)
        return NULL;
	if (already_var(list,temp[0]) && !temp[1])
		return(tmp);
	if (av[1][0] == '+')
		list = update_value(list,temp);
	list = ft_lstlast(list);
    new_var = malloc(sizeof(env_vars));
    if (!new_var)
	{
        free(temp);
        return NULL; 
    }
    new_var->vars = temp[0];
	new_var->var_value = temp[1];
    new_var->next = NULL;
    (list)->next = new_var;
	list = tmp;
    return (list);
}
int already_var(env_vars *list,char *str)
{
	while (list && list ->next)
	{
		if (strcmp(list->vars,str) == 0)
			return(1);
		list = list->next;
	}
	return(0);
}
env_vars *update_value(env_vars *list,char **str)
{
	env_vars *tmp;

	while (list && strcmp(list->vars,str[0]))
		list = list->next;
	list->var_value = strdup(str[1]);
	return (tmp);
}*/