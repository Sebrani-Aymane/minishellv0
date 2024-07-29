#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[count] != c && str[count])
		count++;
	ret = malloc(sizeof(char) * (count + 1));
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

int	main(int ac, char **av, char **envp)
{
	int i=0;
	(void)ac;
char **paths;
paths = split(get_path(enpvp, ':'))
while (av[i])
{
if (access(, F_OK | X_OK) == 0)
{
	execve("/bin/ls", args, envp);
}

}

}