# include <stdio.h>
# include <stdlib.h>
# include "HangamanC.h"

int Player_choice;

void ShowRules()
{
    printf("RULES FOR MULTI-PLAYER: \n\n");
    printf("1. 'PLAYER-1' HAS TO GIVE A WORD IN LOWER CASE WITH A DESCRIPTION ABOUT IT.\n2. 'PLAYER-2' HAS TO GUESS THE WORD FROM THE DESCRIPTION GIVEN AND BLANKED SPACES (TO GUESS THE NUMBER OF WORDS).\n3. PLAYER 2 GETS 6 INCORRECT TRIALS AND HAS TO GUESS THE RIGHT WORD BEFORE YOUR TRIALS GETS OVER.\n4. EACH TIME YOU GUESS THE WRONG LETTER A BODY PART WILL BE DRAWN TO COMPLETE THE HANGMAN.\n5. EACH TIME YOU GUESS THE RIGHT LETTER THAT LETTER WOULD BE PLAYED AT ITS POSITION AS THE ACTUAL WORD, BY THIS YOU WILL BE ABLE TO GUESS OTHER LETTERS TO COMPLETE THE WORD.\n6. GUESS THE RIGHT WORD BEFORE THE HANGMAN VISUAL IS COMPLETED ORELSE IT WOULD BE A **GAME-OVER**.");
    printf("\n");
    printf("\n\nRULES FOR SINGLE-PLAYER: \n\n");
    printf("A RANDOM WORD AND DESCRIPTION WILL BE GENERATED FROM OUR DATABASE. THE OTHER RULES ARE AS SAME AS MULTI-PLAYER");
    printf("\n\n \t BEWARE!!");
    
    int choice;
    printf("\n\nIf you want to start the game now please enter 1 or if you want to exit enter 0: ");
    scanf("%i", &choice);

    if (choice == 1)
    {
        printf("PRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
        scanf("%i", &Player_choice);
        system("cls");
        StartHangman();
    }
    else if (choice == 0)
    {
        printf("\n\nExited. Thank you!");
        exit(0); // Exited with no error.
    }
}