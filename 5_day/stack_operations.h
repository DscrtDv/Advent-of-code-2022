#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

typedef struct n_stack
{
	char			value;
	struct n_stack	*next;
}				n_stack;

n_stack		*push(n_stack *head, char val);
n_stack		*pop(n_stack *head);
int			isEmpty(n_stack *head);
char		peek(n_stack *head);
n_stack		**stack_innit();

#endif
