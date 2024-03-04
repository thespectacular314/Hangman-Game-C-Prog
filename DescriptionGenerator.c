# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "HangamanC.h"

# define Descrp 200

char Generated_Description[100];

char* DescriptionGenerator(int Player_choice, int Generate_Random_Line)
{

    if (Player_choice == 1)
    {
        char* DESCRIPTION = (char*)malloc(Descrp * sizeof(char)); // Dynamic allocation for the variable DESCRIPTION.
        if (DESCRIPTION == NULL) 
        {
            printf("Memory allocation failed.\n"); // Throws an message when there's an issue in allocation.
            exit(EXIT_FAILURE);
        }

        printf("Enter a description about the word (use '_' for spaces): \n");
        scanf("%199s", DESCRIPTION);

        return DESCRIPTION;
    }

    else if (Player_choice == 2)
    {
        FILE* access_database = fopen("100WordDatabase.csv","r"); // Accessing the file
    
        if (access_database == NULL)
        {
            printf("Error Opening File");
            exit(1); // Exited with an error (No-File-Found)
        }

        char Line_dataset[200]; // Character array to store each line from the file 
        int Cursor_Line = 0;

        while (fgets(Line_dataset, sizeof(Line_dataset), access_database) != NULL) // Looping through all the lines 
        {
            if (Cursor_Line == Generate_Random_Line) // Random number will be generated from the StartHangman().
            {
                char *token = strtok(Line_dataset, "-"); // Tokenizing the character with the delimiter "-"
                token = strtok(NULL, "-"); // Tokenizing the rest of the characters from the line.
                strcpy(Generated_Description, token); // Copying the tokenized characters to Generated_Word.
                break;
            }

            ++Cursor_Line; // Incrementing the Cursor line
        }

        return Generated_Description; // Returning the Generated Description to StartHangman()

        fclose(access_database); // Closing the File.
    }
}