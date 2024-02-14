/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:16 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:53:23 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

void	rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(a);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(b);
			(*cost_b)++;
		}
	}
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		r_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}
