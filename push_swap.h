#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

typedef struct s_list
{
	int				*nb;
	struct s_list	*next;
}		t_list;



// ------------------- swap_utils --------------------
int long	ft_atoi(const char *str);
int	ft_strcmp(char *str1, char *str2);
//static int	ft_checksign(const char *str);

// ------------------- check_error --------------------
int	ft_check_error(char **av);
int	check_nb(char **av);
int	check_int(char **av);

# endif