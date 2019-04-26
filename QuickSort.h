
#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H
#include <vector>
#include <iostream>
#include "Insertion.h"
using namespace std;

template <typename T>
class QuickSort {                           //Class QuickSort
    vector<T> sorted;                           //Private vector variable called sorted

public:
    QuickSort(vector<T> arr) {                  //QuickSort Constructor
        sort(arr, 0, (int)arr.size()-1);            //Call the sort function on the vector
        sorted = arr;                               //Set sorted equal to the vector
    }
    void print();                               //Print function
    void sort(vector<T> &arr, int i, int j);    //Sort function

};

/*******************************************************************************************
 * Function Title: Swap
 *
 * Summary: Swaps two values in a vector
 *
 * Inputs: Pointers to the first and second value
 * Outputs: The two values switch locations in the vector
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Set a temporary variable equal to the first value
 *  Set the value of the first equal to the value of the second
 *  Set the value of the second equal to the temporary value
 * End
 * ******************************************************************************************/

template <typename T>
void swap(T* first, T* second) {    //Begin
    T temp = *first;                    //Set a temporary variable equal to the first value
    *first = *second;                   //Set the value of the first equal to the value of the second
    *second = temp;                     //Set the value of the second equal to the temporary value
}                                   //End

/*******************************************************************************************
 * Function Title: Median of three pivot selector
 *
 * Summary: Selects a pivot from a vector using the median of 3 method
 *
 * Inputs: The address of the vector, the starting index, and the final index
 * Outputs: The value of the pivot
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Declare center to the middle of the left and right index
 *  If the value at center is less than the value at the left index
 *  Then
 *      Swap the left and center values
 *  EndIf
 *  If the value at the right is less than the value at the left index
 *  Then
 *      Swap the left and right values
 *  EndIf
 *  If the value at the right is less than the value at the center
 *  Then
 *      Swap the center and right values
 *  EndIf
 *  Swap the center and right-1 values
 *  Return the value at right-1
 * End
 * ******************************************************************************************/

template <typename T>
T median3(vector<T> &arr, int left, int right) {    //Begin
    int center = (left+right)/2;                        //Declare center to the middle of the left and right index
    if (arr[center] < arr[left]) {                      //If the value at center is less than the value at the left index
                                                        //Then
        swap(arr[left], arr[center]);                       //Swap the left and center values
    }                                                   //EndIf
    if (arr[right] < arr[left]) {                       //If the value at the right is less than the value at the left index
                                                        //Then
        swap(arr[left], arr[right]);                        //Swap the left and right values
    }                                                   //EndIf
    if (arr[right] < arr[center]) {                     //If the value at the right is less than the value at the center
                                                        //Then
        swap(arr[center], arr[right]);                      //Swap the center and right values
    }                                                   //EndIf

    swap(arr[center], arr[right-1]);                    //Swap the center and right-1 values
    return arr[right-1];                                //Return the value at right-1

}                                                   //End

/*******************************************************************************************
 * Function Title: Sort
 *
 * Summary: Sorts a list of vector using the quicksort method
 *
 * Inputs: A vector, the index to start at, and the index to end at
 * Outputs: The vector is sorted
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If the there are 10 or less elements
 *  Then
 *      Use median3 to set the pivot
 *      Set i equal to left and j to right -1
 *      Create a temporary variable
 *      Loop
 *          Loop while the ith element is less than the pivot, increment i up
 *          EndLoop when the ith element is not less than the pivot
 *          Loop while the jth element is greater than the pivot, increment j down
 *          EndLoop when the jth element is not greater than the pivot
 *          If i is less than j
 *          Then
 *              Swap the ith and jth elements
 *          Else
 *              End the loop
 *          EndIf
 *      EndLoop when i is greater than j
 *      Swap the ith element with the right - 1 element, placing the pivot at i
 *      Call sort on all elements left of i
 *      Call sort on all elements right of i
 *  Else
 *      Call insertion sort on the elements
 *  EndIf
 * End
 * ******************************************************************************************/

template <typename T>
void QuickSort<T>::sort(vector<T> &arr, int left, int right) {      //Begin

    if (left + 10 <= right) {                                           //If the there are 10 or less elements
                                                                        //Then
        T pivot = median3(arr, left, right);                                //Use median3 to set the pivot
        int i = left, j = right - 1;                                        //Set i equal to left and j to right -1
        T temp;                                                             //Create a temporary variable

        for (;;) {                                                          //Loop

            while(arr[++i] < pivot);                                            //Loop while the ith element is less than the pivot, increment i up
                                                                                //EndLoop when the ith element is not less than the pivot
            while(arr[--j] > pivot);                                            //Loop while the jth element is greater than the pivot, increment j down
                                                                                //EndLoop when the jth element is not greater than the pivot
            if (i < j) {                                                        //If i is less than j
                                                                                //Then
                swap(arr[i], arr[j]);                                               //Swap the ith and jth elements
            } else {                                                            //Else
                break;                                                              //End the loop
            }                                                                   //EndIf
        }                                                                   //EndLoop when i is greater than j

        swap(arr[i], arr[right-1]);                                         //Swap the ith element with the right - 1 element, placing the pivot at i
        sort(arr, left, i - 1);                                             //Call sort on all elements left of i
        sort(arr, i + 1, right);                                            //Call sort on all elements right of i
    }
    else {                                                              //Else
        InsertionSort(arr, left, right);                                    //Call insertion sort on the elements
    }                                                                   //EndIf
}                                                                   //End

/*******************************************************************************************
 * Function Title: Print
 *
 * Summary: Prints all the elements of the sorted vector, seperated by a space.
 *
 * Inputs: The sored list of the vector it is called on
 * Outputs: The sorted list printed to the screen
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Create an iterator at the beginning of the list
 *  Loop while the iterator is not at the end of the list
 *      Print the value the iterator points to
 *      Increment the iterator up one
 *  EndLoop when every item has been printed
 *  Print a new line
 * End
 * ******************************************************************************************/

template <typename T>
void QuickSort<T>::print() {        //Begin
    auto it = sorted.begin();           //Create an iterator at the beginning of the list
    while (it != sorted.end() ) {       //Loop while the iterator is not at the end of the list
        cout << *it << " ";                 //Print the value the iterator points to
        it++;                               //Increment the iterator up one
    }                                   //EndLoop when every item has been printed
    cout << endl;                       //Print a new line
}                                   //End

/*******************************************************************************************
 * Function Title: Print for character
 *
 * Summary: Prints all the elements of the sorted vector of characters using the numeric values, seperated by a space.
 *
 * Inputs: The sored list of the vector it is called on
 * Outputs: The sorted list printed to the screen
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Create an iterator at the beginning of the list
 *  Loop while the iterator is not at the end of the list
 *      Print the value the iterator points to as a numeric value
 *      Increment the iterator up one
 *  EndLoop when every item has been printed
 *  Print a new line
 * End
 * ******************************************************************************************/

template <>
void QuickSort<char>::print() {        //Begin
    auto it = sorted.begin();           //Create an iterator at the beginning of the list
    while (it != sorted.end() ) {       //Loop while the iterator is not at the end of the list
        cout << +(*it) << " ";                 //Print the value the iterator points to
        it++;                               //Increment the iterator up one
    }                                   //EndLoop when every item has been printed
    cout << endl;                       //Print a new line
}                                   //End



#endif //SORT_QUICKSORT_H
