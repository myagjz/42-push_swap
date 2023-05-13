/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:54:08 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 16:55:45 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rotate:
*	Bir yığının alt elemanını en üste getirir.
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/* do_rra:
*	a yığınının alt elemanını en üste getirir.
*	Standart çıktıya "rra" yazdırır.
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/* do_rrb:
*	B yığınının alt öğesini en üste getirir.
*	Standart çıktıya "rrb" yazdırır.
*/
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* do_rrr:
*	Hem a yığınının hem de be yığınının alt öğesini ilgili yığınlarının üstüne getirir.
*	Standart çıktıya "rrr" yazdırır.
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
