#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd1, fd2, fd3;
	char	*line1, *line2, *line3;
	int		av;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (argc == 999)
		return (0);
	av = atoi(argv[1]);
	while (av)
	{
		line1 = get_next_line(fd1);
		if (line1 == 0)
			break;
		line2 = get_next_line(fd2);
		if (line2 == 0)
			break;
		line3 = get_next_line(fd3);
		if (line3 == 0)
			break;
		printf("%s%s%s\n", line1, line2, line3);
		free(line1);
		free(line2);
		free(line3);
		av--;
	}
	if (av != 0)
	{
		free(line1);
		free(line2);
		free(line3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}