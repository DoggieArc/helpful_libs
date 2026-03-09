#ifndef SORTLIB_H_INCLUDED
#define SORTLIB_H_INCLUDED

#define M_ASCEND true
#define M_DECEND false

template <typename Type>
void swap(Type* a, Type* b)
{
    Type temp = *a;
    *a = *b;
    *b = temp;
}

template <typename Type>
void sortBubble(Type* array, int size, bool mode = M_ASCEND)
{
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size-i-1; ++j){
            if((array[j] > array[j+1]) == mode)
                swap(&array[j], &array[j+1]);
        }
    }
}

template <typename Type>
void sortShaker(Type* array, int size, bool mode = M_ASCEND)
{
    int left_pos = 0, right_pos = size-1;
    bool swapped = true;
    while(left_pos < right_pos && swapped){
        swapped = false;
        for(int j = left_pos; j < right_pos; ++j){
            if((array[j] > array[j+1]) == mode){
                swap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        --right_pos;
        for(int j = right_pos; j > left_pos; --j){
            if((array[j] < array[j-1]) == mode){
                swap(&array[j], &array[j-1]);
                swapped = true;
            }
        }
        ++left_pos;
    }
}

#endif // SORTLIB_H_INCLUDED
