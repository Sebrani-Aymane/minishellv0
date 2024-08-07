/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:20:46 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/07 02:44:00 by asebrani         ###   ########.fr       */
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
#include <readline/readline.h>
#include <readline/history.h>

typedef struct env_vars_t{
	char *vars;
	char *var_value;
	char **env;
	struct env_vars_t *next;
}  env_vars;
void	clear_strss(char **strs, int n);
env_vars *execute_builtins(char* builtin, char **av,env_vars *list);
void echoo(char **av);
void pwdd(int a);
void envpp(char **env);
int	ft_strlen(char *str);
char	*get_path(char **envp,char *str);
int	count_words(char *str, char c);
char	*return_word(char *str, char c);
char **joker(env_vars *list);
void	ft_lstadd_front(env_vars **lst, env_vars *next);
env_vars	*ft_lstlast(env_vars *lst);
char	**split(char *str, char sep);
void	clear_strss(char **strs, int n);
env_vars *list_init(char **variables);
void	ft_lstadd_back(env_vars **lst, env_vars *last);
env_vars *exportt_basic(char **env,char **var);
void free_double(char **str);
void excutefilepath(char **av,char *path,char **env);
void	copy_it(char *dest, char *src);
char	*str_joiner(char *s1, char *s2);
int already_var(env_vars *list, char *str);
env_vars *update_value(env_vars *list, char **str);
int	chdirr(char **env, char **av);
#endif
