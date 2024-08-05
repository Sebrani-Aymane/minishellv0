/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:23:32 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/05 06:41:54 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
/*
env_vars *list_init(char **variables)
{
	env_vars *list;
	int i;
	char **splited;
	i = 0;
	list = malloc(sizeof(env_vars));
	if (!list)
		return(NULL);
	if (variables == NULL || variables[i] == NULL)
		return(NULL);
	while(variables[i])
	{
		splited = split(variables[i], '=');
		if (!splited)
			return(printf("here"),NULL);
		list->vars = splited[0];
		list->var_value = splited[1];
		list->next = malloc(sizeof(env_vars));
		if (!list->next)
			return NULL;
		list = list->next;
		ft_lstadd_back(&list, list->next);
		printf("%p==========%s\n",list,splited[1]);
		i++;
		clear_strss(splited, 2);
	}
	list->next = NULL;
	return((list));
	
}
int main(int ac,char **av,char **env)
{
	(void) ac;
	(void) av;
	env_vars **list;

	list = list_init(env);
	while (list)
	{
		printf("%s======%s\n",(*list)->vars,(*list)->var_value);
		*list = (*list)->next;
	}
	return(0);
	
}
*/
#include "minishell.h"

env_vars *list_init(char **variables)
{
    env_vars *list = NULL;
    env_vars *new_node;
    int i = 0;
    char **splited;

	if (variables == NULL || variables[i] == NULL)
    	return NULL;
    while (variables[i])
    {
        splited = split(variables[i], '=');
        if (!splited)
            return NULL;
        new_node = malloc(sizeof(env_vars));
        if (!new_node)
        {
            clear_strss(splited, 2);
            return NULL;
        }
        new_node->vars = splited[0];
        new_node->var_value = splited[1];
        new_node->next = NULL;
        ft_lstadd_back(&list, new_node);
        i++;
    }
    return list;
}