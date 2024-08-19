#include "minishell.h"
#include <readline/readline.h>

void print_it(char **av)
{
	while(*av)
		printf("%s\n",*(av++));
}
int	main(int ac, char **argv, char **envp)
{
	char **builtins;
	env_vars *list;
	char *str;
	int j;
	int i;

	list = list_init(envp);
	str = get_path(envp,"PATH=");
	(void)ac;
	(void)argv;
	char **av = NULL;
	while (1)
	{
		i = 1;
		j = -1;
		char *cmd = readline("minishell $ ");
		av = split (cmd,' ');
		if (!av || !(*av))
			return(0);
		builtins = split("cd echo pwd export unset env exit", ' ');
		while (builtins[++j])
		{
			if (strcmp(av[0],builtins[j]) == 0)
			{
				list = execute_builtins(builtins[j],av,list);
				i = 0;
			}
		}
		if (i)
			excutefilepath(av,str,envp);
		free_double(builtins);
	}
	return(0);
}