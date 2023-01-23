/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/23 13:16:54 by aoberon          ###   ########.fr       */
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

typedef struct s_instruction
{
	struct s_instruction	*next;
	char					*operation;
}	t_instruction;

typedef struct s_piles
{
	t_list	**pile_a;
	t_list	**pile_b;
}	t_piles;

// USELESS ?
// enum e_operation
// {
// 	pa,
// 	pb,
// 	sa,
// 	sb,
// 	ss,
// 	ra,
// 	rb,
// 	rr,
// 	rra,
// 	rrb,
// 	rrr
// };

// |==================================|
// |======= ONE FILE FUNCTIONS =======|
// |==================================|

char			**ft_split(char const *s, char c);

// |================================|
// |======= USEFUL_FUNCTIONS =======|
// |================================|

int				ft_isdigit(int c);
int				ft_isspace(char c);

char			*ft_str_merge(char **str, int space, int size);

// char			*ft_malloc_zero(size_t size); --> static
// char			*ft_strcat(char *dst, char *src); --> static

// |===============================|
// |======= PRINT_FUNCTIONS =======|
// |===============================|

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char	*s);

size_t			ft_strlen(const char *s);

// |====================================|
// |======= LIST_FUNCTIONS_PILES =======|
// |====================================|

void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);

t_list			*ft_lstmoveout(t_list **lst);

// |===========================================|
// |======= LIST_FUNCTIONS_INSTRUCTIONS =======|
// |===========================================|

void			ft_lstclear_instruction(t_instruction **lst);
void			ft_lstadd_back_instruction(t_instruction **lst,
					t_instruction *new);

t_instruction	*ft_lstnew_instruction(char *operation);

// |==================================================|
// |======= LIST_CREATE_FUNCTIONS_INSTRUCTIONS =======|
// |==================================================|

t_instruction	*ft_create_list_instruction(void);

// |================================|
// |======= PARSE_FUNCTIONS ========|
// |================================|

int				ft_parse(char *str, t_list **lst);

// |==========================|
// |======= OPERATIONS =======|
// |==========================|

void			ft_do_operation(char *str, t_list **lst_a, t_list **lst_b);

// |======================|
// |======= OTHERS =======|
// |======================|

char			*get_next_line(int fd);

//==========================================

// |===================================|
// |======= TEMPORARY_FUNCTIONS =======|
// |===================================|

void			ft_print_tab(char **tab);
void			ft_print_list(t_list **lst);
void			ft_print_new_element(t_list *tmp);
void			ft_print_list_one_line(t_list **lst);
void			ft_print_list_instruction(t_instruction **lst);
void			ft_print_new_element_instruction(t_instruction *tmp);
void			ft_print_list_instruction_one_line(t_instruction **lst);
void			ft_print_piles(char *str, t_list **lst_a, t_list **lst_b);

#endif
