/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:27:46 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/05 22:53:33 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bool	is_valid_char(char c)
{
	return (ft_isspace(c) || c == 37 || (c >= 40 && c <= 43) || c == 45 ||
			(c >= 47 && c <= 57) || c == 94 || c == 33);
}

void	compute(void)
{
	char		*line;
	int			flag;
	int			flag_;
	int			i;
	t_bool		is_invalid;
	t_bignum	*num;

	while ((flag = ft_nextline(1, &line)) > 0 && !ft_strequ(line, "quit"))
	{
		i = -1;
		is_invalid = false;
		while (line[++i])
			if (!is_valid_char(line[i]))
			{
				is_invalid = true;
				break ;
			}
		if (is_invalid || (flag_ = parse_expr(line)) != NORM)
		{
			if (flag_ == ERROR || is_invalid)
				ft_printf("bnc: invalid input\n");
			else
				ft_printf("bnc: too many operands or operators\n");
			clear_numstack();
			clear_opstack();
		}
		else
		{
			num = pop_num();
			print_num(num);
			ft_printf("\n");
			delete_num(&num);
		}
		free(line);
	}
	if (flag > 0 && ft_strequ(line, "quit"))
		free(line);
}
