/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:01:27 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/25 17:53:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_FUNC_H
# define LST_FUNC_H

# include "minirt.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					lstsize(t_list **head);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
#endif
