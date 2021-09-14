/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:54:24 by indoming          #+#    #+#             */
/*   Updated: 2021/08/12 11:28:56 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_word(char const *s, char c)
{
	int	pos;
	int	count;

	pos = 0;
	count = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] == c)
			pos++;
		else
		{
			count++;
			while (s[pos] && s[pos] != c)
				pos++;
		}
	}
	return (count);
}

char	*ft_make_word(char *word, char const *s, int pos, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		word[i] = s[pos - word_len];
		i++;
		word_len--;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split2(char **word, char const *s, char c, int numw)
{
	int	i;
	int	pos;
	int	word_len;

	i = 0;
	pos = 0;
	word_len = 0;
	while (s[pos] && i < numw)
	{
		while (s[pos] && s[pos] == c)
			pos++;
		while (s[pos] && s[pos] != c)
		{
			pos++;
			word_len++;
		}
		word[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!word[i])
			return (0);
		ft_make_word(word[i], s, pos, word_len);
		word_len = 0;
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		numw;

	if (!s)
		return (0);
	numw = ft_num_word(s, c);
	word = (char **)malloc(sizeof(char *) * (numw + 1));
	if (!word)
		return (0);
	ft_split2(word, s, c, numw);
	return (word);
}
