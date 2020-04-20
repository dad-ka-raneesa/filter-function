#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int length;
  int *values;
} Dynamic_Array;

Dynamic_Array *create_dynamic_array(int length)
{
  Dynamic_Array *array = malloc(sizeof(Dynamic_Array));
  array->length = 0;
  array->values = malloc(sizeof(int) * length);
  return array;
}

Dynamic_Array *create_copy_of_array(Dynamic_Array *evens, int length)
{
  Dynamic_Array *copy = create_dynamic_array(length);
  for (int i = 0; i < length; i++)
  {
    copy->values[i] = evens->values[i];
    copy->length++;
  }
  free(evens);
  return copy;
}

Dynamic_Array *filter_even(int *numbers, int length)
{
  Dynamic_Array *evens = create_dynamic_array(length);
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

  Dynamic_Array *evens_list = filter_even(values, length);

  printf("\nEven Numbers :\n");
  for (int index = 0; index < (evens_list->length); index++)
  {
    printf("%d\n", evens_list->values[index]);
  }

  free(values);
  free(evens_list);
  return 0;
}