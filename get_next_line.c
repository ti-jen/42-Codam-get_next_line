/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:29:21 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/15 10:16:33 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd)
{

	static t_list *l = NULL;
	bool end;
	static int i = 1;
	char *chunk;
	char *line;
	
	if (!i)
		return(NULL);
	if (l && ft_is_line(l->content, l->lenght))
	{
		line = malloc(ft_line_lenght(l, false) + 1);
		l = ft_make_line(line, l, false);
		return(line);
	}
	chunk =  malloc(BUFFER_SIZE);
	if (!chunk)
		return(NULL);
	while (i)
	{
		i = read(fd, chunk, BUFFER_SIZE);
		l = ft_lstadd_back(l, chunk, i);
		if ( i <= 0 && !l)
		{
			break;
		}
		if (ft_is_line(chunk, i) || !i)
		{
			if(i)
				end = false;
			else
				end = true;
			line = malloc(ft_line_lenght(l, end) + 1);
			l = ft_make_line(line, l, end);
			free(chunk);
			return(line);
		}
	}
	free(chunk);
	return(NULL);
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