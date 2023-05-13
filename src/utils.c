/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:35:17 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 16:35:22 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free_stack:
*	Belirli bir yığındaki her öğeyi serbest bırakır ve
*	yığın işaretçisini NULL olarak ayarlar.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* exit_error:
*   Yığın a ve b'yi serbest bıraktıktan sonra standart çıktıya "Error\n" yazar.
*	Standart hata kodu 1 ile çıkar.
*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/* ft_atoi:
*   Alfasayısal bir karakter dizisini uzun bir tamsayıya dönüştürür.
*/
long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

/* ft_putstr:
*	Belirli bir karakter dizisini standart çıktıya yazdırır.
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* nb_abs:
*	Belirli bir sayının mutlak değerini döndürür.
*	Bir sayının mutlak değeri,
*	o sayının 0'a olan uzaklığını ölçmek için kullanılır,
*	ister pozitif ister negatif olsun (-6'nın mutlak değeri 6'dır).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
