/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simple_sort_b.c                                  .::    .:/ .      .::   */
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
	while (!ft_lstis_inorder_b(*b))
	{
		last = *a;
		while (last->next)
			last = last->next;
		if (content(*b) < content((*b)->next))
			apply_actions_pshswp(a, b, SB, "sb\n");
		else if (content(*b) > content(last))
		{
			apply_actions_pshswp(a, b, RRB, "rrb\n");
			apply_actions_pshswp(a, b, SB, "sb\n");
		}
		else
			apply_actions_pshswp(a, b, RB, "rb\n");
	}
}

static void		only_need_rotate_b(t_list **a, t_list **b, int len)
{
	t_list		*cursor;
	int			i;
	int			max;

	i = 0;
	max = get_elem_max(*b);
	cursor = *b;
	while (content(cursor) != max)
	{
		cursor = cursor->next;
		i++;
	}
	if (i < len - i)
	{
		while (i--)
			apply_actions_pshswp(a, b, RB, "rb\n");
	}
	else
	{
		i = len - i;
		while (i--)
			apply_actions_pshswp(a, b, RRB, "rrb\n");
	}
}

void			simple_sort_b(t_list **a, t_list **b, int len)
{
	if (!ft_lstis_inorder_b(*b))
		need_sort(a, b, len);
	if (!ft_lstis_sorted_b(*b))
		only_need_rotate_b(a, b, len);
}
