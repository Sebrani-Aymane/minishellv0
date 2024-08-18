/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:34 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/18 03:57:03 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>


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

env_vars *exportt_plus(char **av,env_vars *list)
{
	env_vars *tmp;
	env_vars *another_head;
    char **temp;
	
    if (!list)
        return NULL;
	tmp = list;
	another_head = list;
   	temp = split(av[1], '=');
    if (!temp)
        return NULL;
	
	if (already_var(list,temp[0]) && !temp[1])
		return(tmp);
	else if ((already_var(list,temp[0])) && temp[1]) 
	{
		if (temp[0][ft_strlen(temp[0]) - 1] == '+')
			{
				list = update_value(&list,temp);
				if (!(already_vars(list,temp[0])))
					list = append_to_list(list,temp);
				else
				{
					update_value(&tmp,temp); 
					tmp->var_value = str_joiner(tmp->var_value,temp[1]);
					list = another_head;
				}
				return(list);
			}
		else
		{
			update_value(&list, temp);
			list->var_value = strdup(temp[1]);
		}
		return(tmp);
	}
	list = append_to_list(list, temp);
	list = tmp;
    return (list);
}
int already_var(env_vars *list,char *str)
{
	while (list)
	{
		if (strcmp(list->vars,str) == 0 || str[ft_strlen(str) - 1] == '+') 
			return(1);
		list = list->next;
	}
	return(0);
}
env_vars *update_value(env_vars **list,char **str)
{
	env_vars *tmp;
	char	*appended;
	tmp = *list;
	
	while((*list))
	{
		appended = strdup(str[0]);
		if (appended[ft_strlen(appended) - 1] == '+')
			appended[ft_strlen(appended) - 1] = '\0';
		if(strcmp((*list)->vars, appended) == 0)
			return (*list);
		*list = (*list)->next;
	}
	return (tmp);
}
