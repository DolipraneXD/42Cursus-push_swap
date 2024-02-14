/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:53 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/08 16:10:54 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_bonus(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	end = ft_lstlaststack(*stack);
	tmp->next = NULL;
	end->next = tmp;
}

void	ra_bonus(t_stack **a)
{
	rotate_bonus(a);
}

void	rb_bonus(t_stack **b)
{
	rotate_bonus(b);
}

void	rr_bonus(t_stack **a, t_stack **b)
{
	rotate_bonus(a);
	rotate_bonus(b);
}
