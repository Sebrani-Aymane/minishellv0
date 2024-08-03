/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:20:46 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/03 05:06:13 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINISHELL_H
#define MINISHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syslimits.h>
#include <unistd.h>
#include <limits.h>

typedef struct env_vars_t{
	char *vars;
	char *var_value;
	char **env;
	struct env_vars_t *next;
}  env_vars;
void	clear_strss(char **strs, int n);
void execute_builtins(char* builtin, char **av, char **envp);
void echoo(char **av);
void pwdd(int a);
void envpp(char **envp);
char	*get_path(char **envp);
int	count_words(char *str, char c);
char	*return_word(char *str, char c);
void	ft_lstadd_front(env_vars **lst, env_vars *next);
char	**split(char *str, char sep);
void	clear_strss(char **strs, int n);
env_vars **list_init(char **variables);
env_vars **exportt_basic(char **env,char **var);
void free_double(char **str);
int excutefilepath(char **av,char **envp);
void	copy_it(char *dest, char *src);
char	*str_joiner(char *s1, char *s2);

#endif
