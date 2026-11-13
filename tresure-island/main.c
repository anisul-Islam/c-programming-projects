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

// Game rules in one place
#define START_MOVES 20
#define TREASURE_POINTS 50
#define TRAP_PENALTY 20
#define EXIT_BONUS 100

// message numbers:
#define MSG_WELCOME 0
#define MSG_INPUT_ENDED 1
#define MSG_INVALID 2
#define MSG_EDGE 3
#define MSG_WALL 4
#define MSG_LOCKED 5
#define MSG_TREASURE 6
#define MSG_TRAP 7
#define MSG_MOVED 8
#define MSG_WIN 9
#define MSG_NO_MOVES 10

// function prototypes
int countTreasures(char map[][MAX_SIZE]);
void drawMap(char map[][MAX_SIZE], int playerRow, int playerCol);
void drawCell(char cell);
void printStatus(int score, int treasures, int totalTreasures, int movesLeft, int messageCode);
void printMessage(int messageCode);
void printResult(int gameWon, int gameLost);
int isInside(int row, int col);
int scoreAfterTrap(int score);

int main()
{
  // step 1 (Task): Create the island Map using 2d character array

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
  int totalTreasures = countTreasures(map);
  int movesLeft = START_MOVES;
  int gameWon = 0;
  int gameLost = 0;
  int messageCode = MSG_WELCOME;

  while (1)
  {
    printf("\033[2J\033[H");

    // step 2 (Task): Display the map
    drawMap(map, playerRow, playerCol);

    printStatus(score, treasures, totalTreasures, movesLeft, messageCode);

    // reset the next position before every move
    nextRow = playerRow;
    nextCol = playerCol;

    // step 4 (Task): Read Movement commands (U/D/L/R OR Q to Quit: )
    printf("Move U/D/L/R OR Q to Quit: ");
    if (scanf(" %c", &move) != 1)
    {
      messageCode = MSG_INPUT_ENDED;
      break;
    }
    move = toupper((unsigned char)move);

    // calculate the next position
    switch (move)
    {
    case 'U':
      nextRow--;
      break;

    case 'D':
      nextRow++;
      break;

    case 'L':
      nextCol--;
      break;

    case 'R':
      nextCol++;
      break;

    case 'Q':
      printf("\n You Quit the Game.\n");
      return 0;

    default:
      messageCode = MSG_INVALID;
      continue;
    }

    // check the island boundaries
    if (!isInside(nextRow, nextCol))
    {
      messageCode = MSG_EDGE;
    }
    // check whether a wall blocks the path
    else if (map[nextRow][nextCol] == '#')
    {
      messageCode = MSG_WALL;
    }
    // step 8 - require all treasures before exiting
    else if (map[nextRow][nextCol] == 'E' && treasures < totalTreasures)
    {
      messageCode = MSG_LOCKED;
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
        score += TREASURE_POINTS;
        messageCode = MSG_TREASURE;
        map[playerRow][playerCol] = '.';
      }

      // step 7: check for a trap
      else if (map[playerRow][playerCol] == 'X')
      {
        score = scoreAfterTrap(score);
        messageCode = MSG_TRAP;
      }
      else
      {
        messageCode = MSG_MOVED;
      }

      // step 8 - check whether the player won
      if (map[playerRow][playerCol] == 'E')
      {
        score += EXIT_BONUS;
        gameWon = 1;
        messageCode = MSG_WIN;
        break;
      }
    }

    if (movesLeft == 0)
    {
      gameLost = 1;
      messageCode = MSG_NO_MOVES;
      break;
    }
  }

  printf("\033[2J\033[H");

  // step 2 (Task): Display the map
  drawMap(map, playerRow, playerCol);

  // step 8: display the final result after winning
  printResult(gameWon, gameLost);
  printStatus(score, treasures, totalTreasures, movesLeft, messageCode);

  return 0;
}

void printResult(int gameWon, int gameLost)
{

  printf("\n================================\n");

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
}

int countTreasures(char map[][MAX_SIZE])
{
  int count = 0;
  for (int row = 0; row < MAX_SIZE; row++)
  {
    for (int col = 0; col < MAX_SIZE; col++)
    {
      if (map[row][col] == 'T')
      {
        count++;
      }
    }
  }
  return count;
}

// draw the cell
void drawCell(char cell)
{
  switch (cell)
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

// draws the whole map with the player on top
void drawMap(char map[][MAX_SIZE], int playerRow, int playerCol)
{
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
        // cell draw
        drawCell(map[row][col]);
      }
    }
    printf("|\n");
  }
  for (int col = 0; col < MAX_SIZE; col++)
  {
    printf("+---");
  }
  printf("+\n");
}

// turns a meassge number into text
void printMessage(int messageCode)
{
  switch (messageCode)
  {
  case MSG_WELCOME:
    printf("Welcome to Treasure Island !");
    break;
  case MSG_INPUT_ENDED:
    printf("Input ended. Game Over.");
    break;
  case MSG_INVALID:
    printf("Invalid Command. Use U, D, L, R or Q.");
    break;
  case MSG_EDGE:
    printf("You cannot leave the island!");
    break;
  case MSG_WALL:
    printf("A wall blocks your path!");
    break;
  case MSG_LOCKED:
    printf("Collect all treasures before exiting!");
    break;
  case MSG_TREASURE:
    printf("You found a treasure! +%d points.", TREASURE_POINTS);
    break;
  case MSG_TRAP:
    printf("You stepped on a trap! -%d points.", TRAP_PENALTY);
    break;
  case MSG_MOVED:
    printf("Move Completed Successfully.");
    break;
  case MSG_WIN:
    printf("Congratulations! You won! +%d points", EXIT_BONUS);
    break;
  case MSG_NO_MOVES:
    printf("Game over! You ran out of moves.");
    break;
  }
  printf("\n");
}

int isInside(int row, int col)
{
  return row >= 0 && row < MAX_SIZE &&
         col >= 0 && col < MAX_SIZE;
}

int scoreAfterTrap(int score)
{
  score -= TRAP_PENALTY;
  if (score < 0)
  {
    score = 0;
  }
  return score;
}

void printStatus(int score, int treasures, int totalTreasures, int movesLeft, int messageCode)
{
  printf("\n");
  printf("================================\n");
  printf("           GAME STATUS          \n");
  printf("================================\n");
  printf("Score              : %d\n", score);
  printf("Treasures Collected: %d/%d\n", treasures, totalTreasures);
  printf("Moves Left         : %d\n", movesLeft);
  printf("--------------------------------\n");
  printf("Message: ");
  printMessage(messageCode);
  printf("================================\n\n");
}