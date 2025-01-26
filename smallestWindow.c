#include <stdio.h>
#include <string.h>
#include <limits.h>

void smallestWindow(char *str1, char *str2) {
    int str1_l = strlen(str1);
    int str2_l = strlen(str2);
    
    if (str2_l > str1_l) {
        printf("No such window exists\n");
        return;
    }

    int map_str2[256] = {0};
    for (int i = 0; i < str2_l; i++) {
        map_str2[str2[i]]++;
    }

    int map_str1[256] = {0};
    int left = 0, currWindowIndex = -1, minLen = INT_MAX;
    int count = 0;

    for (int right = 0; right < str1_l; right++) {
        map_str1[str1[right]]++;

        if (map_str1[str1[right]] <= map_str2[str1[right]]) {
            count++;
        }

        while (count == str2_l) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                currWindowIndex = left;
            }

            map_str1[str1[left]]--;
            if (map_str1[str1[left]] < map_str2[str1[left]]) {
                count--;
            }
            left++;
        }
    }

    if (currWindowIndex == -1) {
        printf("No such window exists\n");
    } else {
        printf("Smallest window: ");
        for (int i = currWindowIndex; i < currWindowIndex + minLen; i++) {
            printf("%c", str1[i]);
        }
        printf("\n");
    }
}
int main() {
    char str1[100], str2[100];
    
    printf("Enter the main string (str1): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Enter the pattern string (str2): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    smallestWindow(str1, str2);

    return 0;
}