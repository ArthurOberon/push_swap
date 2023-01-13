/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/13 21:44:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // \/!\ CAUTION !!!!! /!\/

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
}	t_list;

typedef struct s_piles
{
	t_list	**pile_a;
	t_list	**pile_b;
}	t_piles;

enum { pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr };

// |==================================|
// |======= ONE FILE FUNCTIONS =======|
// |==================================|

char	**ft_split(char const *s, char c);

// |================================|
// |======= USEFUL_FUNCTIONS =======|
// |================================|

int		ft_isdigit(int c);
int		ft_isspace(char c);

char	*ft_malloc_zero(size_t size);
char	*ft_strcat(char *dst, char *src);
char	*ft_str_merge(char **str, int space, int size);

// |===============================|
// |======= PRINT_FUNCTIONS =======|
// |===============================|

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char	*s);

size_t	ft_strlen(const char *s);

// |==============================|
// |======= LIST_FUNCTIONS =======|
// |==============================|

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));

t_list	*ft_lstnew(int content);
t_list	*ft_lstmoveout(t_list **lst);

// |================================|
// |======= PARSE_FUNCTIONS ========|
// |================================|

int		ft_parse(char *str, t_list **lst);

// |==========================|
// |======= OPERATIONS =======|
// |==========================|

void	ft_do_operation(char *str, t_list **lst_a, t_list **lst_b);

// |======================|
// |======= OTHERS =======|
// |======================|

// void	ft_free_double_tab(char **tab);

//==========================================

// |===================================|
// |======= TEMPORARY_FUNCTIONS =======|
// |===================================|

void	ft_print_tab(char **tab);
void	ft_print_list(t_list **lst);
void	ft_print_new_element(t_list *tmp);

#endif
