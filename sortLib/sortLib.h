#ifndef SORTLIB_H_INCLUDED
#define SORTLIB_H_INCLUDED

#define M_ASCEND true
#define M_DECEND false

template <typename Type>    //template for function of swapping 2 components
void swap(Type* a, Type* b) //need for bubble, shaker and quick sorts
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

template <typename Type>    //template for function of the find minimum value
int Min(Type* array, int from, int to, bool mode)    // need for selection sort
{
    int index_min = from;
    for(int i = from+1; i < to; ++i){
        if((array[index_min] > array[i]) == mode)
            index_min = i;
    }
    return index_min;
}

template <typename Type>    //template for selection sort
void sortSelection(Type* array, int size, bool mode = M_ASCEND)
{
    int index_min;
    for(int i = 0; i < size; ++i){
        index_min = Min(array, i, size, mode);
        if(index_min == i)
            continue;

        swap(&array[i], &array[index_min]);
    }
}

template <typename Type>    //template for function of copy array
Type* copyArray(Type* array, int from, int to)  //need for merge sort
{
    Type* new_array = new Type[to-from];
    for(int i = 0; i < to-from; ++i)    //copying array
        new_array[i] = array[from+i];
    return new_array;   //return memory position
}

/*!!! NEED RECONSTRACT !!!
remove copy array*/
template <typename Type>    //template for merge sort
void sortMerge(Type* array, int size, bool mode = M_ASCEND)
{
    if(size > 1){
        int middle = size/2;    //variable of the middle of the array
        Type* left_array = copyArray(array, 0, middle);     //splitting the array
        Type* right_array = copyArray(array, middle, size);

        sortMerge(left_array, middle, mode);
        sortMerge(right_array, size-middle, mode);

        int i = 0, j = 0, k = 0;    //position of slides:
        //i - left_array
        //j - right_array
        //k - array
        while(i < middle && j < size-middle){    //merging
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

template <typename Type>    //template for quick sort
int partitionPivot(Type* array, int high, int low, bool mode = M_ASCEND){
    Type pivot = array[high];
    int pos = low;  //the slide for find component smaller then pivot

    for(int i = low; i < high; ++i){    //find component smaller then pivot
        if((array[i] < pivot) == mode){
            swap(&array[pos], &array[i]);
            ++pos;
        }
    }

    swap(&array[pos], &array[high]);    //swap pivot and last small element
    return pos;     //return pivot pos
}

template <typename Type>    //template for quick sort
void sortQuickSource(Type* array, int high, int low = 0, bool mode = M_ASCEND)
{
    if(low < high){
        int possition_pivot = partitionPivot(array, high, low, mode);   //finding pivot

        sortQuickSource(array, possition_pivot-1, low, mode);   //splitting the array
        sortQuickSource(array, high, possition_pivot+1, mode);
    }
}

template <typename Type>    //template for fix quick sort
void sortQuick(Type* array, int size, bool mode = M_ASCEND) {sortQuickSource(array, size-1, 0, mode);}


template <typename Type>    //template for insertion sort
void sortInsertion(Type* array, int size, bool mode = M_ASCEND)
{
    int j;  //position of the sorting value
    Type temp;
    for(int i = 1; i < size; ++i){  //check all elements
         temp = array[i];
         j = i - 1;

         while(j >= 0 && ((array[j] > temp) == mode)){  //reposition sorting element
             array[j + 1] = array[j];
             j = j - 1;

         array[j + 1] = temp;
         }
    }
}
#endif // SORTLIB_H_INCLUDED
