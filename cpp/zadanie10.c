#include <stdio.h>
#include <string.h>
#include <ctype.h>


void isPalindrome(char *word, int *sentenceCount, FILE *outputFile) {
    int len = strlen(word);
    
    
    if (len > 0 && ispunct(word[len - 1])) {
        if (word[len - 1] == '.' || word[len - 1] == '!' || word[len - 1] == '?') {
            (*sentenceCount)++;
        }
        word[len - 1] = '\0'; 
        len--;
    }

    
    int isPal = 1; 
    for (int i = 0; i < len / 2; i++) {
        if (tolower(word[i]) != tolower(word[len - 1 - i])) {
            isPal = 0;
            break;
        }
    }
    
    
    if (isPal && len > 0) {
        fprintf(outputFile, "%s\n", word);
    }
}

int main() {
    FILE *inputFile = fopen("res.txt", "r");  
    FILE *outputFile = fopen("output10.txt", "w");
    
    char word[100];
    int sentenceCount = 0;
    
    
    while (fscanf(inputFile, "%s", word) == 1) {
        printf("%s ", word);
        isPalindrome(word, &sentenceCount, outputFile);
    }
    
    printf("\n");
    printf("Количество предложений в файле: %d\n", sentenceCount);
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}
