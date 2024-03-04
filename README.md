# Hangman-Game-C-Prog
I have implemented the famous Hangman Game using C-Programming
# HANGMAN GAME IN C

This is a simple implementation of the classic Hangman game in C programming language. The game randomly selects a word from a predefined list (HERE in this case a CSV file "100WordDatabase"), and the player(s) have to guess the word letter by letter. With each incorrect guess, a part of the hangman is drawn. 

- The player(s) win if they can guess the word before the entire hangman is drawn, and lose if the hangman is complete before guessing the word.

- I have used very basic concepts of C Programming(like string manipulation, pointers, etc.) which makes the beginners understand it in a much easier way.

- **NOTE**
    * This is NOT the most EFFICIENT Code. I have tried to keep it as basic as possible. Meanwhile, I'll still try to make it a better one and commit an update within this repo.

    * This is a part of my first-year project. If ANY mistakes are found please let me know. And ANY type of suggestions regarding this Project are welcomed.

- **ISSUES**
    * I have found two issues in this code, one being the runtime and accepting space characters " " (My code does not accept SPACES during Input).
    * KINDLY LET ME KNOW IF THERE'S ANY MORE ISSUES.

## C-Concepts Used (Most Preferably)
- Strings
- Pointers
- Dynamic Memory Allocation

## Features

- Random selection of words from a predefined list.
- Simple ASCII art for hangman visualization.
- Error checking for invalid inputs.
- Single-player and multiplayer gameplay modes.

## Getting Started

To run the game on your local machine, follow these steps:

1. Clone this repository to your local machine using `git clone <URL of this REPO>`.
2. Navigate to the project directory.
3. Compile the source code using a C compiler (e.g., GCC): `gcc Main.c ShowRules.c StartHangman.c WordGenerator.c DescriptionGenerator.c HangmanDisplay.c -o hangman`.
4. Run the compiled executable: `./hangman`.

## Usage

### Single Player Mode

- Upon running the game, you will be prompted to guess a letter.
- Enter a letter and press enter.
- If the letter is correct, it will be revealed in the word.
- If the letter is incorrect, a part of the hangman will be drawn.
- Keep guessing letters until you either guess the word or the hangman is complete.

### Multiplayer Mode

- In multiplayer mode, one player enters the word to be guessed, and the other player(s) try to guess it.
- The player entering the word should input the word without revealing it to the other player(s).
- The guessing player(s) take turns guessing letters.
- If a guessed letter is correct, it will be revealed in the word. Otherwise, a part of the hangman will be drawn.
- The guessing player(s) win if they guess the word before the hangman is complete, and lose if the hangman is complete before guessing the word.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to fork this repository, make your changes, and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgements

- ASCII art for hangman visualization adapted from various sources on the internet.
- Special thanks to all contributors who helped improve this project.

