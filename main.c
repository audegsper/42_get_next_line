#include "get_next_line.h"


int	main()
{
	char* line;
	int fd;
	int ret;
	fd = open("test01.txt", O_RDONLY);
	if (fd < 0)
	{
		return -1;
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("ret:%d,%s\n", ret, line);
		free(line);
	}
	printf("ret:%d,%s\n", ret, line);
	free(line);
}
