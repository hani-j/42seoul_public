/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:22:07 by hogkim            #+#    #+#             */
/*   Updated: 2022/09/14 20:22:08 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

t_parser_state	get_goto_state(t_parser_state state, t_token_type type)
{
	if (state == STATE_0)
		return (goto_from_state_0(type));
	if (state == STATE_1)
		return (goto_from_state_1(type));
	if (state == STATE_2)
		return (goto_from_state_2(type));
	if (state == STATE_4)
		return (goto_from_state_4(type));
	if (state == STATE_5)
		return (goto_from_state_5(type));
	if (state == STATE_7)
		return (goto_from_state_7(type));
	if (state == STATE_10)
		return (goto_from_state_10(type));
	if (state == STATE_11)
		return (goto_from_state_11(type));
	if (state == STATE_12)
		return (goto_from_state_12(type));
	if (state == STATE_14)
		return (goto_from_state_14(type));
	if (state == STATE_16)
		return (goto_from_state_16(type));
	if (state == STATE_18)
		return (goto_from_state_18(type));
	return (STATE_NON);
}

t_tree_content	get_input_value(t_list *input)
{
	t_token_data	*data;
	t_tree_content	content;

	data = input->head->data;
	if (data->token_type == TT_WORD)
		content.word = ft_strdup(data->content);
	else
		content.token = data->token_type;
	return (content);
}

static void	do_under_ttstart(t_all_data *all_data, t_token_type type)
{
	t_token_data	*token_data;
	t_tree_data		*tree_data;
	t_tree_content	content;

	if (type < TT_START)
	{
		parser_push_back(&all_data->parser.parser_stack, type);
		content = get_input_value(&all_data->token_list);
		tree_push_back(&all_data->parser.tree_stack, content);
		token_data = all_data->token_list.head->data;
		tree_data = all_data->parser.tree_stack.tail->data;
		if (token_data->token_type == TT_WORD)
			tree_data->tree_type = TREE_WORD;
		else
			tree_data->tree_type = TREE_TOKEN;
		list_remove_head_token(&all_data->token_list);
	}
}

int	goto_next_state(t_all_data *all_data, \
					t_parser_state goto_state, t_token_type type)
{	
	if (goto_state)
	{
		do_under_ttstart(all_data, type);
		parser_push_back(&all_data->parser.parser_stack, goto_state);
		return (0);
	}
	else
		return (-1);
}
