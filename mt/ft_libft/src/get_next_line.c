/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:35:47 by dalara-s          #+#    #+#             */
/*   Updated: 2024/10/31 13:23:37 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_free_gnl(char **ptr)
{
	free(*ptr);
	*ptr = 0;
	return (NULL);
}

char	*read_line(char *line, int fd)
{
	int		ret;
	char	*buffer;

	ret = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (ft_free_gnl(&line));
	while (ret > 0 && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			buffer[ret] = 0;
			line = ft_strjoin(line, buffer);
		}
	}
	ft_free_gnl(&buffer);
	if (ret == -1)
		return (ft_free_gnl(&line));
	return (line);
}

char	*get_base(char *buffer)
{
	int		i;
	char	*line;

	line = 0;
	i = 0;
	if (!buffer)
		return (ft_free_gnl(&buffer));
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

char	*get_sufix(char *buffer)
{
	int		i;
	char	*sufix;

	i = 0;
	if (!buffer)
		return (ft_free_gnl(&buffer));
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free_gnl(&buffer));
	if (buffer[i] != 0)
		i++;
	sufix = ft_substr(buffer, i, ft_strlen(buffer));
	ft_free_gnl(&buffer);
	if (!sufix)
		return (NULL);
	return (sufix);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*base;

	base = 0;
	if (BUFFER_SIZE <= 0 && fd < 0)
		return (NULL);
	if ((line && !ft_strchr(line, '\n')) || !line)
		line = read_line(line, fd);
	if (!line)
		return (ft_free_gnl(&line));
	base = get_base(line);
	line = get_sufix(line);
	if (!base)
		return (ft_free_gnl(&line));
	return (base);
}
/*
int main(int argc, char *argv[])
{
	int	fd;
	char	*final;
	final = 0;
	if(argc != 2)
		return 0;
	fd = open(argv[1], O_RDONLY);
	while((final = get_next_line(fd)) != NULL){
	printf("%s",final);
	free(final);
}
	close(fd);
}*/
