/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:52:06 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:53:46 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		l_index;
	int		l_pos;

	tmp = *stack;
	l_index = INT_MAX;
	get_position(stack);
	l_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < l_index)
		{
			l_index = tmp->index;
			l_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (l_pos);
}

int	highest_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	three_sort(t_stack **stack)
{
	int	h_i;

	if (check_sorted(*stack))
		return ;
	h_i = highest_index(*stack);
	if ((*stack)->index == h_i)
		ra(stack);
	else if ((*stack)->next->index == h_i)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
