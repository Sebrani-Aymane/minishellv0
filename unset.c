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

void unsett(env_vars *env,char **av)
{
	int i = 1;

	while (av[i])
	{
		if (check_key(av[i]))
		{
			
		}
	}
}