#include "minishell.h"
char	*get_path(char **envp)
{
	char	*path;

	while (*envp && strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	path  = strdup(*envp + 5);
	if (!path)
		return (NULL);
	return (path);
}
int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

char	*return_word(char *str, char c)
{
	char	*ret;
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	while (str[count] != c && str[count])
		count++;
	ret = malloc((count + 2
	
	
	
	
	
	
	
	
	
	
	


































































































































	
	
	
	
	
	
	
	
	);
	if (!ret)
		return (NULL);
	while (i < count)
		ret[i++] = *(str++);
	ret[i] = '\0';
	return (ret);
}

void	clear_strss(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(strs[i++]);
	free(strs);
}
