#include <stddef.h>
#include <stdio.h>

size_t	line_counter(char* file)
{
	FILE	*fileptr;
	size_t	line_count = 0;
	size_t	char_count = 0;
	char	current;

	if (!file)
		return (0);
	fileptr = fopen(file, "r");
	if (!fileptr)
		return (-1);
	current = getc(fileptr);
	while (current != EOF)
	{
		if (current == '\n')
		{
			line_count++;
		}
		current = getc(fileptr);
		char_count++;
	}
	fclose(fileptr);
	return (line_count);
}

