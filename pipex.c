#include "minishell.h"
#include <readline/readline.h>

int	main(int ac, char **av, char **envp)
{
	char **builtins;
	env_vars *list;
	char *str;
	int j;

	list = list_init(envp);
	str = get_path(envp,"PATH=");
	(void)ac;
	av = NULL;
	while (1)
	{
		j = -1;
		char *cmd = readline("minishell $ ");
		av = split (cmd,' ');
		if (!av || !(*av))
			return(0);
		excutefilepath(av,str,envp);
		builtins = split("cd echo pwd export unset env exit", ' ');
		while (builtins[++j])
		{
			if (strcmp(av[0],builtins[j]) == 0)
				list = execute_builtins(builtins[j],av,list);
		}
		free_double(builtins);
	}
	return(0);
}