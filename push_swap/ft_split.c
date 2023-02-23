#include "push_swap.h"
int		ft_word_count(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

char	*ft_word_make(char *word, char const *s, int k, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
		word[i++] = s[k - word_len--];
	word[i] = '\0';
	return (word);
}

char	**ft_split2(char **result, char const *s, char c, int word_num)
{
	int		i;
	int		k;
	int		word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < word_num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		if (!(result[i] = (char *)malloc(sizeof(char) * (word_len + 6))))
			return (NULL);
		ft_word_make(result[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**result;

	if (s == 0)
		return (NULL);
	word_num = ft_word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (word_num + 1))))
		return (NULL);
	ft_split2(result, s, c, word_num);
	return (result);
}





//int	ft_atoi(const char *str)
//{
//	long int	res;
//	int			negative;
//
//	negative = 1;
//	res = 0;
//	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
//			*str == '\v' || *str == '\f' || *str == '\r'))
//		++str;
//	if (*str == '-')
//		negative = -1;
//	if (*str == '-' || *str == '+')
//		++str;
//
////	if (*str && !(*str >= '0' && *str <= '9'))
////
////print_error();
//	while (*str && *str >= '0' && *str <= '9')
//	{
//		res = res * 10 + (*str - 48);
//		++str;
//	}
//	if(!(*(str + 1) >= '0' && *(str + 1) <= '9') || res > 2147483647 || res < -2147483648)
//	{	
//		printf("i am %ld %cgoing in\n",res,*str);
//		print_error();
//	}
//	return (res * negative);
//}

int ft_atoll(const char *str) 
{
	long long result; 
	int np; 
	int chker;

	result = 0; 
	np = 1; 
	chker = 0; 

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f') 
		str++; 
	if (*str == '-') 
		np = -1; 
	if (*str == '+' || *str == '-')
		str++; 
	while (*str >= 48 && *str <= 57) 
	{ 
		result = result * 10 + (*str - '0'); 
		str++; 
		chker++; 
	} 
	result = result * np; 
	if (*str != '\0' || chker > 10 || result > 2147483647 || result < -2147483648) 
		print_error(); 
	return ((int)result);
}
