/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/19 15:46:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define OPTIMIZE_R 90
# define OPTIMIZE_RR 91

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
	struct s_instruction	*prev;
	char					*operation;
}	t_instruction;

typedef struct s_push_swap
{
	t_list			**pile_a;
	t_list			**pile_b;
	t_instruction	**instructions;
}	t_push_swap;

typedef struct s_best_move
{
	int		size;
	int		rota_dir_a;
	int		rota_dir_b;
	int		sa;
	int		sb;
}	t_best_move;

// |----------------------------|
// |			MOVE			|
// |----------------------------|

void			ft_move(char *operation, t_push_swap list_pack);

// |----------------------------|
// |			ALGO			|
// |----------------------------|

void			ft_find_best_move(t_push_swap p);

// |----------------------------|
// |			UTILS			|
// |----------------------------|

int				ft_abs(int a);
int				ft_isdigit(int c);
int				ft_isspace(char c);
int				ft_check_obvious(t_push_swap list_pack);

char			*ft_strdup(const char *s);


// |----------------------------|
// |			INDEX			|
// |----------------------------|

void			ft_init_index(t_list **lst);

// |----------------------------|
// |			OTHERS			|
// |----------------------------|

char			*get_next_line(int fd);

// |----------------------------|
// |			PARSE			|
// |----------------------------|

int				ft_parse(char *str, t_list **lst);

// |----------------------------|
// |			PILES			|
// |----------------------------|

int				ft_is_ascending(t_list *lst);

// |--------------------------------|
// |			MERGE_STR			|
// |--------------------------------|

char			*ft_str_merge(char **str, int space, int size);

// |--------------------------------|
// |			PILES_UTILS			|
// |--------------------------------|

int				ft_lstsize(t_list *lst);
int				ft_lstsize_instruction(t_instruction *lst);

void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);

t_list			*ft_lstmoveout(t_list **lst);

// |--------------------------------|
// |			PRESET_MOVE			|
// |--------------------------------|

void			ft_3_elements(t_push_swap list_pack);

// |--------------------------------|
// |			ALGO_UTILS			|
// |--------------------------------|

int				ft_add_move_size(t_best_move result);

t_list			*ft_get_the_n_element_pile(t_list *start, int n);

t_best_move		ft_init_best_move(void);
t_best_move		ft_calcul_push_after_max(t_push_swap p, t_best_move *result);
t_best_move		ft_calcul_push_before_min(t_push_swap p, t_best_move *result);

// |--------------------------------|
// |			OPERATIONS			|
// |--------------------------------|

void			ft_do_operation(char *str, t_list **lst_a, t_list **lst_b);

// |------------------------------------|
// |			PRINT_FUNCTIONS			|
// |------------------------------------|

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr_fd(char *s, int fd);
void			ft_print_instruction(t_instruction *lst);

size_t			ft_strlen(const char *s);

// |------------------------------------|
// |			PILES_MIN_MAX			|
// |------------------------------------|

t_list			*ft_find_element_min(t_list *lst);
t_list			*ft_find_element_max(t_list *lst);

// |------------------------------------|
// |			PILES_ASCENDING			|
// |------------------------------------|

void			ft_get_pile_ascending(t_push_swap list_pack);

// |----------------------------------------|
// |			PRESET_MOVE_UTILS			|
// |----------------------------------------|

void			ft_preset_1_3_2(t_push_swap list_pack, char pile);
void			ft_preset_2_3_1(t_push_swap list_pack, char pile);
void			ft_preset_2_1_3(t_push_swap list_pack, char pile);
void			ft_preset_3_2_1(t_push_swap list_pack, char pile);
void			ft_preset_3_1_2(t_push_swap list_pack, char pile);

// |----------------------------------------|
// |			OPTIMIZE_ROTATION			|
// |----------------------------------------|

void			ft_optimize_rotation_pile_a_min_max(t_push_swap p,
					t_best_move *result, t_list *dest);
void			ft_optimize_rotation(t_push_swap p, t_best_move *result,
					t_list *tmp_b, int i);
void			ft_optimize_rotation_pile_b(t_push_swap p, t_best_move *result,
					int i);
void			ft_optimize_rotation_pile_a(t_push_swap p, t_best_move *result,
					t_list *tmp_b);

// |----------------------------------------|
// |			DO_BEST_MOVE_UTILS			|
// |----------------------------------------|

int				ft_do_best_move_s(t_push_swap p, t_best_move fastest);
int				ft_do_best_move_rr(t_push_swap p, t_best_move fastest);
int				ft_do_best_move_ra(t_push_swap p, t_best_move fastest);
int				ft_do_best_move_rb(t_push_swap p, t_best_move fastest);
int				ft_do_best_move_rrr(t_push_swap p, t_best_move fastest);

// |--------------------------------------------|
// |			DO_BEST_MOVE_UTILS_2			|
// |--------------------------------------------|

int				ft_do_best_move_sr(t_push_swap p, t_best_move fastest);

// |--------------------------------------------|
// |			PILES_ASCENDING_UTILS			|
// |--------------------------------------------|

int				ft_get_while_number(t_list *lst);
void			ft_move_to_top_pile_a(t_push_swap list_pack, t_list *element);

// |--------------------------------------------|
// |			LIST_INSTRUCTIONS_UTILS			|
// |--------------------------------------------|

int				ft_add_instruction(char *operation,
					t_instruction **lst_instruction);

void			ft_lstclear_instruction(t_instruction **lst);
void			ft_lstadd_back_instruction(t_instruction **lst,
					t_instruction *new);

char			*ft_invert_operation(char *operation);

t_instruction	*ft_lstnew_instruction(char *operation);

// |------------------------------------------------|
// |			CREATE_LIST_INSTRUCTIONS			|
// |------------------------------------------------|

t_instruction	*ft_create_list_instruction(void);

// |----------------------------------------------------|
// |			LIST_INSTRUCTIONS_COMBINATION			|
// |----------------------------------------------------|

int				ft_find_combination_move(t_instruction **lst);
int				ft_combinate_move(t_instruction *tmp, int n,
					char *combinated_move);

// |--------------------------------------------------------|
// |			LIST_INSTRUCTIONS_COMBINATION_UTILS			|
// |--------------------------------------------------------|

int				ft_find_min_value(int a, int b);
int				ft_find_combination_move_helper(t_instruction **tmp,
					int *combinate_number);

void			ft_init_int_tab(int *tab, int size);
void			ft_delete_one_element(t_instruction **tmp);

//------------------------------------------

// |--------------------------------|
// |			TEMPORARY			|
// |--------------------------------|

void			ft_print_tab(char **tab);
void			ft_print_list(t_list **lst);
void			ft_print_new_element(t_list *tmp);
void			ft_print_tab_int(int *tab, int size);
void			ft_print_list_one_line(t_list **lst);
void			ft_print_piles(char *str, t_push_swap p);
void			ft_print_list_instruction(t_instruction **lst);
void			ft_print_new_element_instruction(t_instruction *tmp);
void			ft_print_list_instruction_one_line(t_instruction **lst);

#endif
