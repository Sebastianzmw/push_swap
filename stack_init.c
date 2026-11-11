#include "push_swap.h"

//converting str to long(int value)
static long	ft_atol(const char *str)
{
	int		neg;
	long	num;
	int		k;

	k = 0;
	num = 0;
	neg = 1;
	while (str[k] && (str[k] == ' ' || (str[k] >= 9 && str[k] <= 13)))
		k++;
	if (str[k] == '+')
		k++;
	else if (str[k] == '-')
	{
		neg *= -1;
		k++;
	}
	while (str[k] >= '0' && str[k] <= '9')
	{
		num = (num * 10) + (str[k] - '0');
		k++;
	}
	return (num * neg);
}
/* 
create the stack with command line values

check following
-overflow|underflow
-duplicate values
-syntax errors

🏁 Flag is useful cause if true, i have the argv in the HEAP to free */

void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		k;

	k = 0;
	while (argv[k])
	{
		if (error_syntax(argv[k]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[k]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		k++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
