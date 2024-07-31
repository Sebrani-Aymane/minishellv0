#include "minishell.h"
void echoo(char **av)
{
	int i =1;

	if (strcmp(av[2],"-n") == 0)
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
	while (envp[i])
	printf("%s\n",envp[i++]);
}
void export(char **env,char **var)
{
	env_vars	hello
	if (!var[2])
		envpp(env);
	else

}