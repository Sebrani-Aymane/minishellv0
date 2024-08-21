/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:40:15 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/21 23:05:36 by asebrani         ###   ########.fr       */
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
void first_in(char *str,env_vars *env)
{
	env_vars *new;
	
	if(!check_key(str))
		return;
	new = malloc(sizeof(env_vars));
	if(!new)
		return;
	else
	{
		while (env)
			env = env->next;
		new->vars = strdup(str);
		new->var_value = strdup("");
		new->next = NULL;
		add_to_list(&env,env);
	}
}