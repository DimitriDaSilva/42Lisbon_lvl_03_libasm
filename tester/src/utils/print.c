/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:52:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/31 19:25:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_header(char *header)
{
	int	pad_len = 15 - strlen(header) / 2;
	printf("\n");
	printf("/+++++++++++++++++++++++++++++++\\\n");
	printf("+%*s%s%*s+\n", pad_len, "", header, pad_len, "");
	printf("\\+++++++++++++++++++++++++++++++/\n");
	printf("\n");
}

