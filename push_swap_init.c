#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	k;
	int	centerline;

	k = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = k;
		if (k <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		k++;
	}
}

//best match is the smallest-bigger value, if no node is Bigger, best_match is the Smallest node.
//with this function every b nodes gets its target node a.
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	long	best_match;
	t_stack_node	*current_a;
	t_stack_node	*target_node;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

 //Set the cost to push the node
 //from b -> a
 //The cost checks for the relative positions in the stack
 //for every node, setting the respective cost
void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->above_median))
			b->push_cost = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_position;
		else
			b->push_cost += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (stack == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < best_match_value)
		{
			best_match_value = stack->push_cost;
			best_match_node = stack;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = true;
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
