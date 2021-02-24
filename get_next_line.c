#include "get_next_line.h"

int	get_next_line(int fd, char** line)
{
	static char* bkup;
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
		if (!(bkup = ft_strjoin(bkup ? bkup : ft_strdup(""), buf)))
			return (-1);
		nl_num = ft_strchr_num(bkup, '\n');
		if (nl_num == -1 && buffer_num == 0)
		{
			if (!(*line = malloc(sizeof(char) * ft_strlen(bkup))))
				return (-1);
			*line = ft_memcpy(*line, bkup, ft_strlen(bkup));
			*(*line + ft_strlen(bkup)) = '\0';
			free(bkup);
			bkup = 0;
			return (0);
		}
	}
	if (!(*line = malloc(sizeof(char) * nl_num)))
		return (-1);
	*line = ft_memcpy(*line, bkup, nl_num);
	*(*line + nl_num) = '\0';
	bkup_temp = ft_strdup(bkup + nl_num + 1);
	free(bkup);
	bkup = bkup_temp;
	return (1);
}
