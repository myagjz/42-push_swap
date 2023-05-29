/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:43:00 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/29 15:02:18 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* rotate:
*	Yığının en üstteki elemanı en alta gönderilir.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* do_ra:
*	a yığınının en üstteki elemanını en alta gönderir.
*	Standart çıktıya "ra" yazdırır.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* do_rb:
*	b yığınının en üstteki elemanını en alta gönderir.
*	Standart çıktıya "rb" yazdırır.
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* do_rr:
*	Hem a yığınının hem de b yığınının en üst öğesini kendi yığınlarının en altına gönderir.
*	Standart çıktıya "rr" yazdırır.
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
