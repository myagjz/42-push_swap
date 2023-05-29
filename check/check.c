/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:05:28 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/29 00:27:26 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_sub(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		do_rra(stack_a);
	else if (line[2] == 'b')
		do_rrb(stack_b);
	else if (line[2] == 'r')
		do_rrr(stack_a, stack_b);
}

char	*ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		do_sa(stack_a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		do_sb(stack_b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		do_pa(stack_a, stack_b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		do_pb(stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		do_ra(stack_a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		do_rb(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		do_rr(stack_a, stack_b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		do_ss(stack_a, stack_b);
	else
		ft_error_ch();
	return (get_next_line(0));
}

void	ft_checker_sub(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(stack_a, stack_b, line);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (ac < 2)
		return (0);
	if (ac > 2 && !is_correct_input(av))
		exit_error(NULL,NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	if (!stack_a || have_duplicates(av))
	{
		free_stack(&stack_a);
		exit_error(NULL,NULL);
	}
	line = get_next_line(0);
	if (!line && !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&stack_a, &stack_b, line);
	free_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}

// ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
