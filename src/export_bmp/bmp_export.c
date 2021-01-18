/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:56:13 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/18 11:57:28 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			create_file(char *file_name)
{
	int	fd;

	if (!((fd = open(file_name, O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		ft_putstr_fd("Error\nCannot creat bmp file\n", 1);
		exit(ERROR);
	}
	return (fd);
}

void		create_header(t_bmp_file *info_bmp_file)
{
	info_bmp_file->byte_type[0] = 0x42;
	info_bmp_file->byte_type[1] = 0x4D;
	info_bmp_file->byte_size = (g_window.width * g_window.height * 4) + 54; // ! 4 is for 4 bits for is pixels. image size is all of info, so need to + 54 as well.
	info_bmp_file->byte_reserved = 0x00000000;
	info_bmp_file->byte_offset = 0x36; // * Where the color begin
	info_bmp_file->header_size = 40; // * always 40
	info_bmp_file->image_width = g_window.width; // 
	info_bmp_file->image_height = -g_window.height;
	info_bmp_file->color_planes = 1; // * always 1
	info_bmp_file->bits_per_pixel = 32; // * not 24? 
	info_bmp_file->compression = 0; // * not compressing anything
	info_bmp_file->image_size = (g_window.width * g_window.height * 4);
	info_bmp_file->bits_xpels_per_meter = 2835; // * pixel per meter
	info_bmp_file->bits_xpels_per_meter = 2835;
	info_bmp_file->total_colors = 0; // * color palette
	info_bmp_file->important_colors = 0; // * all colors are important.
}

// ! : in bmp, we start at bottom left of the window.
// 
void		write_header(int fd, t_bmp_file info_bmp_file)
{
	int			r;

	r = 0;
	r = write(fd, &info_bmp_file.byte_type, 2);
	r = write(fd, &info_bmp_file.byte_size, 4);
	r = write(fd, &info_bmp_file.byte_reserved, 4);
	r = write(fd, &info_bmp_file.byte_offset, 4);
	r = write(fd, &info_bmp_file.header_size, 4);
	r = write(fd, &info_bmp_file.image_width, 4);
	r = write(fd, &info_bmp_file.image_height, 4);
	r = write(fd, &info_bmp_file.color_planes, 2);
	r = write(fd, &info_bmp_file.bits_per_pixel, 2);
	r = write(fd, &info_bmp_file.compression, 4);
	r = write(fd, &info_bmp_file.image_size, 4);
	r = write(fd, &info_bmp_file.bits_xpels_per_meter, 4);
	r = write(fd, &info_bmp_file.bits_ypels_per_meter, 4);
	r = write(fd, &info_bmp_file.total_colors, 4);
	r = write(fd, &info_bmp_file.important_colors, 4);
	(void)r;
}

void		write_file(int fd, int imagesize)
{
	char		*pixel_array;
	int			i;
	int			j;

	if (!(pixel_array = malloc(sizeof(char) * imagesize)))
		exit(ERROR);
	i = 0;
	j = 0;
	imagesize /= 4; // ! 4 is magic number
	while (i < imagesize)
	{
		// ! What is this??
		pixel_array[j++] = g_image.data_addr[i] & 255; // ! Some kind of bitmap?
		pixel_array[j++] = (g_image.data_addr[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g_image.data_addr[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(fd, pixel_array, imagesize *= 4);
	free(pixel_array);
	pixel_array = NULL;
}

void		get_bmp(char *file_name)
{
	t_bmp_file	info_bmp_file;
	int			fd;

	ft_bzero(&info_bmp_file, sizeof(t_bmp_file));
	fd = create_file(file_name);
	create_header(&info_bmp_file);
	write_header(fd, info_bmp_file);
	write_file(fd, info_bmp_file.image_size);
	close(fd);
	(void)info_bmp_file;
}
