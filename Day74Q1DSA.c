#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char names[MAX][LEN];
    int count[MAX] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], names[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    int maxVotes = 0;
    char result[LEN] = "";

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(result, names[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(names[i], result) < 0) {
                strcpy(result, names[i]);
            }
        }
    }

    printf("%s\n", result);

    return 0;
}
