
#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void InsertionSort(vector<T> &arr, int left, int right);    //InsertionSort function declaration

template <typename T>
class Insertion {                                           //Class insertion sort
    vector<T> sorted;                                       //Private vector sorted

    public:
    Insertion(vector<T> arr) {                              //Insertion Constructor
        InsertionSort(arr, 0, (int) arr.size() - 1);            //Call InsertionSort on the entire array
        sorted = arr;                                           //Store the array in sorted
    };
    void print();                                           //Print function


};

/*******************************************************************************************
 * Function Title: Insertion Sort
 *
 * Summary: Sorts elements using the insertion sort method
 *
 * Inputs: The vector to be sorted, the starting index, and ending index
 * Outputs: The vector is sorted
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Declare a variable j
 *  Loop while p starting at left + 1 is less than right +1 increment p up one each time
 *      Store the value at location p to a temporary variable
 *      Loop while j, starting at p, is greater than zero the temp value is less than the value at j - 1, increment j down one each time
 *          Place the j-1 value into the jth position
 *      EndLoop when j is less tha zero or temp is greater than the value at j - 1
 *      Place the temp value in the jth location
 *  EndLoop when p is not less than right +1
 * End
 * ******************************************************************************************/

template <typename T>
void InsertionSort(vector<T> &arr, int left, int right) {   //Begin
    int j;                                                      //Declare a variable j

    for(int p = left + 1; p < right + 1; p++) {                 //Loop while p starting at left + 1 is less than right +1 increment p up one each time

        T temp = arr[p];                                            //Store the value at location p to a temporary variable

        for (j = p; j>0 && temp < arr[j-1]; j--) {                  //Loop while j, starting at p, is greater than zero the temp value is less than the value at j - 1, increment j down one each time
            arr[j] = arr[j-1];                                          //Place the j-1 value into the jth position
        }                                                           //EndLoop when j is less tha zero or temp is greater than the value at j - 1

        arr[j] = temp;                                              //Place the temp value in the jth location
    }                                                           //EndLoop when p is not less than right +1
}                                                           //End

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
void Insertion<T>::print() {        //Begin
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
void Insertion<char>::print() {        //Begin
    auto it = sorted.begin();           //Create an iterator at the beginning of the list
    while (it != sorted.end() ) {       //Loop while the iterator is not at the end of the list
        cout << +(*it) << " ";                 //Print the value the iterator points to
        it++;                               //Increment the iterator up one
    }                                   //EndLoop when every item has been printed
    cout << endl;                       //Print a new line
}                                   //End

#endif //SORT_INSERTION_H
