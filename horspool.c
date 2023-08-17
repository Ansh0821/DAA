#include <stdio.h>
#include <string.h>

#define SIZE 128
int table[SIZE];

void shiftTable(char pattern[])
{
    int m = strlen(pattern);

    for (int i = 0; i < SIZE; i++)
    {
        table[i] = m;
    }

    for (int i = 0; i < m - 1; i++)
    {
        table[pattern[i]] = m - 1 - i;
    }
}

int horspool(char text[], char pattern[])
{
    shiftTable(pattern);
    int m = strlen(pattern);
    int n = strlen(text);

    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
        {
            k++;
        }
        if (k == m)
        {
            return i - m + 1;
        }
        else
            i = i + table[text[i]];
    }
    return -1;
}

void main()
{
    char text[500], pattern[200];
    printf("Enter the text:\n");
    gets(text);

    printf("Enter the pattern:\n");
    gets(pattern);

    int p = horspool(text, pattern);

    if (p == -1)
    {
        printf("Pattern not found\n");
    }
    else
    {
        printf("Pattern found at position %d\n", p + 1);
    }
}