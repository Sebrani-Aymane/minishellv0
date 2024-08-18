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

int	chdirr(char **env,char **av)
{
	int res =-1;


	if(!av[1])
		res = chdir(get_path(env,"HOME="));
	else
		res = chdir(av[1]);
	return(res);

}