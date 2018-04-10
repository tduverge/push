/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   actions.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:20:48 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:05:34 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap_pile(t_list **p)
{
	t_list		*first;
	t_list		*second;

	if (!*p || !(*p)->next)
		return ;
	first = *p;
	second = first->next;
	*p = second;
	first->next = second->next;
	second->next = first;
}

void	push_pile(t_list **dst, t_list **src)
{
	t_list		*dst_t;
	t_list		*src_t;

	if (!*src)
		return ;
	dst_t = *dst;
	src_t = *src;
	*dst = *src;
	*src = src_t->next;
	src_t->next = dst_t;
}

void	rotate_pile(t_list **p)
{
	t_list		*last;
	t_list		*first;

	first = *p;
	if (!first || !(first->next))
		return ;
	last = *p;
	while (last->next)
		last = last->next;
	last->next = first;
	*p = first->next;
	first->next = NULL;
}

void	revrot_pile(t_list **p)
{
	t_list		*first;
	t_list		*last;

	first = *p;
	if (!first || !(first->next))
		return ;
	last = first;
	while (last->next->next)
		last = last->next;
	(*p) = last->next;
	(*p)->next = first;
	last->next = NULL;
}
