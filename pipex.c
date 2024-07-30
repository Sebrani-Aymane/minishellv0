#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syslimits.h>
#include <unistd.h>
#include <limits.h>

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
void	copy_it(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}
char	*str_joiner(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
		return (strdup(s2));
	ret = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!ret)
		return (NULL);
	copy_it(ret, s1);
	copy_it(ret + strlen(s1), s2);
	return (ret);
}
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
//expoort get the variable value write that into a file change if needed read form that file

void excute_builtins(char* builtin,char **av,char **envp)
{
	if (strcmp(builtin,"echo") == 0)
		echoo(av+1);
	else if (strcmp(builtin, "pwd") == 0)
		pwdd(1);
	else if (strcmp(builtin,"env"))
		envpp(envp);
	else if (strcmp(builtin,"export"))
		exportt(envp);


}

int	main(int ac, char **av, char **envp)
{
	int i=0;
	(void)ac;
	char *to_excute;
char **paths;
char *command_path;

command_path = malloc(strlen(av[1] + 2));
if (!command_path)
	return(printf("error command path\n"),1);
command_path  = str_joiner("/",av[1]);
paths = split(get_path(envp), ':');
if (!paths)
	return(printf("ERROR SPLIT\n"),1);
while(paths[i])
{
	to_excute = malloc(strlen(paths[i] + strlen(command_path)));
	to_excute = str_joiner(paths[i],command_path);
	if (access(to_excute, X_OK) == 0)
	{
		execve(to_excute, av +1, envp);
	}
	else
		free(to_excute);
		i++;
}
free(paths);
free(command_path);

int j =0;
char **builtins;
while (av[1])
{
	builtins = split("cd echo pwd export unset env exit", ' ');
	if (strcmp(av[1],builtins[j]) == 0)
		excute_builtins(av[1],av,envp);
	j++;
}
j = 0;
while(builtins[j]) 
{
	free(builtins[j]);
	j++;
}

return(0);
}
