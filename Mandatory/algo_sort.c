/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:21 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:50:47 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_a(t_stack **a)
{
	int	l_pos;
	int	s_size;

	s_size = ft_lstsizestack(*a);
	l_pos = lowest_index_pos(a);
	if (l_pos > s_size / 2)
	{
		while (l_pos < s_size)
		{
			rra(a);
			l_pos++;
		}
	}
	else
	{
		while (l_pos > 0)
		{
			ra(a);
			l_pos --;
		}
	}
}

void	cheap_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(a, b, cost_a, cost_b);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	int	s_size;
	int	pushed;
	int	i;

	s_size = ft_lstsizestack(*a);
	pushed = 0;
	i = 0;
	while (s_size > 6 && i < s_size && pushed < s_size / 2)
	{
		if ((*a)->index <= s_size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (s_size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

void	full_sort(t_stack **a, t_stack **b)
{
	move_to_b(a, b);
	three_sort(a);
	while (*b)
	{
		get_t_pos(a, b);
		cost(a, b);
		cheap_move(a, b);
	}
	if (!check_sorted(*a))
		shift_a(a);
}
