/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:51:00 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/16 17:36:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	int				n_pos;
	size_t			size_of_element;
	size_t			buffer_size;
	struct s_list	*next;
}				t_list;

int		ft_is_backslash_n(t_list *lst_tmp, ssize_t read_size);
int		ft_lst_from_read(t_list **buf, ssize_t *read_size, int fd);

char	*get_next_line(int fd);
char	*ft_get_line(t_list **lst, int fd);
char	*ft_lst_concatenation(t_list **lst);

void	ft_substr(t_list *lst);
void	ft_lstadd_back_gnl(t_list **lst, t_list *new);
void	ft_strncat(char *dst, const char *src, size_t size);

size_t	ft_size_of_line(t_list *lst);

#endif
