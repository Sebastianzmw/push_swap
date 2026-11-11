#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

//search for last node and append
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack_node *stack)
{
	int	k;

	k = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		k++;
		stack = stack->next;
	}
	return (k);
}

t_stack_node	*find_smallest(t_stack_node *a)
{
	long	smallest;
	t_stack_node	*smallest_node;

	if (a == NULL)
		return (NULL);
	smallest = LONG_MAX;	
	while (a)
	{
		if (a->value < smallest)
		{
			smallest = a->value;
			smallest_node = a;
		}
		a = a->next;
	}
	return (smallest_node);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
