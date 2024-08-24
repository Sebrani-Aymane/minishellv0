/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:20:46 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/22 23:19:13 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
#define MINISHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
 //remove it after adding libft functions

typedef struct env_vars_t{
	char *vars;
	char *var_value;
	char **env;
	struct env_vars_t *next;
}  env_vars;
void	clear_strss(char **strs, int n);
void 	export_with_plus(char *av,env_vars *env);
int ft_strcmp(char *str,char *str1);
env_vars *execute_builtins(char* builtin, char **av,env_vars *list,char **env);
void valid_to_add(env_vars *env,char *str);
char *get_till(char *str, char c);
void first_in(char *str,env_vars *env);
void unset(env_vars *env, char **av);
void valid_to_add_plus(env_vars *env,char *str);
env_vars *export_if_plus(char **input,env_vars *list);
void add_to_list(env_vars **head,env_vars *new);
int	ft_isalnum(int c);
int check_key(char *str);
void echoo(char **av);
void pwdd(int a);
env_vars *envpp(env_vars *list);
void export_all(env_vars *env,char **av);
int	ft_strlen(char *str);
void export_it(env_vars *env, char *str);
char	*get_path(char **envp,char *str);
int	count_words(char *str, char c);
char	*return_word(char *str, char c);
char **joker(env_vars *list);
void	ft_lstadd_front(env_vars **lst, env_vars *next);
char *ret(char *in);
env_vars	*ft_lstlast(env_vars *lst);
env_vars *append_to_list(env_vars *list,char **temp);
char	**split(char *str, char sep);
env_vars *exportt_plus(char **av,env_vars *list);
void	clear_strss(char **strs, int n);
env_vars *list_init(char **variables);
void	ft_lstadd_back(env_vars **lst, env_vars *last);
env_vars *exportt_plus(char **av,env_vars *list);
void free_double(char **str);
void excutefilepath(char **av,char *path,char **env);
void	copy_it(char *dest, char *src);
char	*str_joiner(char *s1, char *s2);
int already_var(env_vars *list, char *str);
char** split_by_first_occurrence(char *str, char delimiter);
int already_vars(env_vars *list, char *str);
env_vars *update_value(env_vars **list,char **str);
char *ret(char *in);
int	chdirr(char **env, char **av);
#endif
