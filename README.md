# Hidden Message Decoder

This C program reads a text file provided by the user, extracts the first letter of each word to form a hidden message, and saves the decoded message into a new file prefixed with `decoded_`.

## Features
- Reads words from a user-provided text file.
- Extracts the first character from each word to form a hidden message.
- Saves the decoded message in a new file named `decoded_<original_filename>`.
- Includes error handling for file operations.
- Adheres to file name and word length restrictions.

## Usage
1. Enter the filename of the text file containing the words.
2. The program extracts the first letter of each word to form the hidden message.
3. The decoded message is saved to a new file with a prefix `decoded_`.

## File and Word Size Restrictions
- Maximum file name length: 100 characters.
- Maximum word length: 100 characters.
- Maximum number of words in the file: 1000.

## How to Compile and Run
1. Save the program as `hidden_message_decoder.c`.
2. Compile the program:
   ```bash
   gcc hidden_message_decoder.c -o hidden_message_decoder
