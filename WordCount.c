#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int countWords(FILE *file) {
    int count = 0;
    int inWord = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [parameter] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("Character count: %d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("Word count: %d\n", count);
    } else {
        printf("Invalid parameter.\n");
    }

    fclose(file);
    return 0;
}

