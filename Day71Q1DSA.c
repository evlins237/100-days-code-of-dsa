#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int m;
int *table;

int hash(int key)
{
    return key % m;
}

void insert(int key)
{
    int h = hash(key);

    for (int i = 0; i < m; i++)
    {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY)
        {
            table[idx] = key;
            return;
        }
    }
}

void search(int key)
{
    int h = hash(key);

    for (int i = 0; i < m; i++)
    {
        int idx = (h + i * i) % m;

        if (table[idx] == key)
        {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == EMPTY)
            break;
    }

    printf("NOT FOUND\n");
}

int main()
{
    scanf("%d", &m);

    int q;
    scanf("%d", &q);

    table = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++)
    {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0)
            insert(key);
        else if (strcmp(op, "SEARCH") == 0)
            search(key);
    }

    return 0;
}
