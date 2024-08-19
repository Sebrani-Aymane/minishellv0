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
#include <stdio.h>
#include <string.h>

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
	getcwd(pwd,PATH_MAX);
	printf("%s",pwd);
}
void envpp(env_vars *list)
{

	if (!list)
		return;
	while (list)
	{
		printf("%s",list->vars);
		if(list->var_value)
			printf("=%s/n",list->var_value);
		else if(list->var_value)
		list = list->next;
	}
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