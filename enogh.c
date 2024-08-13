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
env_vars *append_to_list(env_vars *list,char **temp)
{
	env_vars *new_var;
	env_vars *tmp;

	tmp = list;
    new_var = malloc(sizeof(env_vars));
    if (!new_var)
	{
        free(temp);
        return NULL; 
    }
    new_var->vars = temp[0];
	new_var->var_value = temp[1];
    new_var->next = NULL;
	ft_lstadd_back(&list,new_var);
    return (list);
}
