#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sortLib.h"

#define SIZE 16
#define MAX_VALUE 10000
#define MIN_VALUE 0

using namespace std;

template <typename Type>
void fillWithRandom(Type* array, int size)
{
    srand(time(NULL));
    for(int i = 0; i < size; ++i)
        array[i] = (double)(rand() % (MAX_VALUE-MIN_VALUE) + MIN_VALUE+1)/100;
}

template <typename Type>
void printArray(Type* array, int size)
{
    for(int i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << endl;
}

int main()
{
    char method;
    double* array = new double[SIZE];

    fillWithRandom(array, SIZE);
    cout << "The array: ";
    printArray(array, SIZE);

    cout << "1) Bubble sort" << endl
    << "2) Shaker sort" << endl
    << "3) Select sort" << endl
    << "4) Merge sort" << endl
    << "5) Quick sort" << endl
    << "6) Insertion sort" << endl
    << "Choose method of sort: ";
    cin >> method;
    switch(method){
        case '1':
            sortBubble(array, SIZE);
            printArray(array, SIZE);
            sortBubble(array, SIZE, M_DECEND);
            printArray(array, SIZE);
            break;
        case '2':
            sortShaker(array, SIZE);
            printArray(array, SIZE);
            sortShaker(array, SIZE, M_DECEND);
            printArray(array, SIZE);
            break;
        case '4':
            sortMerge(array, SIZE);
            printArray(array, SIZE);
            sortMerge(array, SIZE, M_DECEND);
            printArray(array, SIZE);
            break;
        case '5':
            sortQuick(array, SIZE);
            printArray(array, SIZE);
            sortQuick(array, SIZE, M_DECEND);
            printArray(array, SIZE);
            break;
        case '6':
            sortInsertion(array, SIZE);
            printArray(array, SIZE);
            sortInsertion(array, SIZE, M_DECEND);
            printArray(array, SIZE);
            break;
        default:
            cout << "Error";
    }

    return 0;
}
