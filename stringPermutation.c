#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permute(char str[], char permutation[], int length, int index) {
    if (index == length) {
        printf("%s\n", permutation);
        return;
    }
    for (int i = 0; i < length; i++) {
        if (str[i] == '0') {
            continue;
        }
        
        char temp = str[i];
        permutation[index] = temp;
        str[i] = '0';
        permute(str, permutation, length, index + 1);
        str[i] = temp;
    }
}
int main() {
    char str[32];
    if (scanf("%s", str) == 1){
        int n = strlen(str);
        char *permutation = (char *)malloc((n + 1) * sizeof(char));
        permute(str, permutation, n, 0);
        free(permutation);
    } else {
        printf("Failed to read input.\n");
    }
    return 0;
}
