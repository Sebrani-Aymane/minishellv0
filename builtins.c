#include "minishell.h"
#include <stdio.h>
void echoo(char **av)
{
	int i =0;

	if (strcmp(av[0],"-n") == 0)
	{	
		while (av[i+1])
		{
			printf("%s",av[i]);
			i++;
		}
	}
	else
	{
		while (av[i])
		{
			printf("%s",av[i]);
			i++;
		}
		printf("/n");
	}
}
void pwdd(int a)
{
	char *pwd = NULL;
	(void) a;
	getcwd(pwd,PATH_MAX);
	printf("%s",pwd);
}
void envpp(char **env)
{
	int i=0;
	if (!env || !*env)
		return;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

env_vars *exportt_basic(char **envp, char **av)
{
	env_vars *tmp;
	env_vars *list;
    env_vars *new_var;
	
    char **temp;
    list = list_init(envp);
    if (!list)
        return NULL;
	tmp = list;
	if(!av[1])
		return(list);
    temp = split(av[1], '=');
    if (!temp)
        return NULL;
	list = ft_lstlast(list);
    new_var = malloc(sizeof(env_vars));
    if (!new_var)
	{
        free(temp);
        return NULL; 
    }
    new_var->vars = temp[0];
	new_var->var_value = temp[1];
    new_var->next = NULL;
    (list)->next = new_var;
	list = tmp;
    return (list);
}

env_vars *export_plus(char **envp,char **av)
{
	env_vars *tmp;
	env_vars *list;
    env_vars *new_var;
	
    char **temp;
    list = list_init(envp);
    if (!list)
        return NULL;
	tmp = list;
    temp = split(av[1], '=');
    if (!temp)
        return NULL;
	if (already_var(list,temp[0]) && !temp[1])
		return(tmp);
	if (av[1][0] == '+')
		list = update_value(list,temp);
	list = ft_lstlast(list);
    new_var = malloc(sizeof(env_vars));
    if (!new_var)
	{
        free(temp);
        return NULL; 
    }
    new_var->vars = temp[0];
	new_var->var_value = temp[1];
    new_var->next = NULL;
    (list)->next = new_var;
	list = tmp;
    return (list);
}
int already_var(env_vars *list,char *str)
{
	while (list && list ->next)
	{
		if (strcmp(list->vars,str) == 0)
			return(1);
		list = list->next;
	}
	return(0);
}
env_vars *update_value(env_vars *list,char **str)
{
	env_vars *tmp;

	tmp = list;
	while (list && strcmp(list->vars,str[0]))
		list = list->next;
	list->var_value = strdup(str[1]);
	return (tmp);
}