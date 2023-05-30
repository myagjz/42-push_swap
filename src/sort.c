/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:43:31 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/30 13:52:37 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* push_all_save_three:
*	Son üç öğe hariç a yığınının tüm öğelerini b yığınına iter.
*	Sıralama verimliliğine yardımcı olmak için önce daha küçük değerleri,
*	ardından daha büyük değerleri zorlar.
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
*	Yığının büyük kısmı sıralandıktan sonra, yığın a'yı en düşük değer en üstte olana kadar kaydırır.
*	Yığının alt yarısındaysa, tersine döndürerek konumuna getirin, aksi halde yığının tepesine gelene kadar döndürün.
*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/* sort:
*	3'ten büyük bir yığın için sıralama algoritması.
*		B yığınına 3 sayı dışında her şeyi itin.
*		A yığınında kalan 3 sayıyı sıralayın.
*		En uygun maliyetli hareketi hesaplayın.
*		A yığını sıralanana kadar öğeleri kaydırın.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
