/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 16:46:59 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 21:15:33 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		sort_z(t_list **a, t_list **b, int *step)
{
	apply_actions_pshswp(a, b, PB, "pb\n");
	apply_actions_pshswp(a, b, SA, "sa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	apply_actions_pshswp(a, b, PA, "pa\n");
	change_step_2(a, b, step, 3);
}

static void		sort_x(t_list **a, t_list **b, int *step)
{
	apply_actions_pshswp(a, b, RA, "ra\n");
	change_step_2(a, b, step, 3);
}

static void		sort_y(t_list **a, t_list **b, int *step)
{
	apply_actions_pshswp(a, b, SA, "sa\n");
	apply_actions_pshswp(a, b, RA, "ra\n");
	change_step_2(a, b, step, 3);
}

void			sort_3(t_list **a, t_list **b, int *step)
{
	int		x;
	int		y;
	int		z;
	int		min;

	x = content(*a);
	y = content((*a)->next);
	z = content((*a)->next->next);
	if (x < y)
		min = x < z ? x : z;
	else
		min = y < z ? y : z;
	if (z == min)
		sort_z(a, b, step);
	else if (x == min)
		sort_x(a, b, step);
	else
		sort_y(a, b, step);
}
