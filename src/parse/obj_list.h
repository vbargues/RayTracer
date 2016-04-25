/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:39:34 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:39:35 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_LIST_H
# define OBJ_LIST_H
# include "../../rt.h"
# include <stdlib.h>

t_lst		*ft_parse_lstnew(t_obj *object);
t_llst		*ft_parse_llstnew(t_light *light);

void		ft_parse_lstadd(t_lst **be_lst, t_lst *new_obj);
void		ft_parse_llstadd(t_llst **be_llst, t_llst *new_obj);

#endif
