/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   change_step_3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:04 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:04 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		sort_x(t_list **a, t_list **b)
{
	apply_actions_pshswp(a, b, RA, "ra\n");
	change_step_2(a, b);
}

static void		sort_y(t_list **a, t_list **b)
{
	apply_actions_pshswp(a, b, SA, "sa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	change_step_2(a, b);
}

static void		sort_z(t_list **a, t_list **b, int *nb)
{
	apply_actions_pshswp(a, b, PB, "pb\n");
	apply_actions_pshswp(a, b, SA, "sa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	if (nb[1] == nb[2] + 1)
	{
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
	else
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
	}
}

void			change_step_3(t_list **a, t_list **b)
{
	int		nb[3];
	int		min;

	nb[0] = content(*a);
	nb[1] = content((*a)->next);
	nb[2] = content((*a)->next->next);
	if (nb[0] < nb[1])
		min = nb[0] < nb[2] ? nb[0] : nb[2];
	else
		min = nb[1] < nb[2] ? nb[1] : nb[2];
	if (min == nb[0])
		sort_x(a, b);
	else if (min == nb[1])
		sort_y(a, b);
	else if (min == nb[2])
		sort_z(a, b, nb);
}
