int	ft_strtoi(char const *s, char const **end)
{
	int				number;
	unsigned char	c;
	int				digit;

	number = 0;
	c = *s;
	digit = c - '0';
	while ((unsigned)digit < 10)
	{
		number = (number * 10) + digit;
		c = *++s;
		digit = c - '0';
	}
	*end = s;
	return (sign * number);
}
