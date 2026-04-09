/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:29:21 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/09 11:17:32 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif



char *get_next_line(int fd)
{
	int i;
	char *chunk;
	char *line = NULL;
	
	chunk =  malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return(NULL);
	while (!line)
	{
		i = read(fd, chunk, BUFFER_SIZE);
		// printf("=%i[]%s=\n", i,  chunk);
		if (!i && !chunk[0])
			return(NULL);
		line = make_line_list(chunk, i);
	}
	return(line);
}

int main()
{
 	int fd = open("gnlTester/files/41_no_nl", O_RDWR);
	get_next_line(fd);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}