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
void envpp(char **envp)
{
	int i=0;
	if (!envp || !(*envp))
		return;
	while (envp && envp[i] )
		printf("%s\n",envp[i++]);
}

env_vars *exportt_basic(char **envp, char **av)
{
    env_vars *list;
    env_vars *new_var;
    char **temp;

    list = list_init(envp);
    if (!list)
        return NULL;
    temp = split(av[2], '=');
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
    return (list);
}
