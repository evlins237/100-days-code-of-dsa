#include <stdio.h>
#include <string.h>
#include <limits.h>

int main()
{
    char s[100005];
    scanf("%s", s);

    int index[26];
    for (int i = 0; i < 26; i++)
        index[i] = -1;

    int ansIndex = INT_MAX;
    char ans = '-';

    for (int i = 0; s[i] != '\0'; i++)
    {
        int c = s[i] - 'a';

        if (index[c] == -1)
        {
            index[c] = i;
        }
        else
        {
            if (i < ansIndex)
            {
                ansIndex = i;
                ans = s[i];
            }
        }
    }

    if (ansIndex == INT_MAX)
        printf("-1\n");
    else
        printf("%c\n", ans);

    return 0;
}
