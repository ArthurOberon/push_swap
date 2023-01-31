/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 16:05:08 by aoberon          ###   ########.fr       */
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
	int				index;
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

// |=====================|
// |======= UTILS =======|
// |=====================|

int				ft_isdigit(int c);
int				ft_isspace(char c);

// |=====================|
// |======= INDEX =======|
// |=====================|

void			ft_init_index(t_list **lst);

// |======================|
// |======= OTHERS =======|
// |======================|

char			*get_next_line(int fd);

// |=========================|
// |======= MERGE_STR =======|
// |=========================|

char			*ft_str_merge(char **str, int space, int size);

// |===============================|
// |======= PRINT_FUNCTIONS =======|
// |===============================|

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char	*s);

size_t			ft_strlen(const char *s);

// |======================|
// |======= PARSE ========|
// |======================|

int				ft_parse(char *str, t_list **lst);

// |==========================|
// |======= LIST_PILES =======|
// |==========================|

int				ft_lstsize(t_list **lst);

void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);

t_list			*ft_lstmoveout(t_list **lst);

// |==========================|
// |======= OPERATIONS =======|
// |==========================|

void			ft_do_operation(char *str, t_list **lst_a, t_list **lst_b);

// |============================|
// |======= OPERATIONS_2 =======|
// |============================|

void			ft_move(char *operation, t_list **lst_a, t_list **lst_b,
					t_instruction **lst_instruction);


// |==========================|
// |======= LIST_ORDER =======|
// |==========================|

void			ft_get_order(t_list **lst_a, t_list **lst_b,
					t_instruction **lst_instruction);

// |===========================|
// |======= ORDER_UTILS =======|
// |===========================|

int				ft_calcul_gap(t_list *start_a, t_list *end_a,
					t_list *start_b, t_list *end_b);

void			ft_go_to_element(t_list **start, t_list *end);

// |=================================|
// |======= LIST_INSTRUCTIONS =======|
// |=================================|

void			ft_lstclear_instruction(t_instruction **lst);
void			ft_lstadd_back_instruction(t_instruction **lst,
					t_instruction *new);
void			ft_add_instruction(char *operation,
					t_instruction **lst_instruction);

t_instruction	*ft_lstnew_instruction(char *operation);

// |========================================|
// |======= LIST_CREATE_INSTRUCTIONS =======|
// |========================================|

t_instruction	*ft_create_list_instruction(void);

//==========================================

// |=========================|
// |======= TEMPORARY =======|
// |=========================|

void			ft_print_tab(char **tab);
void			ft_print_list(t_list **lst);
void			ft_print_new_element(t_list *tmp);
void			ft_print_tab_int(int *tab, int size);
void			ft_print_list_one_line(t_list **lst);
void			ft_print_list_instruction(t_instruction **lst);
void			ft_print_new_element_instruction(t_instruction *tmp);
void			ft_print_list_instruction_one_line(t_instruction **lst);
void			ft_print_piles(char *str, t_list **lst_a, t_list **lst_b);

#endif
