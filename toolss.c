#include "minishell.h"
#include <string.h>

char	**split(char *str, char sep)
{
	int		count_word;
	int		n;
	char	**strs;

	if (!str)
		return (NULL);
	n = 0;
	count_word = count_words(str, sep);
	strs = malloc(sizeof(char *) * (count_word + 1));
	if (!strs)
		return (NULL);
	while (n < count_word && *str)
	{
		while (*str && *str == sep)
			str++;
		strs[n] = return_word(str, sep);
		if (!strs[n])
			return (clear_strss(strs, n), NULL);
		while (*str && *str != sep)
			str++;
		n++;
	}
	strs[n] = NULL;
	return (strs);
}
void	copy_it(char *dest, char *src)
{	
	if(!src)
		return;
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}
char	*str_joiner(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
		return (strdup(s2));
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	copy_it(ret, s1);
	copy_it(ret + strlen(s1), s2);
	return (ret);
}
int	ft_strlen(char *str)
{
	int i=0;
	if (!str)
		return(0);
	while (str[i] != '\0')
		i++;
	return (i);
}
char **joker(env_vars *list)
{
    int i = 0;
    char **ret = NULL;
    env_vars *temp;
    char *str;
    temp = list;
    while (list)
    {
        list = list->next;
        i++;
    }
    list = temp;
    ret = calloc((i + 1) , sizeof(char *));
	if (!ret)
		return NULL;
	int j = 0;
    while (list && j < i)
    {
		if(!(list->var_value))
			str = strdup(list->vars);
		else
        	str = str_joiner(list->vars, "=");
        ret[j] = str_joiner(str, list->var_value);
        free(str); 
		j++;
        list = list->next;
    }
	ret[j] = NULL;
    return ret; 
}