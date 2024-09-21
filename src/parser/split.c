#include "cub3d.h"

char **ft_split_cub(char *s)
{
	char *temp;
	char **tab;

	temp = tab_to_space(s);
	tab = ft_split(temp, ' ');
	free(temp);
	return (tab);
}