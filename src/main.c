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

int     main(int ac, char** av)
{
   t_info info;

   info.fd = 0;
   info.screenshoot = 0;
   info.head_llist = NULL;
   check_argument(ac, av, &info.screenshoot);
   get_fd(av[1], &info);
   if (parse(&info) == ERROR)
      return (free_memory(&info, ERROR));
   
   
   // Check
   // ft_lstiter(info.head_llist, printf);
   printf("Resolution is: W = %d, H = %d\n", g_window_width, g_window_height);
   printf("Floor color is: %d\n", g_floor_color);
   printf("Ceiling color is: %d\n", g_ceiling_color);
   printf("Sprite's parth is: %s\n", g_sprite_path);
   printf("NO's parth is: %s\n", g_NO_path );
   printf("SO's parth is: %s\n", g_SO_path );
   printf("WE's parth is: %s\n", g_WE_path );
   printf("EA's parth is: %s\n", g_EA_path );
   printf("screenshoot = %d\n", info.screenshoot);
   printf("programm continues till this point.\n");
   free_memory(&info, ERROR);
   // Cần kiểm tra memory leak
   // while (1);
   return (0);
}