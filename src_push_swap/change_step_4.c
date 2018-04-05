/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   change_step_4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:04 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:04 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		first_case(t_list **a, t_list **b, int min)
{
	if (content((*a)->next) == min)
		apply_actions_pshswp(a, b, SA, "sa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	change_step_3(a, b);
}

static void		second_case(t_list **a, t_list **b, int max, int min)
{
	if (content((*a)) == max - 1 || content((*a)->next) == max - 1)
		apply_actions_pshswp(a, b, PB, "pb\n");
	else
	{
		if (content((*a)->next) == max)
			apply_actions_pshswp(a, b, SA, "sa\n");
		apply_actions_pshswp(a, b, PB, "pb\n");
		change_step_3(a, b);
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		return ;
	}
	apply_actions_pshswp(a, b, PB, "pb\n");
	if (content(*a) != min && content(*b) != max)
		apply_actions_pshswp(a, b, SS, "ss\n");
	else if (content(*a) != min)
		apply_actions_pshswp(a, b, SA, "sa\n");
	else if (content(*b) != max)
		apply_actions_pshswp(a, b, SB, "sb\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	apply_actions_pshswp(a, b, PA, "pa\n");
	apply_actions_pshswp(a, b, PA, "pa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
}

static void		third_case(t_list **a, t_list **b, int max)
{
	apply_actions_pshswp(a, b, PB, "pb\n");
	apply_actions_pshswp(a, b, PB, "pb\n");
	if (content(*a) == max)
		apply_actions_pshswp(a, b, SA, "sa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	if (content(*b) < content((*b)->next))
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	apply_actions_pshswp(a, b, RA, "ra\n");
}

void			change_step_4(t_list **a, t_list **b, int treat)
{
	int			max;
	int			min;
	t_list		*tmp;

	tmp = *a;
	max = content(tmp);
	min = content(tmp);
	while (treat--)
	{
		if (content(tmp) > max)
			max = content(tmp);
		if (content(tmp) < min)
			min = content(tmp);
		tmp = tmp->next;
	}
	if (content(*a) == min || content((*a)->next) == min)
		first_case(a, b, min);
	else if (content(*a) == max || content((*a)->next) == max)
		second_case(a, b, max, min);
	else
		third_case(a, b, max);
}
