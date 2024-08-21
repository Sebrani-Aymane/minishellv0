#include "minishell.h"
#include <readline/readline.h>

char *ret(char *in)
{
	int i =0;
	while (in[i])
	{
		if (in[i] == '+')
			in[i] = in[i+1];
		i++;
	}
	return(in);
}
int	ft_isalnum(int c)
{
	if (((c <= 122 && c >= 97) || (c <= 90 && c >= 65))
		|| (c <= '9' && c >= '0'))
		return (1);
	else
		return (0);
}
