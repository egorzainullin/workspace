#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int strlen(char s[])
{
	int i = 0;
	while ((int)s[i] > 20)
	{
	i++;
	}
	return i;
}

int compare(int i, char s[], char s1[])
{
	int j = 0;
	int length1 = strlen(s1);
	int length = strlen(s);
	while ((s[i] == s1[j]) && (j < length1) && (i < length))
	{
		++i;
		++j;
	}
	return i;
}

int main()
{
	char s1[100] = "";
	char s[100] = "";
	scanf("%s", s);
	scanf("%s", s1);
	int i = 0;
	int k = 0;
	int count = 0;
	int length = strlen(s);
	while (i < length)
	{
		k = i;
		i = compare(i, s, s1);
		if (i - k == strlen(s1))
		{
			++count;
		}
		if (i == k)
		{
			++i;
		}
	}
	printf("%d", count);
	return 0;
}