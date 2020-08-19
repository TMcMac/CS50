#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


/**
 * This simple program is meant to take in a 26 char alpha string and then
 * use that string to encrypt a plaintext message supplied by the user.
 * The program will then output the ciphertext
 * Return 0 for success, Return 1 for any error.
 */

int main(int argc, char **argv)
{
    int i, j, diff;
    string message;
    char ciphertext[256];
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string key = argv[1];
    for (i = 0; key[i] != '\0'; i++)
    {
        if (toupper(key[i]) < 65 || toupper(key[i]) > 90)
        {
            printf("The key must be 26 alpha characters.\n");
            return 1;
        }
        for (j = 0; key[j] != '\0'; j++)
        {
            if (key[i] == key[j] && i != j)
            {
                printf("The key must contain 26 unique alpha values.\n");
                return 1;
            }
        }
    }

    message = get_string("plaintext: ");
    // gets a message string from the user

    for (i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            diff = toupper(message[i]) - 65;
            // diff is the difference between the char in message and the letter A
            // We use diff to pick the letter we need out of our users provided key
            if (isupper(message[i]))
            {
                ciphertext[i] = toupper(key[diff]);
                // maintain upper case
            }
            else
            {
                ciphertext[i] = tolower(key[diff]);
                // maintain lower case
            }
        }
        else
        {
            ciphertext[i] = message[i];
            // if it is not an alpha char (punctuation of space) just copy over
        }
    }
    ciphertext[i] = '\0';
    // all string need to be nullbyte terminated

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}