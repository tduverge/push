/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   change_step_2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:04 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:04 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

void			change_step_2(t_list **a, t_list **b)
{
	int		j;

	j = 2;
	if (!ft_stepis_sorted(*a, 2))
		apply_actions_pshswp(a, b, SA, "sa\n");
	while (j--)
		apply_actions_pshswp(a, b, RA, "ra\n");
}
