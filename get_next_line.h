/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:37:57 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/21 11:45:37 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	char			*content;
	int				lenght;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_line_lenght(t_list *l, bool end);
void	ft_lstadd_back(t_list **lst, char *content, int size);
char	*ft_extract_line(t_list **l, int end);

#endif