/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:00:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/15 15:36:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		error(ERR_MALLOC);
	new_elem->content = content;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

int			lstsize(t_list **head)
{
	t_list		*cursor;
	int			count;

	count = 0;
	cursor = *head;
	while (cursor)
	{
		cursor = cursor->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = (*alst);
	new->prev = NULL;
	if ((*alst) != NULL)
		(*alst)->prev = new;
	(*alst) = new;
}
