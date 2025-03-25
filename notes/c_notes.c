// Input/Output Functions (`<stdio.h>`)
#include <stdio.h>

int main() {
    char name[50];
    int age;

    printf("Enter your name: ");
    scanf("%s", name);  // Read a string (stops at space)

    printf("Enter your age: ");
    scanf("%d", &age);  // Read an integer

    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}

// String Functions (`<string.h>`)
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    printf("Length: %lu\n", strlen(str1));  // Get string length

    strcpy(str1, str2);  // Copy string
    printf("Copied: %s\n", str1);

    strcat(str1, "!!");  // Concatenate strings
    printf("Concatenated: %s\n", str1);

    if (strcmp(str1, "World!!") == 0)  // Compare strings
        printf("Strings match!\n");

    return 0;
}

// Memory Management Functions (`<stdlib.h>`)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*) malloc(5 * sizeof(int));  // Allocate memory

    for (int i = 0; i < 5; i++) 
        arr[i] = i * 2;

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    free(arr);  // Free allocated memory
    return 0;
}

// Mathematical Functions (`<math.h>`)
#include <stdio.h>
#include <math.h>

int main() {
    printf("Power: %.2f\n", pow(2, 3));  // 2^3
    printf("Square root: %.2f\n", sqrt(25));  // sqrt(25)
    printf("Absolute: %d\n", abs(-10));  // Absolute value
    printf("Ceil: %.2f\n", ceil(2.3));  // Round up
    printf("Floor: %.2f\n", floor(2.9));  // Round down

    return 0;
}

// Character Functions (`<ctype.h>`)
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'a';

    if (isalpha(ch)) printf("%c is a letter\n", ch);  // Check if letter
    if (isdigit('5')) printf("5 is a digit\n");  // Check if digit

    printf("Uppercase: %c\n", toupper(ch));  // Convert to uppercase
    printf("Lowercase: %c\n", tolower('A'));  // Convert to lowercase

    return 0;
}

// Standard Library Functions (`<stdlib.h>`)
#include <stdio.h>
#include <stdlib.h>

int main() {
    char numStr[] = "123";
    int num = atoi(numStr);  // Convert string to int

    printf("Converted number: %d\n", num);

    srand(42);  // Seed random number generator
    printf("Random: %d\n", rand());  // Generate random number

    exit(0);  // Exit program
}

// File Handling Functions (`<stdio.h>`)
#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "w");  // Open file for writing
    if (file == NULL) return 1;

    fprintf(file, "Hello, file!\n");  // Write to file
    fclose(file);  // Close file

    return 0;
}

// Memory Functions (`<string.h>`)
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello";
    char dest[10];

    memcpy(dest, src, strlen(src) + 1);  // Copy memory
    printf("Copied: %s\n", dest);

    memset(dest, 'A', 5);  // Fill memory with 'A'
    dest[5] = '\0';
    printf("Memset: %s\n", dest);

    return 0;
}

// String Notes
// Mutable string (array of chars)
char str[] = "hello world";

// Immutable string (string literal)
char *str2 = "str literal -> not mutable";
