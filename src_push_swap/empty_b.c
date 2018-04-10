/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   empty_b.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 15:51:13 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 16:44:31 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		len_2(t_list **a, t_list **b)
{
	if (content(*b) > content((*b)->next))
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		return ;
	}
	apply_actions_pshswp(a, b, PA, "pa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	apply_actions_pshswp(a, b, PA, "pa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
}

static void		len_3_3(t_list **a, t_list **b)
{
	apply_actions_pshswp(a, b, PA, "pa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	if (content(*b) > content((*b)->next))
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
}

static void		len_3_2(t_list **a, t_list **b, int max)
{
	apply_actions_pshswp(a, b, PA, "pa\n");
	if (content(*b) == max)
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, SA, "sa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
}

static void		len_3_1(t_list **a, t_list **b, int max)
{
	max = get_elem_max(*b);
	if (content(*b) == max)
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		if (content(*b) > content((*b)->next))
		{
			apply_actions_pshswp(a, b, PA, "pa\n");
			apply_actions_pshswp(a, b, PA, "pa\n");
			apply_actions_pshswp(a, b, RA, "ra\n");
			apply_actions_pshswp(a, b, RA, "ra\n");
		}
		else
		{
			apply_actions_pshswp(a, b, PA, "pa\n");
			apply_actions_pshswp(a, b, RA, "ra\n");
			apply_actions_pshswp(a, b, PA, "pa\n");
			apply_actions_pshswp(a, b, RA, "ra\n");
		}
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else if (content(*b) == max - 1)
		len_3_2(a, b, max);
	else
		len_3_3(a, b);
}

void			empty_b(t_list **a, t_list **b, int *step, int j)
{
	int		len;

	len = ft_lstlen(*b);
	if (len == 1)
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else if (len == 2)
		len_2(a, b);
	else if (len == 3)
		len_3_1(a, b, 0);
	step[j] = 0;
	quick_a(a, b, step, 1);
}
