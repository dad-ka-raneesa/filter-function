#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

Int_Array *create_dynamic_array(int length)
{
  Int_Array *array = malloc(sizeof(Int_Array));
  array->length = 0;
  array->values = malloc(sizeof(int) * length);
  return array;
}

Int_Array *create_copy_of_array(Int_Array *evens, int length)
{
  Int_Array *copy = create_dynamic_array(length);
  for (int i = 0; i < length; i++)
  {
    copy->values[i] = evens->values[i];
    copy->length++;
  }
  free(evens);
  return copy;
}

Int_Array *filter_even(int *numbers, int length)
{
  Int_Array *evens = create_dynamic_array(length);
  for (int index = 0; index < length; index++)
  {
    if (numbers[index] % 2 == 0)
    {
      evens->values[evens->length] = numbers[index];
      evens->length++;
    }
  }
  return create_copy_of_array(evens, evens->length);
}

void display_int_array(Int_Array array)
{
  printf("\nEven Numbers :\n");
  for (size_t i = 0; i < array.length; i++)
  {
    printf("%d ", array.values[i]);
  }
  printf("\n");
}