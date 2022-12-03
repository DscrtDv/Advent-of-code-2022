#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

static char *ft_strtrim(char *str, char to_trim)
{
	int i = 0;

	if (!str)
		return (NULL);
	while (str[i] != to_trim)
		i++;
	str[i] = '\0';
	return (str);
}

int		get_max(int *array)
{
	int i = 0;
	int temp_i = 0;
	int temp = 0;

	while (i < 265)
	{
		if(array[i] > temp)
		{
			temp = array[i];
			temp_i = i;
		}
		i++;
	}
	array[temp_i] = 0;
	return (temp);
}

int main(void)
{
	char *line, *temp_line = NULL;
	int counter = 0;
	int array[265];
	unsigned int current = 0;
	unsigned int temp_digit = 0;
	int i = 0;
	int fd = open("input.txt", O_RDONLY);

	while (i < 2270)
	{
		line = get_next_line(fd);

		if (ft_strlen(line) > 1)
		{
			line = ft_strtrim(line, '\n');
			temp_digit += ft_atoi(line);
			free(line);
		}				
		else
		{	
			
			/*
			if (current < temp_digit)
			{
				current = temp_digit;
				printf("___________________________________________________\n");	
				printf("New maximum at line %d reached: %d \n",i, current);
			}
			temp_digit = 0;
			*/
			array[counter] = temp_digit;
			temp_digit = 0;
			counter++;
		}
		i++;
	}
	printf("elves counter: %d \n", counter);
	printf("Max 1 is: %d \n", get_max(array));
	printf("Max 2 is: %d \n", get_max(array));
	printf("Max 3 is: %d \n", get_max(array));
	return (0);
}
