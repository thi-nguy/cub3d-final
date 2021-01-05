#include "cub3d.h"


float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI)); //get inside 0, 2Pi
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

void find_where_ray_face()
{
    if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
		ray.is_ray_facing_down = 1;
	else
    	ray.is_ray_facing_up = 1;
	if (ray.ray_angle < (0.5 * M_PI) || ray.ray_angle > (1.5 * M_PI))
		ray.is_ray_facing_right = 1;
	else
    	ray.is_ray_facing_left = 1;
}

void	next_horz_intercept(float next_y, float next_x)
{
	float	tmp;

	while (next_x >= 0 && next_x <= (g_map_col * g_tile_size) && next_y >= 0 && next_y <= (g_map_row * g_tile_size))
	{
		tmp = 0;
		if (ray.is_ray_facing_up)
			tmp = 1;
		if (has_wall_at(next_y - tmp, next_x))
		{
			ray.horz_wall_hit_y = next_y;
			ray.horz_wall_hit_x = next_x;
			ray.found_horz_wall_hit = 1;
			return ;
		}
		next_x += ray.x_step;
		next_y += ray.y_step;
	}
}

void find_horz_intercept(t_ray *ray, t_player *player)
{
    float	next_horz_touch_y;
	float	next_horz_touch_x;
    
    //get point of Oy intercept.
    ray->y_intercept = floor(player->y / g_tile_size) * g_tile_size;
	if (ray->is_ray_facing_down)
		ray->y_intercept += g_tile_size;
	ray->x_intercept = player->x + ((ray->y_intercept - player->y) /
	tan(ray->ray_angle));
	ray->y_step = g_tile_size;
	if (ray->is_ray_facing_up)
		ray->y_step *= -1;
	ray->x_step = g_tile_size / tan(ray->ray_angle);
	if (ray->is_ray_facing_left && ray->x_step > 0)
		ray->x_step *= -1;
	if (ray->is_ray_facing_right && ray->x_step < 0)
		ray->x_step *= -1;
	next_horz_touch_x = ray->x_intercept;
	next_horz_touch_y = ray->y_intercept;
	next_horz_intercept(next_horz_touch_y, next_horz_touch_x);
   
}

void	next_vert_intercept(float next_vert_touch_y, float next_vert_touch_x)
{
	float	tmp;

	while (next_vert_touch_x >= 0 && next_vert_touch_x <= g_window.width
	&& next_vert_touch_y >= 0 && next_vert_touch_y <= g_window.height)
	{
		tmp = 0;
		if (ray.is_ray_facing_left)
			tmp = 1;
		if (has_wall_at(next_vert_touch_y, next_vert_touch_x - tmp))
		{
			ray.found_vert_wall_hit = 1;
			ray.vert_wall_hit_x = next_vert_touch_x;
			ray.vert_wall_hit_y = next_vert_touch_y;
			return ;
		}
		next_vert_touch_x += ray.x_step;
		next_vert_touch_y += ray.y_step;
	}
}

void		find_vert_intercept(t_ray *ray, t_player *player)
{     
    float	next_vert_touch_x;
	float	next_vert_touch_y;

	ray->x_intercept = floor(player->x / g_tile_size) * g_tile_size;
	if (ray->is_ray_facing_right)
		ray->x_intercept += g_tile_size;
	ray->y_intercept = player->y + (ray->x_intercept - player->x) *
	tan(ray->ray_angle);
	ray->x_step = g_tile_size;
	if (ray->is_ray_facing_left)
		ray->x_step *= -1;
	ray->y_step = g_tile_size * tan(ray->ray_angle);
	if (ray->is_ray_facing_up && ray->y_step > 0)
		ray->y_step *= -1;
	if (ray->is_ray_facing_down && ray->y_step < 0)
		ray->y_step *= -1;
	next_vert_touch_x = ray->x_intercept;
	next_vert_touch_y = ray->y_intercept;
	next_vert_intercept(next_vert_touch_y, next_vert_touch_x);

}


void	init_ray()
{
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.was_hit_vertical = 0;
	ray.wall_hit_vertical = 0;
	ray.x_step = 0;
	ray.x_intercept = 0;
	ray.y_step = 0;
	ray.y_intercept = 0;
	ray.distance = 0;
	ray.is_ray_facing_down = 0;
	ray.is_ray_facing_up = 0;
	ray.is_ray_facing_right = 0;
	ray.is_ray_facing_left = 0;
    ray.wall_hit_content = 0;
	ray.vert_wall_hit_x = 0;
	ray.vert_wall_hit_y = 0;
	ray.horz_wall_hit_y = 0;
	ray.horz_wall_hit_x = 0;
	ray.found_vert_wall_hit = 0;
	ray.found_horz_wall_hit = 0;
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	the_smallest_of_the_distances_utile(float vert_hit_distance, float horz_hit_distance)
{
	if (horz_hit_distance < vert_hit_distance)
	{
		ray.wall_hit_x = ray.horz_wall_hit_x;
		ray.wall_hit_y = ray.horz_wall_hit_y;
		ray.distance = horz_hit_distance;
	}
	else
	{
		ray.wall_hit_x = ray.vert_wall_hit_x;
		ray.wall_hit_y = ray.vert_wall_hit_y;
		ray.distance = vert_hit_distance;
	}
	if (vert_hit_distance < horz_hit_distance)
		ray.was_hit_vertical = 1;
}


void find_smallest_distance()
{
    float		horz_hit_distance;
	float		vert_hit_distance;

	horz_hit_distance = 0;
	vert_hit_distance = 0;
	if (ray.found_horz_wall_hit == 1)
		horz_hit_distance = distance_between_points(player.x, player.y,
		ray.horz_wall_hit_x, ray.horz_wall_hit_y);
	else
		horz_hit_distance = MAX_VALUE;
	if (ray.found_vert_wall_hit == 1)
		vert_hit_distance = distance_between_points(player.x, player.y,
		ray.vert_wall_hit_x, ray.vert_wall_hit_y);
	else
		vert_hit_distance = MAX_VALUE;
	the_smallest_of_the_distances_utile(vert_hit_distance, horz_hit_distance);

}

int	choice_of_texture(void)
{
	if (ray.is_ray_facing_up && !ray.was_hit_vertical)
		return (0);
	if (ray.is_ray_facing_down && !ray.was_hit_vertical)
		return (1);
	if (ray.is_ray_facing_left && ray.was_hit_vertical)
		return (2);
	if (ray.is_ray_facing_right && ray.was_hit_vertical)
		return (3);
	(void)ray;
	// return (0);
}


void	draw_wall(t_wall *wall, int column_id)
{
	int	texture_offset_x;
	int	texture_offset_y;
	int	texture_color;
	int	distance_from_top;
	int	index;

	index = choice_of_texture();
	if (ray.was_hit_vertical == 1)
		texture_offset_x = (int)(ray.wall_hit_y * g_texture[index].width /
		g_tile_size) % g_texture[index].width;
	else
		texture_offset_x = (int)(ray.wall_hit_x * g_texture[index].width /
		g_tile_size) % g_texture[index].width;
	while (wall->wall_top < wall->wall_bottom)
	{
		distance_from_top = wall->wall_top + (wall->wall_strip_height / 2) -
		(g_window.height / 2);
		texture_offset_y = distance_from_top * ((float)g_texture[index].height /
		wall->wall_strip_height);
		texture_color = g_texture[index].data_addr[(g_texture[index].width *
		texture_offset_y) + texture_offset_x];
		g_image.data_addr[(wall->wall_top * g_window.width) +
		column_id] = texture_color;
		wall->wall_top++;
	}
}

void		render_ray(int column_id)
{
	t_wall	wall;

	wall.correct_wall_distance = ray.distance * cos(ray.ray_angle - player.rotationAngle);
	g_sprite.buffer[column_id] = wall.correct_wall_distance;
	wall.distance_projection_plane = (g_window.width / 2) / tan(g_fov / 2);
	wall.wall_strip_height = (g_tile_size / wall.correct_wall_distance) * wall.distance_projection_plane;
	wall.wall_top = (g_window.height / 2) - (wall.wall_strip_height / 2);
	if (wall.wall_top < 0)
		wall.wall_top = 0;
	wall.wall_bottom = (g_window.height / 2) + (wall.wall_strip_height / 2);
	if (wall.wall_bottom > g_window.height)
		wall.wall_bottom = g_window.height;
	draw_wall(&wall, column_id);
}



void cast_one_ray(float ray_angle, int strip_id)
{
    ray.ray_angle = normalize_angle(ray_angle);
    find_where_ray_face();
	find_horz_intercept(&ray, &player);
    find_vert_intercept(&ray, &player);
    find_smallest_distance();
    render_ray(strip_id);
}

void cast_rays(void)
{
    int strip_id;

    strip_id = 0;
    ray.ray_angle = player.rotationAngle - (g_fov / 2);
    while (strip_id < g_num_rays)
    {   
        init_ray();
        cast_one_ray(ray.ray_angle, strip_id);
        ray.ray_angle += g_fov / g_num_rays;
        strip_id++;
    }


}