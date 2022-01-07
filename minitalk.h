#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_info 
{
	char	c;
	int		byte;
}	t_info;

t_info myinfo = {0, 0};
