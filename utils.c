#include "fractol.h"

bool valid_number(char *str)
{
    int i;
    i = 0;
    if (str[0] == '-' || str[0] == '+')
    {
        if (str[1] == '\0')
            return false;
        else
            i++;
    }
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}
