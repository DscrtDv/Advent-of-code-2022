#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../Libft_42/libft.h"

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

int		get_part1(int min1, int max1, int min2, int max2)
{
	if (min1 <= min2 && max1 >= max2)
		return (1);
	else if (min2 <= min1 && max2 >= max1)
		return (1);
	return (0);
}

int		get_part2(int min1, int max1, int min2, int max2)
{
	if ((min1 <= min2 && max1 >= min2) || (max1 <= max2 && max1 >= min2))
		return (1);

	else if ((min2 <= min1 && max2 >= min1) || (max2 <= max1 && max2 >= min1))
		return (1);

	return (0);
}

int		range_compare(char **pair1, char **pair2, int part_2)
{
	int	min1, max1, min2, max2;
	min1 = ft_atoi(pair1[0]);
	max1 = ft_atoi(pair1[1]);
	min2 = ft_atoi(pair2[0]);
	max2 = ft_atoi(pair2[1]);

	if (part_2)
		return (get_part2(min1, max1, min2, max2));
	return (get_part1(min1, max1, min2, max2));

}

void	free_array(void **array, int len)
{
	int i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int		compute_arrays(char *line)
{
	int		result = 0;
	char	**temp_array;
	char	**pair1;
	char	**pair2;
	
	temp_array = ft_split(line, ',');
	pair1 = ft_split(temp_array[0], '-');
	pair2 = ft_split(temp_array[1], '-');
	free_array((void**)temp_array, 2);
	
	result += range_compare(pair1, pair2, 1);
	free_array((void**)pair1, 2);
	free_array((void**)pair2, 2);
	
	return (result);
}

int main(void)
{
	int result = 0;
	char *line;
	char *file = "input.txt";
	size_t	line_count = line_counter(file);
	int fd = open(file, O_RDONLY);

	while (line_count > 0)
	{
		line = get_next_line(fd);
		result += compute_arrays(line);
		free(line);
		line_count--;
	}
	close(fd);
	printf("total of groups overlapping: %d \n", result);
	return (0);
}
