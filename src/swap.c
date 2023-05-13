/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:35:31 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 16:35:34 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap:
*	Bir yığının en üstteki 2 öğesini değiştirir.
*	Yalnızca bir öğe varsa veya hiç öğe yoksa hiçbir şey yapmaz.
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* do_sa:
*	a yığınının en üstteki 2 öğesini değiştirir.
*	Standart çıktıya "sa" yazdırır.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
*	b yığınının en üstteki 2 öğesini değiştirir.
*	Standart çıktıya "sb" yazdırır.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
*	a yığınının ilk 2 elemanı ile b yığınının ilk 2 elemanını değiştirir.
*	Standart çıktıya "ss" yazdırır.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
