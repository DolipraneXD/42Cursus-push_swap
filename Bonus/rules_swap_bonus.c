/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:58 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/08 14:33:20 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_bonus(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	sa_bonus(t_stack **a)
{
	swap_bonus(*a);
}

void	sb_bonus(t_stack **b)
{
	swap_bonus(*b);
}

void	ss_bonus(t_stack **a, t_stack **b)
{
	swap_bonus(*a);
	swap_bonus(*b);
}
