/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:51:18 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:51:18 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

static void		make_len_tab(char const *s, char c, size_t *len_tab)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		k = 0;
		while (s[i] != c && s[i])
		{
			i++;
			k++;
		}
		len_tab[j] = k;
		j++;
	}
}

static void		made_words_in(char const *s, char c, char **res)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		k = 0;
		while (s[i] != c && s[i])
		{
			res[j][k] = s[i];
			i++;
			k++;
		}
		if (s[i])
			res[j][k] = '\0';
		j++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;
	size_t	*len_tab;
	char	**res;

	if (!(s))
		return (NULL);
	nb_words = ft_count_words(s, c);
	if (!(len_tab = (size_t *)malloc(sizeof(size_t) * nb_words)))
		return (NULL);
	make_len_tab(s, c, len_tab);
	if (!(res = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		if (!(res[i] = (char *)malloc(sizeof(char) * (len_tab[i] + 1))))
			return (NULL);
		i++;
	}
	res[nb_words] = NULL;
	made_words_in(s, c, res);
	return (res);
}
