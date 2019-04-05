/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:36:43 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 12:12:57 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <stdlib.h>

typedef struct			s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
	char				*item;
}						t_btree;

t_btree					*btree_create_node(char *item);
char	*btree_search_item(t_btree *root, char *data_ref, int (*cmpf)());
int		btree_level_count(t_btree *root);
void	btree_insert_data(t_btree **root, char *item, int (*cmpf)());
void	btree_apply_suffix(t_btree *root, void (*applyf)());
void	btree_apply_prefix(t_btree *root, void (*applyf)());
void	btree_apply_infix(t_btree *root, void (*applyf)());
void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem));

#endif
