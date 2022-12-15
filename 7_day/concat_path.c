#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../Libft_42/libft.h"

char	*get_current_position(char *line)
{
	int i = 0;

	if 
}

int main(void)
{
	int n_line = 351;
	char *line;
	char *path;
	int fd = open("cd_cmd.txt", O_RDONLY);
	
	while (n_line > 0)
	{
		line = get_next_line(fd);
		path = get_current_position(line);
		printf("Current line: %s", line);
		free(line);
		n_line--;
	}
	return (0);
}
