#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char word[] = "void";
    char buffer[100]; // Buffer to store characters read from the file

    // Open the file
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Replace occurrences of the word with spaces
        char *pos = buffer;
        while ((pos = strstr(pos, word)) != NULL) {
            memset(pos, ' ', strlen(word));
            pos += strlen(word);
        }
        // Write the modified line back to the file
        fseek(file, -strlen(buffer), SEEK_CUR);
        fputs(buffer, file);
    }

    // Close the file
    fclose(file);

    printf("Occurrences of the word 'void' have been removed from the file.\n");

    return 0;
}
