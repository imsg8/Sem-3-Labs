#include <stdio.h>
 
void copy(char [], char [], int);
 
int main()
{
    char str1[20], str2[20];
 
    printf("Enter string to copy: ");
    scanf("%[^\n]s", str1);
    copy(str1, str2, 0);
    printf("Copying success.\n");
    printf("The first string is: %s\n", str1);
    printf("The second string is: %s\n", str2);
    return 0;
}
 
void copy(char str1[], char str2[], int index)
{
    str2[index] = str1[index];
    // printf ("INDEX IS %d\n", index);
    if (str1[index] == '\0')
        return;
    copy(str1, str2, index + 1);
}