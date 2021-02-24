#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>

int	get_next_line(int fd, char** line);
char* ft_strjoin(char const* s1, char const* s2);
void* ft_memcpy(void* dst, const void* src, size_t n);
size_t	ft_strlen(const char* s);
int ft_strchr_num(const char* s, int c);
char* ft_strdup(const char* s);

#endif
