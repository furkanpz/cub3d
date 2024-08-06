#include "cub3d.h"

void	f_fill(t_get_file *file, char **map, size_t row, size_t col)
{
	if (row < 0 || col < 0)
		return ;
	if (row >= file->mapy || col >= file->lmapsize)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'X')
		return ;
    if (file->fferror == 1)
        return ;
    if (map[row][col] == '_' || !map[row + 1])
    {    
        file->fferror = 1;
        return ;
    }
    map[row][col] = 'X';
	f_fill(file, map, row - 1, col);
	f_fill(file, map, row + 1, col);
	f_fill(file, map, row, col - 1);
	f_fill(file, map, row, col + 1);
}

void freepchar(char **str)
{
    size_t i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
    if (str)
        free(str);
    str = NULL;
}

char **temp_map_f(t_get_file *file)
{
    char **temp_map;
    int i;
	size_t c;

	c = 0;
    temp_map = malloc(sizeof(char *) * (file->mapy + 2));
    if (!temp_map)
        return (NULL);
    i = 0;
	temp_map[0] = malloc(sizeof(char) * (file->lmapsize + 1));
	while (c < file->lmapsize)
		temp_map[0][c++] = '_';
	temp_map[0][c] = '\0';
	c = 1;
    while (file->map[i])
        temp_map[c++] = ft_strdup(file->map[i++]);
    temp_map[c] = NULL;
    return (temp_map);
}

void p_map(char **temp_map)
{
	for (int x= 0; temp_map[x];x++)
		printf("%s\n",temp_map[x]);
}

void	flood_fill(t_get_file *file)
{
    char **temp_map;

    temp_map = temp_map_f(file);
    file->fferror = 0;
    f_fill(file, temp_map, file->p.y, file->p.x);
    freepchar(temp_map);
}