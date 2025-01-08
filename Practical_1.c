#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidString(const char *str)
{
    int i = 0;

    while (str[i] == 'a')
    {
        i++;
    }

    if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0')
    {
        return true;
    }

    return false;
}

int main()
{
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    if (isValidString(str))
    {
        printf("Valid String\n");
    }
    else
    {
        printf("Not Valid String\n");
    }

    return 0;
}
