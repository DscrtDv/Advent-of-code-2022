#ifndef RPS_H
# define RPS_H

# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct
{
	char	shape;
	int		value;
	char	win;
	char	draw;
	char	loose;
} choice;

//utils
size_t	line_counter(char *file);

#endif
