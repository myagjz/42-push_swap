/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:15:44 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 17:15:46 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
*	Bir yığının sıralanıp sıralanmadığını kontrol eder.
*	Yığın sıralanmamışsa 0, sıralanmışsa 1 döndürür.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Sıralanacak değerlerin sayısına bağlı olarak
*	bir sıralama yöntemi seçer.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	Girişin doğru olup olmadığını kontrol eder,
*	bu durumda yığın a ve b'yi başlatır,
*	her bir değer indeksini atar ve yığınları sıralar.
*	Sıralama tamamlandığında yığınları serbest bırakır ve çıkar.
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
