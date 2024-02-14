/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:24 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:51:26 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = ft_lstsizestack(tmp_a);
	size_b = ft_lstsizestack(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

int	get_target(t_stack **a, int b_i, int target_i, int target_pos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > b_i && tmp->index < target_i)
		{
			target_i = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_i != INT_MAX)
		return (target_pos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < target_i)
		{
			target_i = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_t_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		t_pos;

	tmp = *b;
	get_position(a);
	get_position(b);
	t_pos = 0;
	while (tmp)
	{
		t_pos = get_target(a, tmp->index, INT_MAX, t_pos);
		tmp->target_pos = t_pos;
		tmp = tmp->next;
	}
}

void	assing_index(t_stack *a, int s_size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	while (--s_size > 0)
	{
		tmp = a;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->data == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->data > value && tmp->index == 0)
			{
				value = tmp->data;
				highest = tmp;
				tmp = a;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = s_size;
	}
}
