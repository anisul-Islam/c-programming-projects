#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
  char password[100];

  printf("Password: ");
  fgets(password, sizeof password, stdin); // anisul
  password[strcspn(password, "\n")] = '\0';

  int length = strlen(password);

  // printf("Length of password: %d\n", length);
  int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSymbol = 0;
  for (int i = 0; i < length; i++)
  {
    unsigned char c = (unsigned char)password[i];
    if (isupper(c))
    {
      hasUpper = 1;
    }
    else if (islower(c))
    {
      hasLower = 1;
    }
    else if (isdigit(c))
    {
      hasDigit = 1;
    }
    else
    {
      hasSymbol = 1;
    }
  }

  // step 3
  int score = 0;
  if (length >= 8)
    score++;
  if (length >= 12)
    score++;
  score = score + hasUpper + hasLower + hasDigit + hasSymbol;

  // step 4
  // password = Admin
  char lower[100];
  for (int i = 0; i <= length; i++)
  {
    lower[i] = tolower((unsigned char)password[i]);
  } // admin
  char common[6][12] = {"password", "123456", "admin", "password123", "12345678", "qwerty"};
  for (int w = 0; w < 6; w++)
  {
    if (strcmp(lower, common[w]) == 0)
    {
      score = score - 2;
      printf(" this is one of the most common passwords\n");
      break;
    }
  }

  // step 5 Annni
  for (int i = 2; i < length; i++)
  {
    if (password[i] == password[i - 1] &&
        password[i] == password[i - 2])
    {
      score--;
      printf(" has the same character three times in a row\n");
      break;
    }
  }

  // steps 6
  if (length < 8)
    printf("   tip: use at least 8 characters\n");
  if (!hasUpper)
    printf("   tip: add an uppercase letter\n");
  if (!hasLower)
    printf("   tip: add a lowercase letter\n");
  if (!hasDigit)
    printf("   tip: add a digit\n");
  if (!hasSymbol)
    printf("   tip: add a symbol like @ or #\n");

  // step 7
  printf("Score %d: ", score);
  if (score >= 5)
    printf("Strong\n");
  else if (score >= 3)
    printf("Medium\n");
  else
    printf("Weak\n");
  return 0;
}