#include <stdio.h>
#include <ctype.h>

#define PLAYER_BG "\033[30;102m"
#define RESET "\033[0m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define GRAY "\033[90m"
#define RED "\033[91m"
#define CYAN "\033[96m"
#define LAND "\033[32m"

#define MAX_SIZE 5
int main()
{
  // step 1 (Task): Create the island Map using 2d character array
  /**
   * . => Empty Land
   * # => Wall
   * T => Treasure
   * X => Trap
   * E => Exit
   */
  //
  char map[MAX_SIZE][MAX_SIZE] = {
      {'.', '.', '.', '.', '.'},
      {'.', '#', '.', 'T', '.'},
      {'.', '.', 'X', '.', '.'},
      {'T', '#', '.', '#', '.'},
      {'.', '.', '.', '.', 'E'},
  };
  int playerRow = 0;
  int playerCol = 0;

  int nextRow, nextCol;
  char move;

  // step c: track the score and collect the treasures
  int treasures = 0;
  int score = 0;
  int totalTreasures = 2;
  int movesLeft = 20;
  int gameWon = 0;
  int gameLost = 0;

  const char *message = "Welcome to Treasure Island!";

  while (1)
  {
    printf("\033[2J\033[H");

    // step 2 (Task): Display the map
    for (int row = 0; row < MAX_SIZE; row++)
    {
      for (int col = 0; col < MAX_SIZE; col++)
      {
        printf("+---");
      }
      printf("+\n");

      for (int col = 0; col < MAX_SIZE; col++)
      {
        printf("| ");
        if (row == playerRow && col == playerCol)
        {
          printf(PLAYER_BG "P " RESET);
        }
        else
        {
          // printf("%c ", map[row][col]);
          switch (map[row][col])
          {
          case '.':
            printf(LAND ". " RESET);
            break;

          case '#':
            printf(GRAY "# " RESET);
            break;

          case 'T':
            printf(YELLOW "T " RESET);
            break;

          case 'X':
            printf(RED "X " RESET);
            break;

          case 'E':
            printf(CYAN "E " RESET);
            break;

          default:
            break;
          }
        }
      }
      printf("|\n");
    }
    for (int col = 0; col < MAX_SIZE; col++)
    {
      printf("+---");
    }
    printf("+\n");

    printf("\n");
    printf("================================\n");
    printf("           GAME STATUS          \n");
    printf("================================\n");
    printf("Score              : %d\n", score);
    printf("Treasures Collected: %d/%d\n", treasures, totalTreasures);
    printf("Moves Left         : %d\n", movesLeft);
    printf("--------------------------------\n");
    printf("Message: %s\n", message);
    printf("================================\n\n");

    // reset the next position before every move
    nextRow = playerRow;
    nextCol = playerCol;

    // step 4 (Task): Read Movement commands (U/D/L/R OR Q to Quit: )
    printf("Move U/D/L/R OR Q to Quit: ");
    if (scanf(" %c", &move) != 1)
    {
      message = "Input ended. Game Over.";
      break;
    }
    move = toupper((unsigned char)move);

    // calculate the next position
    switch (move)
    {
    case 'U':
      nextRow--;
      message = "Move up.";
      break;

    case 'D':
      nextRow++;
      message = "Move down .";
      break;

    case 'L':
      nextCol--;
      message = "Move left.";
      break;

    case 'R':
      nextCol++;
      message = "Move right";
      break;

    case 'Q':
      printf("\n You Quit the Game.\n");
      return 0;

    default:
      message = "Invalid Command. Use U, D, L, R or Q.";
      continue;
    }

    // check the island boundaries
    if (nextRow < 0 || nextRow >= MAX_SIZE ||
        nextCol < 0 || nextCol >= MAX_SIZE)
    {
      message = "You cannot leave the island!.";
    }
    // check whether a wall blocks the path
    else if (map[nextRow][nextCol] == '#')
    {
      message = "A wall blocks your path!.";
    }
    // step 8 - require all treasures before exiting
    else if (map[nextRow][nextCol] == 'E' && treasures < totalTreasures)
    {
      message = "Collect all treasures before exiting!.";
    }
    // move the player if the move is valid
    else
    {
      playerRow = nextRow;
      playerCol = nextCol;
      movesLeft--;

      if (map[playerRow][playerCol] == 'T')
      {
        treasures++;
        score += 50;
        message = "You found a treasure! +50 points.";
        map[playerRow][playerCol] = '.';
      }

      // step 7: check for a trap
      else if (map[playerRow][playerCol] == 'X')
      {
        score -= 20;
        if (score < 0)
        {
          score = 0;
        }
        message = "You stepped on a trap! -20 points.";
      }
      else
      {
        message = "Move Completed Successfully.";
      }

      // step 8 - check whether the player won
      if (map[playerRow][playerCol] == 'E')
      {
        score += 100;
        gameWon = 1;
        message = "Congratulations! You won! +100 points";
        break;
      }
    }

    if (movesLeft == 0)
    {
      gameLost = 1;
      message = "Game over! You ran out of moves.";
      break;
    }
  }

  printf("\033[2J\033[H");

  // step 2 (Task): Display the map
  for (int row = 0; row < MAX_SIZE; row++)
  {
    for (int col = 0; col < MAX_SIZE; col++)
    {
      printf("+---");
    }
    printf("+\n");

    for (int col = 0; col < MAX_SIZE; col++)
    {
      printf("| ");
      if (row == playerRow && col == playerCol)
      {
        printf(PLAYER_BG "P " RESET);
      }
      else
      {
        // printf("%c ", map[row][col]);
        switch (map[row][col])
        {
        case '.':
          printf(LAND ". " RESET);
          break;

        case '#':
          printf(GRAY "# " RESET);
          break;

        case 'T':
          printf(YELLOW "T " RESET);
          break;

        case 'X':
          printf(RED "X " RESET);
          break;

        case 'E':
          printf(CYAN "E " RESET);
          break;

        default:
          break;
        }
      }
    }
    printf("|\n");
  }
  for (int col = 0; col < MAX_SIZE; col++)
  {
    printf("+---");
  }
  printf("+\n");
  printf("\n===============================================\n");

  // step 8: display the final result after winning
  if (gameWon)
  {
    printf("                YOU WIN!\n");
  }
  else if (gameLost)
  {
    printf("                YOU LOSE!\n");
  }
  else
  {
    printf("                GAME OVER!\n");
  }
  printf("================================\n");
  printf("Score              : %d\n", score);
  printf("Treasures Collected: %d/%d\n", treasures, totalTreasures);
  printf("Moves Left         : %d\n", movesLeft);
  printf("--------------------------------\n");
  printf("Message: %s\n", message);
  printf("================================\n\n");

  return 0;
}