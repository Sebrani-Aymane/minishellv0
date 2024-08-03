/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:23:32 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/03 06:01:30 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

env_vars **list_init(char **variables)
{
	env_vars **head;
	env_vars *list;
	int i;
	char **splited;
	i = 0;
	list = malloc(sizeof(env_vars));
	if (!list)
		return(NULL);
	head = malloc (sizeof(env_vars*));
	if (!head)
		return(NULL);
	*head = list;
	if (!variables || *variables)
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
		ft_lstadd_front(&list, list->next);
		list = list->next;
		i++;
		clear_strss(splited, 2);
		
	}
	list->next = NULL;
	return(head);
	
}