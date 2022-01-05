#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_info 
{
	char	c;
	int		byte;
}	t_info;

t_info myinfo = {0, 0};
