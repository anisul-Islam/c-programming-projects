
#include <stdio.h>

int main()
{
  int choice;
  float fahr, celsius;

  printf("Temperature Converter Started\n");
  printf("Choose 1. Fahrenheit to Celsius\n");
  printf("Choose 2. Celsius to Fahrenheit\n");

  scanf("%d", &choice);

  if (choice == 1)
  {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahr);

    celsius = (fahr - 32) / 1.8;

    printf("Temperature in Celsius: %.2f\n", celsius);
  }
  else if (choice == 2)
  {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahr = celsius * 1.8 + 32;

    printf("Temperature in Fahrenheit: %.2f\n", fahr);
  }
  else
  {
    printf("Invalid choice\n");
  }

  return 0;
}