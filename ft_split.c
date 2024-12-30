/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:27:22 by aboukezi          #+#    #+#             */
/*   Updated: 2024/12/29 18:59:09 by aelaen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count(char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	if (!s)
		return (0);
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static void	subtab(char *strtab, char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		strtab[i] = s[i];
		i++;
	}
	strtab[i] = '\0';
}

static void	write_tabs(char **tab, char *s, char c)
{
	size_t	lettercount;
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[word])
	{
		lettercount = 0;
		while (s[word + lettercount] && s[word + lettercount] != c)
			lettercount++;
		if (lettercount > 0)
		{
			tab[i] = (char *)malloc(sizeof(char) * (lettercount + 1));
			if (!tab[i])
				free(tab[i]);
			subtab (tab[i], s + word, c);
			word += lettercount;
			i++;
		}
		else
			word++;
	}
	tab[i] = 0;
}

char	**ft_split(char *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	write_tabs (tab, s, c);
	return (tab);
}
