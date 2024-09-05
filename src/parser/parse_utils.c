#include "../inc/cub3d.h"

int ft_get_file_size(char *map)
{
	int i;
	char *s;
	int fd;

	i = 0;
	fd = open(map, O_RDONLY, 0644);
	if (fd == -1)
		ft_error_msg(map, 0);
	s = get_next_line(fd);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void ft_error_msg(char *av, int type)
{
	if (type == 0)
	{	
		printf("cub3d: %s: Map Error\n", av);
		sleep(5);
		exit(1);
	}
}