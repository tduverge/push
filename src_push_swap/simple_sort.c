/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simple_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:12 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:12 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		need_sort(t_list **a, t_list **b, int len)
{
	t_list		*last;

	len = (int)len;
	while (!ft_lstis_inorder(*a))
	{
		last = *a;
		while (last->next)
			last = last->next;
		if (content(*a) > content((*a)->next))
			apply_actions_pshswp(a, b, SA, "sa\n");
		else if (content(*a) < content(last))
		{
			apply_actions_pshswp(a, b, RRA, "rra\n");
			apply_actions_pshswp(a, b, SA, "sa\n");
		}
		else
			apply_actions_pshswp(a, b, RA, "ra\n");
	}
}

void			only_need_rotate(t_list **a, t_list **b, int len)
{
	t_list		*cursor;
	int			i;
	int			min;

	i = 0;
	min = get_elem_min(*a);
	cursor = *a;
	while (content(cursor) != min)
	{
		cursor = cursor->next;
		i++;
	}
	if (i < len - i)
	{
		while (i--)
			apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else
	{
		i = len - i;
		while (i--)
			apply_actions_pshswp(a, b, RRA, "rra\n");
	}
}

void			simple_sort(t_list **a, t_list **b, int len)
{
	if (!ft_lstis_inorder(*a))
		need_sort(a, b, len);
	if (!ft_lstis_sorted(*a))
		only_need_rotate(a, b, len);
}
