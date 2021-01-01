#include "cub3d.h"

void   free_array(char** array, int len)
{
   int i;

   if (!array)
      return ;
   for (i = 0; i < len; i++)
      free(array[i]); 
   free(array);
   array = NULL;
}

int   free_memory(t_info* info, int return_code)
{
   if (info->head_llist)
      ft_lstclear(&info->head_llist, free);
   return(return_code);
}