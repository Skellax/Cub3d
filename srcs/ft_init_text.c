/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:04:29 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/15 09:55:33 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_text(t_game *cube)
{
    int i;

    i = -1;
    while(++i < NB_TEXTURES)
    {
        if (!(cube->img_text[i].mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, 
            cube->name_text[i], 
            &cube->img_text[i].size.x, &cube->img_text[i].size.y)))
            error_msg("error:\n texture non trouvee");
        cube->img_text[i].addr = mlx_get_data_addr(cube->img_text[i].mlx_img,
            &cube->img_text[i].bpp,
            &cube->img_text[i].line_len, &cube->img_text[i].endian);
    }
}