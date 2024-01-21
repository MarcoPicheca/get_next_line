/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:27:25 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/05 17:24:26 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp;
	size_t	i;
	size_t	n;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (size > 0)
	{
		i = 0;
		tmp = (char *)ptr;
		if ((size * nmemb) == 0)
			return (NULL);
		n = size * nmemb;
		while (n > i)
		{
			*tmp = 0;
			tmp++;
			n--;
		}
	}
	return (ptr);
}

char	*ft_strchr(char *buff, int n)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	if (n == '\0')
		return ((char *)&buff[ft_strlen(buff, 0)]);
	while (buff[i])
	{
		if (buff[i] == (char) n)
			return ((char *)&buff[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s, int flag)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else if (flag == 1)
	{
		while (s[i] != '\n' && s[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	*newstr;

	if (!s1 && !s2)
		return (NULL);
	else
	{
		i = 0;
		k = 0;
		j = 0;
		newstr = (char *)ft_calloc((ft_strlen(s1, 0)
					+ ft_strlen(s2, 0) + 1), 1);
		if (!newstr)
			return (NULL);
		while (s1[i])
			newstr[j++] = s1[i++];
		while (s2[k] != '\0')
			newstr[j++] = s2[k++];
		newstr[j++] = s2[k++];
		free(s1);
		return (newstr);
	}
	return (NULL);
}

char	*ft_strjoin(char *buff, char *tmp)
{
	if (!buff)
		buff = ft_calloc(1, 1);
	if (!buff || !tmp || (!buff[0] && !tmp[0]))
	{
		free(tmp);
		free(buff);
		return (NULL);
	}
	return (ft_strjoin2(buff, tmp));
}
