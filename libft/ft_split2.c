/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:30:42 by van               #+#    #+#             */
/*   Updated: 2025/07/22 14:42:21 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	count_str2(char const *s, char *seps)
{
	size_t	count;
	size_t	sep;

	count = 0;
	sep = 1;
	while (*s)
	{
		if (ft_strchr(seps, *s))
			sep = 1;
		else
		{
			if (sep)
				count++;
			sep = 0;
		}
		s++;
	}
	return (count);
}

size_t	slen2(char const *s, char *seps)
{
	size_t	len;

	len = 0;
	while (s[len] && !ft_strchr(seps, s[len]))
		len++;
	return (len);
}

char	**ft_split2(char const *s, char *seps)
{
	char		**arr;
	size_t		cs;
	size_t		i;
	size_t		shift;

	cs = count_str2(s, seps);
	arr = malloc((cs + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = -1;
	shift = 0;
	while (++i < cs)
	{
		while (s[shift] && ft_strchr(seps, s[shift]))
			shift++;
		arr[i] = malloc (slen2 (s + shift, seps) + 1);
		if (arr[i] == NULL)
			return (NULL);
		ft_strlcpy (arr[i], s + shift, slen2 (s + shift, seps) + 1);
		shift = shift + slen2 (s + shift, seps);
	}
	arr[i] = NULL;
	return (arr);
}

void	print_arr(char **arr)
{
	int	i;
	int	len;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i])
	{
		len = ft_strlen(arr[i]);
		write(1, arr[i], len);
		if (arr[i][len - 1] != '\n')
			write (1, "\n", 1);
	}
}

// #include <stdlib.h> // malloc, NULL

// // Aide à libérer le tableau en cas d'erreur
// static char **free_all(char **arr, size_t i)
// {
//     while (i > 0)
//         free(arr[--i]);
//     free(arr);
//     return (NULL);
// }

// char **ft_split2(const char *s, char *seps)
// {
//     char        **arr;
//     size_t      words_count;
//     size_t      i = 0;
//     size_t      shift = 0;
//     size_t      len;

//     if (!s || !seps)
//         return (NULL);

//     words_count = count_str2(s, seps);
//     arr = malloc((words_count + 1) * sizeof(char *));
//     if (!arr)
//         return (NULL);

//     while (i < words_count)
//     {
//         while (s[shift] && ft_strchr(seps, s[shift])) // skip seps
//             shift++;

//         len = slen2(s + shift, seps);
//         arr[i] = malloc(len + 1);
//         if (!arr[i])
//             return free_all(arr, i);

//         ft_strlcpy(arr[i], s + shift, len + 1);
//         shift += len;
//         i++;
//     }
//     arr[i] = NULL;
//     return arr;
// }
