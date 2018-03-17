/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:22:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:22:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int		not_format(t_list **pile, char *arg)
{
	if (not_numeric(pile, arg))
		return (1);
	if (got_doubles(pile))
		return (1);
	return (0);
}

static t_list	*command_list(void)
{
	t_list		*commands;
	char		*command;
	int			action;

	commands = NULL;
	while (get_next_line(0, &command))
	{
		if ((action = is_valid_input(command)) != -1)
		{
			if (!commands)
				commands = ft_lstnew((int *)&action, sizeof(int *));
			else
				ft_lstpush(&commands, ft_lstnew((int *)&action, sizeof(int *)));
			free(command);
		}
		else
		{
			free(command);
			ft_putstr("Error\n");
		}
	}
	return (commands);
}

static int		ex_prg(int err, t_list **a, t_list **b, t_list **cmds)
{
	ft_lstdel(a, ft_del);
	ft_lstdel(b, ft_del);
	ft_lstdel(cmds, ft_del);
	if (!err)
		return (0);
	else
		ft_putstr("Error\n");
	return (-1);
}

int				main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*commands;
	char	v;

	v = 0;
	a = NULL;
	b = NULL;
	commands = NULL;
	if (ac < 2)
		return (0);
	if (!strcmp(av[1], "-v"))
		v = 1;
	i = ac - 1;
	while (i >= 1 + v)
		if (not_format(&a, av[i--]))
			return (ex_prg(1, &a, &b, &commands));
	commands = command_list();
	if (v)
		print_lsts(200, a, b);
	apply_actions(&a, &b, commands, v);
	(ft_is_sorted(a) && !b) ? printf("OK\n") : printf("KO\n");
	return (ex_prg(0, &a, &b, &commands));
}
