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

int		detect_option(char **av, t_param *p)
{
	int		i;
	int		j;

	i = 1;
	while (av[i][0] == '-' && !ft_isdigit(av[i][1]))
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] == 'v')
				p->v = 1;
			else if (av[i][j] == 'g')
				p->g = 1;
			else
			{
				ft_putstr("Invalid Option. Only v or g are support.\n");
				exit(2);
			}
			j++;
		}
		j == 1 ? ft_putstr("Invalid Option. Only v or g are support.\n") : 0;
		j == 1 ? exit(2) : 0;
		i++;
	}
	return (i);
}

int				main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*commands;
	t_param	p;

	p.v = 0;
	p.g = 0;
	p.stop = 1;
	a = NULL;
	b = NULL;
	commands = NULL;
	if (ac < 2)
		return (0);
	i = ac - 1;
	while (i >= detect_option(av, &p))
		if (not_format(&a, av[i--]))
			return (ex_prg(1, &a, &b, &commands));
	commands = command_list();
	p.commands = commands;
	if (p.v)
		print_lsts(200, a, b);
	p.g ? option_g(&a, &b, &p) : not_option_g(&a, &b, &p);
	return (ex_prg(0, &a, &b, &commands));
}
