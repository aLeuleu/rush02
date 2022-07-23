/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:04:39 by alevra            #+#    #+#             */
/*   Updated: 2022/07/23 16:58:04 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_element_dict
{
	char	*key;
	char	*value;
} t_element_dict;

t_element_dict	*parse_dict();

int		how_many_splits(char *input);

void	set_keys(t_element_dict	*tab_element);

char	*fetch_values(char *key);

void	display_tab_element(t_element_dict	*tab_element);
