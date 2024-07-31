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
	struct env_vars_t *next;
	struct env_vars_t **head;
	struct env_vars_t *prev;
}  env_vars;
void excute_builtins(char* builtin,char **av,char **envp);
void echoo(char **av);
void pwdd(int a);
void envpp(char **envp);
char	*get_path(char **envp);
int	count_words(char *str, char c);
char	*return_word(char *str, char c);
char	**split(char *str, char sep);
void	clear_strss(char **strs, int n);
void exportt(char **env,char **var);
void free_double(char **str);
int excutefilepath(char **av,char **envp);
void	copy_it(char *dest, char *src);
char	*str_joiner(char *s1, char *s2);
#endif
