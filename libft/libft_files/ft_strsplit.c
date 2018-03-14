/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:12 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 09:28:31 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

static size_t	ft_nb_words(char const *str, char c)
{
	size_t	i;
	size_t	nbw;

	i = 0;
	nbw = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			nbw++;
		}
	}
	return (nbw);
}

static size_t	ft_len_pt(char const *str, int j, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && j != 0 && str[i])
			i++;
		while (str[i] != c && j == 0 && str[i])
		{
			i++;
			k++;
		}
		j--;
	}
	return (k);
}

static char		*ft_unconcat(char const *str, int length, int j, char c)
{
	char	*render;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!(render = malloc(sizeof(char) * length + 1)))
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (j == 0)
			while (str[i] != c && str[i] != '\0')
			{
				render[k] = str[i];
				k++;
				i++;
			}
		while (str[i] != c && str[i] != '\0')
			i++;
		j--;
	}
	render[k] = '\0';
	return (render);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**final;
	size_t	nb_words;
	size_t	i;
	size_t	length;

	if (!str)
		return (0);
	i = 0;
	nb_words = ft_nb_words(str, c);
	if (!(final = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		length = ft_len_pt(str, i, c);
		final[i] = ft_unconcat(str, length, i, c);
		i++;
	}
	final[i] = NULL;
	return (final);
}
