/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_io.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:22:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:22:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_is_sorted(t_list *pile)
{
	t_list		*cur;
	t_list		*ahead;

	cur = pile;
	if (!cur)
		return (0);
	if (!(cur->next))
		return (1);
	ahead = cur->next;
	while (ahead && (*(int *)(cur->content) < *(int *)(ahead->content)))
	{
		cur = ahead;
		ahead = ahead->next;
	}
	if (!ahead)
		return (1);
	return (0);
}

int		is_valid_input(char *cmd)
{
	int		len;

	if (!ft_strcmp("v", cmd))
		return (200);
	else if (!ft_strcmp("rra", cmd) || !ft_strcmp("rrb", cmd) ||
			!ft_strcmp("rrr", cmd))
		return (30 + (cmd[2] - 'a') % 5);
	if ((len = ft_strlen(cmd)) != 2)
		return (-1);
	if (cmd[0] == 's' && (cmd[1] == 'a' || cmd[1] == 'b' || cmd[1] == 's'))
		return ((cmd[1] - 'a') % 4);
	if (cmd[0] == 'p' && (cmd[1] == 'a' || cmd[1] == 'b'))
		return (10 + (cmd[1] - 'a') % 10);
	if (cmd[0] == 'r' && (cmd[1] == 'a' || cmd[1] == 'b' || cmd[1] == 'r'))
		return (20 + (cmd[1] - 'a') % 5);
	return (-1);
}
