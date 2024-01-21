/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:03 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/07 18:04:52 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	rd_check(int i, char *buff, char *tmp)
{
	if (i < 0)
	{
		free(tmp);
		free(buff);
		return (0);
	}
	return (1);
}

char	*ft_read(char *buff, int fd)
{
	int		i;
	char	*tmp;

	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 1;
	while (!ft_strchr(buff, '\n') && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (rd_check(i, buff, tmp) == 0)
			return (NULL);
		tmp[i] = 0;
		buff = ft_strjoin(buff, tmp);
		if (!buff)
		{
			free(buff);
			return (NULL);
		}
	}
	free(tmp);
	return (buff);
}

char	*next_line(char *buff)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(buff, 1);
	tmp = (char *)ft_calloc(i + 2, sizeof(char));
	if (!tmp)
	{
		free(buff);
		return (NULL);
	}
	j = 0;
	while (buff[j] != '\n' && buff[j] != '\0' && j < i)
	{
		tmp[j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
		tmp[j++] = '\n';
	return (tmp);
}

char	*cut_line(char *buff)
{
	char	*new;
	int		i;
	int		j;
	int		z;

	i = ft_strlen(buff, 0);
	j = ft_strlen(buff, 1);
	new = (char *)ft_calloc(i - j + 1, sizeof(char));
	if (!new)
	{
		free(buff);
		return (NULL);
	}
	j++;
	z = 0;
	while (j < i && buff[j] != '\0')
		new[z++] = buff[j++];
	free(buff);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff[fd] = ft_read(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	line = next_line(buff[fd]);
	buff[fd] = cut_line(buff[fd]);
	if (!buff[fd] || !line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int main()
// {
// 	int fd_0 = open("./prova0.txt", O_RDONLY);
// 	int fd_1 = open("./prova1.txt", O_RDONLY);
// 	int fd_2 = open("./prova2.txt", O_RDONLY);
// 	int fd_3 = open("./prova3.txt", O_RDONLY);

// 	char *s = get_next_line(fd_0);
// 	char *s1 = get_next_line(fd_1);
// 	char *s2 = get_next_line(fd_2);
// 	char *s3 = get_next_line(fd_3);

// 	while(s != NULL || s1 != NULL || s2 != NULL || s3 != NULL)
// 	{
// 		printf(" sono zero: %s\n", s);
// 		free(s);
// 		s = get_next_line(fd_0);
// 		printf(" sono uno: %s\n", s1);
// 		free(s1);
// 		s1 = get_next_line(fd_1);
// 		printf(" sono due: %s\n", s2);
// 		free(s2);
// 		s2 = get_next_line(fd_2);
// 		printf(" sono tre: %s\n", s3);
// 		free(s3);
// 		s3 = get_next_line(fd_3);
// 	}
// 	printf(" ultima 0: %s\n", s);
// 	free(s);
// 	printf(" ultima 1: %s\n", s1);
// 	free(s1);
// 	printf(" ultima 2: %s\n", s2);
// 	free(s2);
// 	printf(" ultima 3: %s\n", s3);
// 	free(s3);
// 	return 0;
// }