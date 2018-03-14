/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simple_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/04 11:09:46 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 12:50:14 by kbedene     ###    #+. /#+    ###.fr     */
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
