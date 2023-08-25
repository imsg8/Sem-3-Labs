#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalRec(char str[],
			int s, int e)
{
	if (s == e)
	return true;

	if (str[s] != str[e])
	return false;

	if (s < e + 1)
	return isPalRec(str, s + 1, e - 1);

	return true;
}

bool isPalindrome(char str[])
{
int n = strlen(str);

if (n == 0)
	return true;

return isPalRec(str, 0, n - 1);
}

int main()
{
    char str[30];
    printf("Enter string - ");
    gets(str);

	if (isPalindrome(str))
	printf("Yes");
	else
	printf("No");

	return 0;
}