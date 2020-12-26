#include "cub3d.h"

int find_item(const char *content, char* x)
{
    if (ft_strncmp(content, x, ft_strlen(x)) == 0)
        return (1);
    return (0);
}


t_list* ft_lstfind(t_list* lst, char* item, int f(const char *, char *))
{
    t_list *tmp;
    t_list *prev; 
    
    tmp = lst;

    if (!f)
		return (ERROR);

	while (lst)
	{
        if ((f)(lst->content, item) == 1)
            return(lst);
        else
		    lst = lst->next;
	}
    return (lst);
}

t_list*  get_node(t_list** llist, char* item)
{
    t_list *found_node;

    found_node = ft_lstfind(*llist, item, find_item);
    if (!found_node)
		return (NULL);
	if (found_node == ft_lstlast(*llist))
		return (NULL);
    return (found_node);
}

int check_number_of_element(char* line, int num)
{
    int num_of_element;

    num_of_element = ft_count_words(line, ' ');
    printf("number of element: %d\n", num_of_element);
    if (num_of_element == num)
        return (SUCCESS);
    else
    {
        ft_putstr_fd("Error.\n", 1);
        ft_putstr_fd("Number of elements is not correct.\n", 1);
        return(ERROR);
    }
}

int parse_resolution(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "R")))
    {
        ft_putstr_fd("Error\n", 1);
        ft_putstr_fd("Cannot find the resolution or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 3) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    g_window_width = ft_atoi(line[1]);
    g_window_height = ft_atoi(line[2]);
    if (g_window_height <= 0 || g_window_width <= 0)
    {
        ft_putstr_fd("Error\n", 1);
        ft_putstr_fd("Window size is misconfiguration.\n", 1);
        free_array(line, 3);
        return (ERROR);
    }
    free_array(line, 3);
    return (SUCCESS);
}

int parse_info(t_info* info)
{
    if (parse_resolution(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    
    // paser_color(info);
    // parse_image_path(info);

    return(SUCCESS);


}