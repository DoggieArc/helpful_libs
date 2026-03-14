#ifndef SORTLIB_H_INCLUDED
#define SORTLIB_H_INCLUDED

#define M_ASCEND true
#define M_DECEND false

template <typename Type>    //template for function of swapping 2 components
void swap(Type* a, Type* b) //need for bubble and shaker sorts
{
    Type temp = *a; //auxiliary variable
    *a = *b;
    *b = temp;
}

template <typename Type>    //template for bubble sort
void sortBubble(Type* array, int size, bool mode = M_ASCEND)
{
    for(int i = 0; i < size; ++i){  //finding max or min component
        for(int j = 0; j < size-i-1; ++j){
            if((array[j] > array[j+1]) == mode)
                swap(&array[j], &array[j+1]);
        }
    }
}

template <typename Type>    //template for shaker sort
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

template <typename Type>    //template for function of copy array
Type* copyArray(Type* array, int from, int to)  //need for merge and quick sorts
{
    Type* new_array = new Type[to-from];
    for(int i = 0; i < to-from; ++i)    //copying array
        new_array[i] = array[from+i];
    return new_array;   //return memory position
}

template <typename Type>    //template for merge sort
void sortMerge(Type* array, int size, bool mode = M_ASCEND)
{
    if(size > 1){
        int middle = size/2;    //variable of the middle of the array
        Type* left_array = copyArray(array, 0, middle);
        Type* right_array = copyArray(array, middle, size);

        sortMerge(left_array, middle, mode);
        sortMerge(right_array, size-middle, mode);

        int i = 0, j = 0, k = 0;    //position of slides:
        //i - left_array
        //j - right_array
        //k - array
        while(i < middle && j < size-middle)
        {
            if((left_array[i] < right_array[j]) == mode){
                array[k] = left_array[i];
                ++i;
            }
            else{
                array[k] = right_array[j];
                ++j;
            }
            ++k;
        }

        // Copy the remaining components of left_array,
        // if there are any
        while(i < middle){
            array[k] = left_array[i];
            ++i;
            ++k;
        }

        // Copy the remaining components of right_array,
        // if there are any
        while(j < size-middle){
            array[k] = right_array[j];
            ++j;
            ++k;
        }
    }
}

/*template <typename Type>    //template for quick sort
void sortQuick(Type* array, int size, bool mode = M_ASCEND)
{

}*/

#endif // SORTLIB_H_INCLUDED
