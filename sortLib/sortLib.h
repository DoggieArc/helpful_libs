#ifndef SORTLIB_H_INCLUDED
#define SORTLIB_H_INCLUDED

#define M_ASCEND true
#define M_DECEND false

template <typename Type>    //function of swapping 2 components
void swap(Type* a, Type* b) //need for bubble and shaker sorts
{
    Type temp = *a; //auxiliary variable
    *a = *b;
    *b = temp;
}

template <typename Type>    //bubble sort
void sortBubble(Type* array, int size, bool mode = M_ASCEND)
{
    for(int i = 0; i < size; ++i){  //finding max or min component
        for(int j = 0; j < size-i-1; ++j){
            if((array[j] > array[j+1]) == mode)
                swap(&array[j], &array[j+1]);
        }
    }
}

template <typename Type>    //shaker sort
void sortShaker(Type* array, int size, bool mode = M_ASCEND)
{
    int left_pos = 0, right_pos = size-1;   //left and right slide
    bool swapped = true;
    while(left_pos < right_pos && swapped){
        swapped = false;
        for(int j = left_pos; j < right_pos; ++j){  //finding left component
            if((array[j] > array[j+1]) == mode){
                swap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        --right_pos;    //moving the right slide to the left
        for(int j = right_pos; j > left_pos; --j){  //finding right component
            if((array[j] < array[j-1]) == mode){
                swap(&array[j], &array[j-1]);
                swapped = true;
            }
        }
        ++left_pos;     //moving the left slide to the right
    }
}

#endif // SORTLIB_H_INCLUDED
