/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:03:15 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/23 22:15:47 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void unset(env_vars *env, char **av)
{
    int i = 1;

    while (av[i])
    {
        env_vars *current = env;
        env_vars *previous = NULL;

        while (current)
        {
            if (ft_strcmp(current->vars, av[i]) == 0)
            {
                if (previous == NULL)
                    env = current->next; 
                else
                    previous->next = current->next;
                free(current->vars);
                free(current->var_value);
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
        i++;
    }
}
