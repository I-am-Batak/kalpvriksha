#include <stdio.h>
#include <stdlib.h>

void toString(int num, char numString[]) {
    int index = 0;
    int sign = 1;
    char tempString[100];
    
    if (num < 0) {
        sign = -1;
        num = num * -1;
    }

    if (num == 0) {
        numString[index++] = '0';
        numString[index] = '\0';
        return;
    }

    while (num != 0) {
        tempString[index++] = (num % 10) + '0';
        num = num / 10;
    }

    if (sign == -1) {
        tempString[index++] = '-';
    }

    tempString[index] = '\0';

    int i = 0;
    while (index > 0) {
        numString[i++] = tempString[index - 1];
        index--;
    }

    numString[i] = '\0';
}

void compressString(char stringIN[], char stringOUT[]) {
    int index = 0;
    int i = 0;

    while (stringIN[index] != '\0' && stringIN[index] != '\n') {
        char InChar = stringIN[index];
        int count = 1;
        
        while (stringIN[index + 1] == InChar) {
            count++;
            index++;
        }

        stringOUT[i++] = InChar;

        if (count > 1) {
            char countString[100];
            toString(count, countString);
            for (int j = 0; countString[j] != '\0'; j++) {
                stringOUT[i++] = countString[j];
            }
        }
        index++;
    }
    stringOUT[i] = '\0';
}

int main() {
    char inputString[100];
    char compressedString[100];
    fgets(inputString, 100, stdin);
    compressString(inputString, compressedString);
    printf("%s", compressedString);
    return 0;
}
