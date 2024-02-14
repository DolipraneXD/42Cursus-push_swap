/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:38 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:52:26 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size == 2 && !check_sorted(*a))
		sa(a);
	else if (stack_size == 3)
		three_sort(a);
	else if (stack_size > 3 && !check_sorted(*a))
		full_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		s_size;

	if (ac < 2)
		return (0);
	b = NULL;
	a = buildstack(ac, av);
	s_size = ft_lstsizestack(a);
	assing_index(a, s_size + 1);
	push_swap(&a, &b, s_size);
	free_everything(&a, &b);
}
