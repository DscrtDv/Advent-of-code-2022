#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line.h"
#include <fcntl.h>

#if !defined(BUFFER_SIZE)
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	static char	remainder_buffer[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char	*temp;
	char	*line;
	ssize_t read_size;

	line = ft_strdup(remainder_buffer);
	while (get_index(line, '\n') == -1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	if (line[0] == '\0' || read_size == -1)
	{
		free(line);
		return (NULL);
	}
	line = get_remainder(line, remainder_buffer);
	return (line);
}

char	*get_remainder(char *line, char *remainder_buffer)
{
	ssize_t	end_index;
	char	*temp;

	end_index = get_index(line, '\n');
	if (end_index != -1)
	{
		ft_strlcpy(remainder_buffer, line + end_index + 1, BUFFER_SIZE + 1);
		temp = line;
		line = (char *)malloc(sizeof(char) * (end_index + 2));
		if (!line)
			return (NULL);
		ft_strlcpy(line, temp, end_index + 2);
		free(temp);
	}
	else
		remainder_buffer[0] = '\0';
	return (line);
}
