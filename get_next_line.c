/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:29:21 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/16 11:17:49 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	static t_list	*l = NULL;
	static int		i = 1;
	char			*chunk;

	if (!i)
		return (NULL);
	if (l && ft_line_lenght(l, i))
		return (extract_line(&l, true));
	chunk = malloc(BUFFER_SIZE);
	if (!(chunk))
		return (NULL);
	while (i)
	{
		i = read(fd, chunk, BUFFER_SIZE);
		l = ft_lstadd_back(l, chunk, i);
		if (i <= 0 && !l)
			break ;
		if (ft_line_lenght(l, i))
		{
			free(chunk);
			return (extract_line(&l, i));
		}
	}
	free(chunk);
	return (NULL);
}

// int main()
// {
//  	int fd = open("gnlTester/files/nl", O_RDWR);
// 	// int fd = open("filename.txt", O_RDWR);
// 	char *line;
// 	int i = 0;

// 	while(i < 10)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// }