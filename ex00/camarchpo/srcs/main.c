/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:50:21 by alevra            #+#    #+#             */
/*   Updated: 2022/07/23 12:27:12 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"rush02.h"



typedef struct s_element_dict
{
	char	*key;
	char	*value;
} t_element_dict;



int main(int argc, char **argvalue)
{
	
	int a;
	a =0;

	t_element_dict element;

	element.key = "0";
	element.value = "zero";

	t_element_dict element2;

	element2.key = "1";
	element2.value = "one";

	return 0;
}
