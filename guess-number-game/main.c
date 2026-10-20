#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  int guessNumber, randomNumber;
  int startingRange = 1;
  int endingRange = 5;
  int attempt = 0;

  srand(time(NULL));
  randomNumber = rand() % endingRange + 1;

  printf("\nGuess Number Game.\n");

  while (1)
  {
    printf("\nGuess a number between %d-%d: ", startingRange, endingRange);
    scanf("%d", &guessNumber);

    if (guessNumber < 1 || guessNumber > 5)
    {
      printf("Invalid guess! Enter a number between %d-%d", startingRange, endingRange);
      continue;
    }

    attempt++;
    if (guessNumber > randomNumber)
    {
      printf("Too high! Try again.\n");
    }
    else if (guessNumber < randomNumber)
    {
      printf("Too Low! Try again.\n");
    }
    else
    {
      printf("Congratulations! You guessed the number.\n");
      printf("The correct number was %d.\n", randomNumber);
      printf("Total valid attempts: %d.\n", attempt);
      break;
    }
  }

  return 0;
}