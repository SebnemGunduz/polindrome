#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Ignore spaces and non-alphanumeric characters
        if (!isalnum(str[left])) {
            left++;
            continue;
        }
        if (!isalnum(str[right])) {
            right--;
            continue;
        }

        // Compare characters
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }

        left++;
        right--;
    }

    return 1; // Is a palindrome
}

int main() {
    char word[100];

    printf("Bir kelime girin: ");
    fgets(word, sizeof(word), stdin);
    // Remove newline character at the end of the input
    word[strcspn(word, "\n")] = 0;

    if (is_palindrome(word)) {
        printf("'%s' bir palindrom kelimedir.\n", word);
    } else {
        printf("'%s' bir palindrom kelime değildir.\n", word);
    }

    return 0;
}