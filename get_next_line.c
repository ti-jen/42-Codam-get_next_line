/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:29:21 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/13 12:37:33 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif



char *get_next_line(int fd)
{
	int i;
	int p;
	char *chunk;
	char *line = NULL;
	
	p = 0;
	chunk =  malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return(NULL);
	while (!line)
	{
		i = read(fd, chunk, BUFFER_SIZE);
		printf("=%i[]%s=", i,  chunk);
		if (i <= 0 && !p)
		{
			free(chunk);
			return(NULL);
		}
		line = make_line_list(chunk, i);
		p = 1;
	}
	free(chunk);
	return(line);
}

int main()
{
 	// int fd = open("gnlTester/files/multiple_line_no_nl", O_RDWR);
	int fd = open("filename.txt", O_RDWR);
	char *line;
	int i = 0;
	
	while(i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
}