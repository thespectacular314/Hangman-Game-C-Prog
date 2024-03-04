# include <stdio.h>
# include <stdlib.h>
# include "HangamanC.h"

int Player_choice;

int main() 
{    
    int menu_choice;

    system("cls");
    printf("    WELCOME TO THE HANGMAN GAME!!   \n");
    printf("  Please press 'ENTER' to continue.    ");
    getchar();
    system("cls");
    printf("\t*****MAIN MENU*****\n\tStart Game -----> Press 1\n\tRules for the Game -----> Press 2");

    printf("\nEnter your choice: ");
    scanf("%i", &menu_choice);

    getchar();
    system("cls");


    if (menu_choice == 1) 
    {
         printf("PRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
         scanf("%i", &Player_choice);

        system("cls"); // Clear Terminal.
        getchar();
        StartHangman();            
    } 

    else if (menu_choice == 2)
    {
        ShowRules();
    }

    else
    {
        printf("ENTER A VALID CHOICE!! ");
        return main(); 
    }
     
}