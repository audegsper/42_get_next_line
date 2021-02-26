#include "get_next_line_bonus.h"

int	get_next_line(int fd, char** line)
{
	static char* bkup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				buffer_num;
	int				nl_num;
	char* bkup_temp;

	nl_num = -1;
	if (read(fd, buf, 0) == -1 || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	while (nl_num == -1)
	{
		buffer_num = read(fd, buf, BUFFER_SIZE);
		buf[buffer_num] = '\0';
		if (!(bkup[fd] = ft_strjoin(bkup[fd] ? bkup[fd] : ft_strdup(""), buf)))
			return (-1);
		nl_num = ft_strchr_num(bkup[fd], '\n');
		if (nl_num == -1 && buffer_num == 0)
		{
			if (!(*line = malloc(sizeof(char) * ft_strlen(bkup[fd]) + 1)))
				return (-1);
			*line = ft_memcpy(*line, bkup[fd], ft_strlen(bkup[fd]));
			*(*line + ft_strlen(bkup[fd])) = '\0';
			free(bkup[fd]);
			bkup[fd] = 0;
			return (0);
		}
	}
	if (!(*line = malloc(sizeof(char) * nl_num + 1)))
		return (-1);
	*line = ft_memcpy(*line, bkup[fd], nl_num);
	*(*line + nl_num) = '\0';
	bkup_temp = ft_strdup(bkup[fd] + nl_num + 1);
	free(bkup[fd]);
	bkup[fd] = bkup_temp;
	return (1);
}
