/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:18:05 by van               #+#    #+#             */
/*   Updated: 2025/09/01 17:25:09 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// takes a ptr to a string,
//  returns true if the ptr points on a number (no sign, no dot)
bool	is_number(char *s)
{
	if (!s || !ft_isdigit(*s))
		return (false);
	while (*s && ft_isdigit(*s))
		s++;
	if (*s && !ft_isspace(*s))
		return (false);
	return (true);
}

// returns a ptr to the start of the nth word in s, else NULL
char	*get_nth_word(char *s, int n)
{
	char	*start;
	bool	new;

	if (s == NULL || n <= 0)
		return (NULL);
	new = true;
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			if (new)
			{
				start = s;
				new = false;
				if (--n == 0)
					return (start);
			}
		}
		else
			new = true;
		s++;
	}
	return (NULL);
}

int	count_words(char *s)
{
	int		count;
	bool	new;

	count = 0;
	new = true;
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			if (new)
			{
				count++;
				new = false;
			}
		}
		else
			new = true;
		s++;
	}
	return (count);
}

bool	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

char	*get_next_word(char *s)
{
	bool	new;

	new = ft_isspace(*s);
	while (*s)
	{
		if (!new && ft_isspace(*s))
			new = true;
		else if (new && !ft_isspace(*s))
			return (s);
		s++;
	}
	return (NULL);
}
