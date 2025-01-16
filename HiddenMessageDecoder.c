
/* Description: Here this code uses the filename that was provided by the user and opens the file, this code extracts the first letter 
 of each word to decipher a hdden message. The code asks users to enter the filename, then reads the file to create the decoded message.
 A new file containing the original filename prefixed with "decoded_" is created after the output has been decoded. Here the code has 
 error handling for file operations and abides by given word and filename size restrictions.*/
// Name: Karthikeya Telapalli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Here I am defining constants
#define MAX_WORDS 1000              // This is the maximum no of words that the code reads from the file.
#define MAX_FILENAME_LENGTH 100     // This is maximum length that a filename should have.  

void decode(char words[][101], int num_words, char *result) {
    // Here it goes through each word once, then it obtains the first character.
    for(int i = 0; i < num_words; i++) {
        result[i] = words[i][0];
    }
    result[num_words] = '\0'; // Here we terminate the decoded string.
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char words[MAX_WORDS][101];
    char result[MAX_WORDS + 1];
    int num_words = 0;

    // Here we ask the user to enter a filename.
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Here we try to open the file using the name user has entered.  
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        // Here we display error and exit if we can not open the file
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    // Here after reading every word from the file, and then we add it to the words array.
    while(fscanf(file, "%100s", words[num_words]) != EOF && num_words < MAX_WORDS) {
        num_words++;
    }
    fclose(file); // Here we close the opened file.

    // Here we extract the hidden message from the words array, and use the decode function.
    decode(words, num_words, result);

    // Here we add "decoded_" to the original filename and create the output file's name.
    char output_filename[MAX_FILENAME_LENGTH + 8]; // Here we give additional space for "decoded_" prefix.
    snprintf(output_filename, sizeof(output_filename), "decoded_%s", filename);

    // Here we display the name of the output file.
    printf("Output file name:\n%s\n", output_filename);

    // Here we try to open the output file for writing.
    file = fopen(output_filename, "w");
    if(file == NULL) {
        // Here we display error and exit if we can not create the file. 
        printf("Error creating output file: %s\n", output_filename);
        return 1;
    }
    // Write the decoded message to the output file
    fprintf(file, "%s", result);
    fclose(file); // Here we close the file

    return 0;
}