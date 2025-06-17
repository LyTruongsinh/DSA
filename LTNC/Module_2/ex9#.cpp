#include <iostream>
using namespace std;
void sort(float array[], int size, bool isAscending)
{
    int n = size;
    if(isAscending) // tăng dần
    {
        for(int i = 0; i < n; i++)
        {
            int key = array[i];
            int j;
            for(j = i - 1; j >= 0; j --)
            {
                if(array[j] > key)
                {
                    array[j + 1] = array[j];
                }
                else {
                    break;
                }
            }
            array[j + 1] = key;
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            int key = array[i];
            int j;
            for(j = i - 1; j >= 0; j --)
            {
                if(array[j] < key)
                {
                    array[j + 1] = array[j];
                }
                else {
                    break;
                }
            }
            array[j + 1] = key;
        }
    }
}