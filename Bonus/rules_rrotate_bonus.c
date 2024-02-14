/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:56 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/08 16:10:37 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	r_rotate_bonus(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*bend;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	end = ft_lstlaststack(*stack);
	bend = ft_lstbeforelast(*stack);
	tmp = *stack;
	*stack = end;
	(*stack)->next = tmp;
	bend->next = NULL;
}

void	rra_bonus(t_stack **a)
{
	r_rotate_bonus(a);
}

void	rrb_bonus(t_stack **b)
{
	r_rotate_bonus(b);
}

void	rrr_bonus(t_stack **a, t_stack **b)
{
	r_rotate_bonus(a);
	r_rotate_bonus(b);
}
