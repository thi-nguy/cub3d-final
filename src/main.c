#include "cub3d.h"

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
   
   
   ft_lstiter(info.head_llist, printf);
   printf("screenshoot = %d\n", info.screenshoot);
   printf("programm continues till this point.\n");
   free_memory(&info, ERROR);
   // Cần kiểm tra memory leak
   // while (1);
   return (0);
}