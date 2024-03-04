# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "HangamanC.h"

# define Word 100   // setting up a macro called "Word" of size 100 (Global instance)

char Generated_Word[100];         

char* WordGenerator(int Player_choice, int Generate_Random_Line) 
{
    if (Player_choice == 1)
    {
        char* WORD = (char*)malloc(Word * sizeof(char));  // Dynamic allocation for the variable WORD.
        
        if (WORD == NULL) 
        {
            printf("Memory allocation failed.\n");   // Throws message when there's an issue in allocation.
            exit(EXIT_FAILURE);
        }

        printf("Enter your Word: ");
        scanf("%99s", WORD);  

        return WORD;
    }

    // Single-Player System
    else if (Player_choice == 2)
    {
        int Dataset_Length;
        FILE* access_database = fopen("100WordDatabase.csv","r");  // Accessing the file
        
        if (access_database == NULL)
        {
            printf("Error Opening File");
            exit(1); // Exited with an error (No-File-Found)
        }

        char Line_dataset[1000];  // Character array to store each line from the file 
        int Cursor_Line = 0;

        while (fgets(Line_dataset, sizeof(Line_dataset), access_database) != NULL) // Looping through all the lines 
        {
            if (Cursor_Line == Generate_Random_Line) // Random number will be generated from the StartHangman().
            {
                char *token = strtok(Line_dataset, "-");  // Tokenizing the character with the delimiter "-"
                strcpy(Generated_Word, token); // Copying the tokenized word to Generated_Word.
                break;
            }

            ++Cursor_Line; // Incrementing the Cursor line
        }

        return Generated_Word; // Returning the Generated Word to StartHangman()
        fclose(access_database); // Closing the File.
    }

    else
    {
        printf("Enter a Valid choice between 1 and 2");
    }

}