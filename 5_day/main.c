#include "stack_operations.h"
#include "../gnl/get_next_line.h"
#include "../Libft_42/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

n_stack		**send_stack_instruction(n_stack **stacks, int move, int from, int to)
{
	int	moved = 0;
	int a_moved = 0;
	char val;

	while (moved < move)
	{
		if (!isEmpty(stacks[from]))
		{
			val = peek(stacks[from]);
			//printf("fetching %c \n", val);
			stacks[from] = pop(stacks[from]);
			//printf("Popping from stack %i \n", from+1);
			stacks[to] = push(stacks[to], val);
			//printf("added %c to stack %d\n", peek(stacks[to]), to+1);
			a_moved++;
		}
		moved++;
	}
	printf("moved %d items / %d items from %d to %d\n", a_moved, move, from+1, to+1);
	return (stacks);
}

n_stack		**part_ii(n_stack **stacks, int move, int from, int to)
{
	/*
	char *block = (char*)malloc(sizeof(char) * move);
	if (!block)
		return (NULL);
	*/
	char block[200];
	int len = move;
	block[move] = '\0';
	while(len)
	{
		block[len-1] = peek(stacks[from]);
		stacks[from] = pop(stacks[from]);
		len--;
	}
	len = 0;
	while (len < move)
	{
		stacks[to] = push(stacks[to], block[len]);
		len++;
	}
	printf("%s \n", block);
	return (stacks);
}

n_stack		**process_line(n_stack **stacks, char *line)
{
	int i = 0, command = 0;
	int	move = 0;
	int from = 0;
	int to = 0;
	
	while (line[i])
	{
		if (ft_isdigit(line[i]) && command < 3)
		{
			if (command == 0)
			{
				if(ft_isdigit(line[i+1]))
				{
					char temp[3];
					ft_strlcpy(temp, line+i, 3);
					move = ft_atoi(temp);
					i++;
				}
				else {
					move = (int)line[i] - '0';
				}
			}
			else if (command == 1)
				from = (int)line[i] - '0' - 1;
			else if (command == 2)
				to = (int)line[i] - '0' - 1;
			command++;
		}
		i++;
	}
	//stacks = send_stack_instruction(stacks, move, from, to);
	stacks = part_ii(stacks, move, from, to);
	return (stacks);
}

int	main(void)
{
	n_stack	**stacks = stack_innit();
	int fd = open("input.txt", O_RDONLY);
	char *line;
	int i = 0;

	while (i < 503)
	{
		line = get_next_line(fd);
		stacks = process_line(stacks, line);
		free(line);
		printf("%d line processed-------------------\n", i+1);
		i++;
	}
	printf("The top of each stacks produces the message:\n");
	for (int j = 0; j < 9; j++)
		printf("%c ", peek(stacks[j]));
	return (0);
}
