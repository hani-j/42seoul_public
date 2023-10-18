#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		av;

	fd = open("test.txt", O_RDONLY);
	if (argc == 999)
		return (0);
	av = atoi(argv[1]);
	while (av)
	{
		line = get_next_line(fd);
		if (line == 0)
			break;
		printf("%s", line);
		free(line);
		av--;
	}
	if (av != 0)
		free(line);
	close(fd);
	return (0);
}