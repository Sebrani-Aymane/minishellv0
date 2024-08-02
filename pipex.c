
#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	int j = -1;
	char **builtins;

	(void)ac;
	if (excutefilepath(av,envp) == 0)
	{
		builtins = split("cd echo pwd export unset env exit", ' ');
		while (builtins[++j])
			if (strcmp(av[1],builtins[j]) == 0)
				execute_builtins(builtins[j],av,envp);
		free_double(builtins);
	return(0);
}
}
