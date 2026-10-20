# 🎯 Guess the Number Game in C

A simple, interactive number guessing game built with the C programming language. The program generates a random number between 1 and 100 and challenges the user to guess it.

The game provides hints after each guess, validates the input range, and tracks the number of valid attempts needed to find the correct number.

## 📌 Project Overview

The goal of this project is to practice fundamental C programming concepts, including random number generation, loops, conditional statements, user input, and counters.

## ✨ Features

- 🎲 **Random Number Generation:** Generates a random number between 1 and 100 using `rand()`.
- 🔁 **Repeated Guessing:** Uses a loop to keep the game running until the correct number is found.
- ⬆️ **Too High Hint:** Tells the user when their guess is greater than the target number.
- ⬇️ **Too Low Hint:** Tells the user when their guess is less than the target number.
- ✅ **Input Validation:** Rejects guesses outside the range of 1 to 100.
- 🔢 **Attempt Counter:** Counts valid guesses only. Invalid guesses do not increase the counter.
- 🏆 **Winning Message:** Congratulates the user and displays the correct number and total attempts.

## 🛠️ Technologies Used

- **Language:** C
- **Standard Libraries:**
  - `stdio.h` for input and output
  - `stdlib.h` for random number generation
  - `time.h` for initializing the random number generator

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
cd <your-project-folder>
```

Replace the placeholders with your repository URL and project folder name.

### 2. Compile the Program

If you have GCC installed, run:

- check gcc: for mac `gcc -v` or for windows ``gcc -version`

```bash
gcc main.c -o guess_game
```

### 3. Run the Game

On Linux or macOS:

```bash
./guess_game
```

On Windows:

```bash
guess_game.exe
```

For Windows, run the executable from Command Prompt or PowerShell in the project directory.

## 🎮 How to Play

1. Start the program.
2. Read the instructions displayed on the screen.
3. Enter an integer between 1 and 100.
4. Follow the hints:
   - **Too high:** Guess a smaller number.
   - **Too low:** Guess a larger number.

5. Continue guessing until you find the correct number.
6. View your total number of valid attempts.

Invalid guesses outside the allowed range are rejected and do not count as attempts.

## 💻 Example Output

```text
Guess Number Game
Guess a number between 1 and 100.
Enter your guess: 150
Invalid guess! Enter a number between 1 and 100.
Enter your guess: 50
Too high! Try again.
Enter your guess: 25
Too low! Try again.
Enter your guess: 35
Congratulations! You guessed the number.
The correct number was 35.
Total valid attempts: 3
```

_Note: This is an example. The target number and hints will vary each time the game runs._

## 📚 Concepts Practiced

This project covers the following C programming concepts:

- Variables and data types
- Standard input and output using `printf()` and `scanf()`
- Random number generation with `rand()`
- Random number generator initialization with `srand()` and `time(NULL)`
- Arithmetic operators and the modulo operator (`%`)
- Conditional statements: `if`, `else if`, and `else`
- Logical operators: `||`
- Infinite loops using `while (1)`
- Loop control statements: `continue` and `break`
- Input validation
- Counter variables and increment operators (`++`)

## 🗂️ Project Structure

```text
guess-number-game/
├── main.c
└── README.md
```

## 🎯 Learning Objectives

By completing this project, you will learn how to:

- Generate and use random numbers in C.
- Build interactive programs using loops.
- Make decisions using conditional statements.
- Validate user input before processing it.
- Count attempts without including invalid guesses.
- Control program execution using `break` and `continue`.

## 🔮 Future Improvements

Possible extensions for this project include:

- [ ] Handle non-numeric input safely.
- [ ] Add difficulty levels, such as Easy, Medium, and Hard.
- [ ] Limit the number of guesses.
- [ ] Allow the user to play multiple rounds.
- [ ] Display a score based on the number of attempts.
- [ ] Ask the user whether they want to play again.

## 👨‍💻 Author

Created as a C programming practice project to strengthen problem-solving skills and understand the fundamentals of programming.

## 📄 License

This project is open for learning and personal practice. Add a license file if you want to specify the terms under which others may use, modify, or distribute your code.
