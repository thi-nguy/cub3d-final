#include "cub3d.h"

int find_item(const char *content, char* x)
{
    char **new_array;

    new_array = ft_split(content, ' ');
    if (ft_strcmp(new_array[0], x) == 0)
    {
        free_array(new_array);
        return (1);
    }
    free_array(new_array);
    return (0);
}

t_list* ft_lstfind(t_list* lst, char* item, int f(const char *, char *))
{
    if (!f)
		return (ERROR);
	while (lst)// || lst->next)
	{
        // if (lst->content == NULL && lst->next)
        //     lst = lst->next;
        if ((f)(lst->content, item) == 1)
            return(lst);
		lst = lst->next;
	}
    return (lst);
}

t_list*  get_node(t_list** llist, char* item)
{
    t_list *found_node;

    found_node = ft_lstfind(*llist, item, find_item);
    
   



    return (found_node);
}

int parse_resolution(t_list** lst)
{
    t_list* node;

    if (!(node = get_node(lst, "WE")))
        return (ERROR);
    
    printf("%s\n", (char*)node->content);
    
    // printf(&node->content);
    return (SUCCESS);
}

int parse_info(t_info* info)
{
    //t_list* refined_list;

    //clear emptyline?
    // refined_list = 


    if (parse_resolution(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    
    // paser_color(info);
    // parse_image_path(info);

    return(SUCCESS);


}