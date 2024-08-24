#include "minishell.h"
#include <stdio.h>
/*void echoo(char **av)
{
	int i =1;

	if (av[1][1] == '-' && av[])
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
		printf("\n");
	}
}*/
void echoo(char **av)
{
    int i = 1;         
    int newline = 1; 

    while (av[i] && strcmp(av[i], "-n") == 0)
	{
        newline = 0;
        i++; 
    }
    while (av[i])
	{
        printf("%s", av[i]);
        if (av[i + 1])
		{ 
            printf(" ");
        }
        i++;
	}
    if (newline)
	{
        printf("\n");
    }
}

void pwdd(int a)
{
	char *pwd = NULL;
	(void) a;
	pwd = getcwd(NULL,0);
	printf("%s\n",pwd);
}
env_vars *envpp(env_vars *list)
{
	env_vars *tmp;

	tmp = list;
	if (!list)
		return(NULL);
	while (list)
	{
		printf("%s",list->vars);
		if(list->var_value)
			printf("=%s\n",list->var_value);
		else
			printf("\n");
		list = list->next;
	}
	return(tmp);
}

int	chdirr(char **env,char **av)
{
	int res =-1;

	if(!av[1])
		res = chdir(get_path(env,"HOME="));
	else
		res = chdir(av[1]);
	return(res);
}