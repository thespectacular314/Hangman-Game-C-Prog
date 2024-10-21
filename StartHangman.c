# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "HangamanC.h"

int trials = 6, matchFound = 0, position = 0;
int temp_var, win_var, lengthOfHangmanWord, i, fillBlanks, AlreadyGuessed, Generate_Random_Line, temp_len;
char tempWord[100], Hangman_Output[100], AlphabetFromPlayer_2, disp_entered_alphabet[100] = "";

void StartHangman()
{
    srand(time(NULL)); // Generating a random instance(time) through time()
    Generate_Random_Line = rand() % (100); // Generating a random number

    char* input_1_player = WordGenerator(Player_choice, Generate_Random_Line);
    char* desc = DescriptionGenerator(Player_choice, Generate_Random_Line);

    system("cls");
    lengthOfHangmanWord = strlen(input_1_player);

    printf("\n\nENTER A CHARACTER TO GUESS THE WORD.\n");

    // Creating a blank space for the characters to be guessed "_ _ _"
    for (i = 0; i < lengthOfHangmanWord; i++) 
    {
        Hangman_Output[i] = '_';  // Creating another character array of just "_". 
        Hangman_Output[lengthOfHangmanWord] = '\0';   
    }

    printf("\n");

    // Creating the initial state of the word i.e with the blanks.
    for (i = 0; i < lengthOfHangmanWord; i++) 
    {
        printf(" ");
        printf("%c", Hangman_Output[i]);
    }

    int k = 0; // Temporary variable for the variable disp_entered_characters

    while (trials != 0) 
    {
        matchFound = 0;
        printf("\n\nNumber of Words: %i", lengthOfHangmanWord);
        printf("\n");

        printf("\nThe Description for the word is -- %s", desc);
        printf("\n");

        printf("\n\nALREADY ENTERED CHARACTERS: %s ",disp_entered_alphabet);

        printf("\n\n   Enter any alphabet of your choice:  ");
        scanf(" %c", &AlphabetFromPlayer_2);
        system("cls");  // To clear the terminal

        temp_len = strlen(disp_entered_alphabet); // finding the number of characters attempted by the player.


        // Checking whether if the user has already entered the character (if-yes display the statement).
        for (i = 0; i < temp_len; ++i)
        {
            if (disp_entered_alphabet[i] == AlphabetFromPlayer_2)
            {
                printf("\n\nYou have already enterd this character please try another one.");
                break;
            }
        }
        
        // Warning to enter only alphabets in lowercase.
        if (AlphabetFromPlayer_2 < 'a' || AlphabetFromPlayer_2 > 'z') 
        {
            system("cls");
            printf("\n\n\t Wrong input TRY AGAIN!! We only accept Alphabets.\n ");
            matchFound = 2;  // Creating an instance that user has entered a character other than that of LC alphabets.
        } 

        else 
        {
            if (matchFound != 2) 
            {
                for (temp_var = 0; temp_var < lengthOfHangmanWord; temp_var++) 
                {
                    if (AlphabetFromPlayer_2 == input_1_player[temp_var]) 
                    {
                        matchFound = 1;  // Creating an instance that user has guessed one of the right characters from the hangman word.
                    }
                }

                if (matchFound == 0) // Wrong guess
                {
                    AlreadyGuessed = 0;

                    for (i = 0; i < temp_len; ++i) 
                    {
                        if (disp_entered_alphabet[i] == AlphabetFromPlayer_2) 
                        {
                            AlreadyGuessed = 1;
                            HangmanDisplay(trials);
                            printf("\n\n\tYou have already entered this character.\n");
                        }
                    }

                    if (!AlreadyGuessed) 
                    {
                        --trials; // Deducting the trials by 1 from the total.
                        HangmanDisplay(trials);
                        getchar();
                        printf("\n\nYou have %i tries remaining.", trials);
                    }
                }

                else    // Right Guess
                {
                    for (temp_var = 0; temp_var < lengthOfHangmanWord; temp_var++) 
                    {
                        fillBlanks = 0;  // Temp variable used(indirectly) to fill up the blanked spaces
                        if (AlphabetFromPlayer_2 == input_1_player[temp_var]) 
                        {
                            position = temp_var;  // Tracking the index of the character found.
                            fillBlanks = 1;  // Blanked space needs to be filled.
                        }
                        if (fillBlanks == 1) 
                        {
                            for (i = 0; i < lengthOfHangmanWord; i++) 
                            {
                                if (i == position) 
                                {
                                    Hangman_Output[i] = AlphabetFromPlayer_2; // Placing up the right character in its position
                                } 
                                
                                else if (Hangman_Output[i] >= 'a' && Hangman_Output[i] <= 'z') 
                                {
                                    continue;
                                } 
                                
                                else 
                                {
                                    Hangman_Output[i] = '_';
                                }
                            }

                            tempWord[position] = AlphabetFromPlayer_2;
                            tempWord[lengthOfHangmanWord] = '\0'; 
                            win_var = strcmp(tempWord, input_1_player); // Comparision between the actual word and predicted word (True if 0)

                            if (win_var == 0) 
                            {
                                printf("\n\n\t\t The Word was %s", input_1_player);
                                printf("\n\n\t\t That's Brilliant!! You must be smart.");
                                printf("\n\n\t\t Congratualation!! For winning the game and saving our guy.\n\n");
                                getchar(); // Systems waits for an input (Anytype) before proceeding further

                            
                                int choice;
                                printf("\n\nIf you would like to play again PRESS 1.\nIf you want to check the rules PRESS 2.\nIf you would like EXIT the game PRESS 0.\nEnter your Choice: ");
                                scanf("%i", &choice);

                                if (choice == 1)
                                {
                                    system("cls");
                                    printf("\nPRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
                                    scanf("%i", &Player_choice);
                                    
                                    trials = 6;
                                    StartHangman();
                                }
                                else if (choice == 2)
                                {
                                    system("cls"); // Clears the terminal
                                    ShowRules();
                                }

                                else
                                {
                                    printf("\n\nEXITED. THANK YOU FOR PLAYING!! \n\n");
                                    exit(0); // Exited without any error
                                }
                            }
                        }
                    }
                }
            }
        }    

        // To display the present state of the Hangman_Output
        if (win_var != 0)
        {
            printf("\n\n\t");
            for (i = 0; i < lengthOfHangmanWord; i++) 
            {
                printf(" ");
                printf("%c", Hangman_Output[i]);
            }
        }      
        
        if (trials <= 0) 
        {
            printf("\n\n\t Sorry!! You lost the game.");
            printf("\n\n\t You Better Save him Next time.!!!");
            printf("\n\n\t The Word was %s", input_1_player);
            getchar();

            int choice;
            printf("\n\nIf you would like to play again PRESS 1.\nIf you want to check the rules PRESS 2.\nIf you would like EXIT the game PRESS 0.\nEnter your Choice: ");
            scanf("%i", &choice);

            if (choice == 1)
            {
                system("cls");
                printf("\nPRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
                scanf("%i", &Player_choice);
                trials = 6;  // Resetting trials to 6 for the next game.
                StartHangman();
            }

            else if (choice == 2)
            {
                system("cls");
                ShowRules();
            }

            else
            {
                printf("\n\nEXITED. THANK YOU FOR PLAYING!! \n\n");
                exit(0);
            }
        }
        
        
        disp_entered_alphabet[k] = AlphabetFromPlayer_2; // Displays the already enetered character
        ++k; // Incrementing k by 1
        
    }  
    
    getchar();

            
}