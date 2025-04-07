#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float ft_atof(char *str)
{
	int sign = 1;
	float number = 0;
	int i = 0;
	float float_mult = 1;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i++] - '0';
	}
	if (str[i] == '.')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		float_mult /= 10;
		number += (str[i++] - '0') * float_mult;
	}
	return number * sign;
}


int main(int argc, char **argv)
{
	printf("%f\n", ft_atof(argv[1]));
	printf("%f\n", atof(argv[1]));
}
