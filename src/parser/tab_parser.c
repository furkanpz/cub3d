#include "cub3d.h"

int str_tab_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}
void init_int(int *i, int *j, int *c)
{
	*i = 0;
	*j = 0;
	*c = 0;
}

char *tab_to_space(char *str)
{
	int i;
	int j;
	int c;
	char *new_str;
	char *trim_str;

	init_int(&i, &j, &c);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + (str_tab_count(str) * 3) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		c = 0;
		if (str[i] == '\t')
			while (c != 4)
				new_str[j + c++] = ' ';
		else
			new_str[j++] = str[i];
		j += c;
		i++;
	}
	new_str[j] = '\0';
	trim_str = ft_strtrim(new_str, "\n");
	free(new_str);
	return (trim_str);
}
