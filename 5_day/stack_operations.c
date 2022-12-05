#include <stdio.h>
#include <stdlib.h>
#include "stack_operations.h"

n_stack		*push(n_stack *head, char val)
{
	n_stack	*ptr = (n_stack*)malloc(sizeof(n_stack));
	if (!ptr)
		return (NULL);
	if (head == NULL)
	{
		ptr->value = val;
		ptr->next = NULL;
		head = ptr;
	}
	else 
	{
		ptr->value = val;
		ptr->next = head;
		head = ptr;
		//printf("current val: %c // previous val: %c \n", head->value, head->next->value);
	}
	return (head);
}

n_stack		*pop(n_stack *head)
{
	char	val;
	n_stack *ptr;
	if (head == NULL)
		printf("Underflow state: nothing to be removed.\n");
	else
	{
		val = head->value;
		ptr = head;
		head = head->next;
		free(ptr);
		return (head);
	}
	return (NULL);
}

int		isEmpty(n_stack *head)
{
	if (head == NULL)
		return (1);
	return (0);
}

char	peek(n_stack *head)
{
	if (!isEmpty(head))
		return head->value;
	return (0);
}

static n_stack		*populate_stack(n_stack *stack, char *str)
{
	int i = 0;
	while (str[i])
	{
		stack = push(stack, str[i]);
		i++;
	}
	return (stack);
}

static n_stack		*populate_array(n_stack *array, int i)
{
	char *s1 = "SZPDLBFC";
	char *s2 = "NVGPHWB";
	char *s3 = "FWBJG";
	char *s4 = "GJNFLWCS";
	char *s5 = "WJLTPMSH";
	char *s6 = "BCWGFS";
	char *s7 = "HTPMQBW";
	char *s8 = "FSWT";
	char *s9 = "NCR";

	switch(i)
	{
		case 0:
			return populate_stack(array, s1);
		case 1:
			return populate_stack(array, s2);
		case 2:
			return populate_stack(array, s3);
		case 3:
			return populate_stack(array, s4);
		case 4:
			return populate_stack(array, s5);
		case 5:
			return populate_stack(array, s6);
		case 6:
			return populate_stack(array, s7);
		case 7:
			return populate_stack(array, s8);
		case 8:
			return populate_stack(array, s9);
	}
	return (NULL);
}

static n_stack		**create_stack_array(int len)
{
	int i = 0;
	char c = 'A';
	n_stack	**array =  (n_stack**)malloc(sizeof(n_stack*) * len);
	if (!array)
		return (NULL);
	while (i < len)
	{
		array[i] = populate_array(array[i], i);
		if (!array[i])
			printf("shits fucking up\n");
		i++;
	}
	return (array);
}

n_stack 	**stack_innit()
{
	n_stack	**array;
	int i = 0;
	array = create_stack_array(9);
	return (array);
}
