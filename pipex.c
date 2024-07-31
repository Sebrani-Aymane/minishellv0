#include "minishell.h"

//expoort get the variable value write that into a linked list change if needed read form that file
int	main(int ac, char **av, char **envp)
{
	int j =0;
	char **builtins;

	(void)ac;
	if (excutefilepath(av,envp) == 0)
	{
		builtins = split("cd echo pwd export unset env exit", ' ');
		while (builtins[j++])
		if (strcmp(av[1],builtins[j]) == 0)
			excute_builtins(av[0],av,envp);
	}
	free_double(builtins);
	return(0);
}

