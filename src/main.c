#include "cub3d.h"

int     main(int ac, char** av)
{
   t_info info;

   info.fd = 0;
   info.screenshoot = 0;
   check_argument(ac, av, &info.screenshoot);
   get_fd(av[1], &info);
   if (parse(&info) == ERROR)
      return (ERROR);
   
   
   ft_lstiter(info.head_llist, printf);
   printf("screenshoot = %d\n", info.screenshoot);
   printf("programm continues till this point.\n");
   return (0);
}