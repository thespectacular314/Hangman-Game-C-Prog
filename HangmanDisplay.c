# include <stdio.h>
# include <stdlib.h>
# include "HangamanC.h"

// Displaying Hangman figure using printf()
void HangmanDisplay(int trials)                       
{
    switch(trials)
    {
        case 0:
            system("cls");
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||        /|\\");
            printf("\n\t||       / | \\");
            printf("\n\t||        / \\");
            printf("\n\t||       /   \\");
            printf("\n\t||=================");
            break;

        case 1:
            system("cls");
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||        /|\\");
            printf("\n\t||       / | \\");
            printf("\n\t||        /");
            printf("\n\t||       /");
            printf("\n\t||=================");
            break;

        case 2:
            system("cls");
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||        /|\\");
            printf("\n\t||       / | \\");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;

        case 3:
            system("cls");
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||         |\\");
            printf("\n\t||         | \\");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;

        case 4:
            system("cls");
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;

        case 5:
            system("cls");
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;
    }
}