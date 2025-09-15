#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, j;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        freq[(int)str[i]]++;

        int found = 0;
        for (j = 0; j <= i; j++) {
            if (freq[(int)str[j]] == 1) {
                printf("%c ", str[j]);
                found = 1;
                break;
            }
        }
        if (!found) printf("-1 ");
    }
    printf("\n");
    return 0;
}
