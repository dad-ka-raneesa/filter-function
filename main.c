#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

int main(void)
{
  int length;

  printf("Enter the amount of numbers :");
  scanf("%d", &length);

  int *values = malloc(sizeof(int) * length);

  for (int i = 0; i < length; i++)
  {
    printf("Enter number %02d:", i + 1);
    scanf("%d", (values + i));
  }

  Int_Array *evens_list = filter_even(values, length);
  display_int_array(*evens_list);

  free(values);
  free(evens_list);
  return 0;
}