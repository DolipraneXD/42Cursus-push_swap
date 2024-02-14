/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:27 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 10:51:47 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstbeforelast(t_stack *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstsizestack(t_stack *lst)
{
	int		i;
	t_stack	*current;

	if (!lst)
		return (0);
	current = lst;
	i = 0;
	while (current != NULL)
	{
		current = current -> next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlaststack(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnewstack(int data)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (newnode == NULL)
		return (NULL);
	newnode -> data = data;
	newnode -> next = NULL;
	return (newnode);
}

void	ft_lstadd_backstack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlaststack(*lst);
	last -> next = new;
}
