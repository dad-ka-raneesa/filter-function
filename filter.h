#ifndef __FILTER_H_
#define __FILTER_H_
typedef struct
{
  int length;
  int *values;
} Int_Array;

Int_Array *filter_even(int *array, int length);
Int_Array *create_dynamic_array(int length);
Int_Array *create_copy_of_array(Int_Array *evens, int length);
void display_int_array(Int_Array array);
#endif