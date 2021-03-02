#include "get_next_line_bonus.h"

int	write_line(char** line, int length, char** bkup, int buffer_num)
{
	int				nl_num;
	char*			bkup_temp;

	nl_num = ft_strchr_num(*bkup, '\n');
	if (!(*line = malloc(sizeof(char) * length + 1)))
		return (-1);
	*line = ft_memcpy(*line, *bkup, length);
	*(*line + length) = '\0';
	if (nl_num == -1 && buffer_num == 0)
	{
		free(*bkup);
		*bkup = 0;
		return (0);
	}
	bkup_temp = ft_strdup(*bkup + length + 1);
	free(*bkup);
	*bkup = bkup_temp;
	return (1);
}

int	get_next_line(int fd, char** line)
{
	static char* bkup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				buffer_num;
	int				nl_num;

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
			return (write_line(line, ft_strlen(bkup[fd]), &bkup[fd], buffer_num));
		}
	}
	return (write_line(line, nl_num, &bkup[fd], buffer_num));
}
