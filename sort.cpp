#include <random>
#include <chrono>
#include <vector>
#include <iostream>
#include "Insertion.h"
#include "QuickSort.h"
#include <string>
#include <typeinfo>


#define N 20

using namespace std;

/*******************************************************************************************
 * Function Title: Word Generator
 *
 * Summary: Generates a random string of length 20
 *
 * Inputs: None
 * Outputs: A random string of length 20
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Seed and set up the proper distribution that allows for only characters for a generator
 *  Declare a string to store the word
 *  Loop 20 times
 *      Push a random character from the distribution to the back of the word
 *  EndLoop after 20 iterations
 *  Return the word
 * End
 * ******************************************************************************************/

string wordgenerator() {                        //Begin

    random_device rd;                               //Seed and set up the proper distribution that allows for only characters for a generator
    mt19937 gen(rd());
    uniform_int_distribution<> dist(33, 126);

    string word;                                    //Declare a string to store the word

    for (int i = 0; i < 20; i++) {                  //Loop 20 times

        word.push_back((char)dist(gen));                //Push a random character from the distribution to the back of the word

    }                                               //EndLoop after 20 iterations

    return word;                                    //Return the word

}                                               //End

/*******************************************************************************************
 * Function Title: Score
 *
 * Summary: Scores a string based on each letter being worth 1-26 points for letters a-z
 *
 * Inputs: A string
 * Outputs: The score
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Start the score at 0
 *  Loop 20 times
 *      If the character is an uppercase letter
 *      Then
 *          Add the appropriate score of 1-26 based on the letter to score
 *      Else If the character is a lowercase letter
 *      Then
 *          Add the appropriate score of 1-26 based on the letter to score
 *      EndIf
 *  EndLoop after 20 iterations
 *  Return score
 * End
 * ******************************************************************************************/

int score(string s) {                           //Begin

    int score = 0;                                  //Start the score at 0

    for (int i =0; i < 20; i++) {                   //Loop 20 times

        if (s[i] >= 65 && s[i] <= 90) {                 //If the character is an uppercase letter
                                                        //Then
            score += (s[i] - 64);                           //Add the appropriate score of 1-26 based on the letter to score
        }
        else if (s[i] >= 97 && s[i] <= 122) {           //Else If the character is a lowercase letter
                                                        //Then
            score += (s[i] - 96);                           //Add the appropriate score of 1-26 based on the letter to score
        }                                               //EndIf

    }                                               //EndLoop after 20 iterations

    return score;                                   //Return Score

}                                               //End

/*******************************************************************************************
 * Function Title: < operator for strings
 *
 * Summary: Defines the operator for strings to be the < of their scores
 *
 * Inputs: Two strings
 * Outputs: True or false
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Return true or false based on the < evaluation of the strings scores
 * End
 * ******************************************************************************************/

bool operator<(string s1, string s2) {  //Begin

    return(score(s1) < score(s2));          //Return true or false based on the < evaluation of the strings scores
}                                       //End

/*******************************************************************************************
 * Function Title: > operator for strings
 *
 * Summary: Defines the operator for strings to be the > of their scores
 *
 * Inputs: Two strings
 * Outputs: True or false
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Return true or false based on the > evaluation of the strings scores
 * End
 * ******************************************************************************************/

bool operator>(string s1, string s2) {  //Begin

    return(score(s1) > score(s2));          //Return true or false based on the > evaluation of the strings scores
}                                       //End

/*******************************************************************************************
 * Function Title: Main
 *
 * Summary: Creates a vector of random strings and then sorts and prints those strings
 *
 * Inputs: None
 * Outputs: The sorted list of strings
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Declare a variable i
 *  Declare a vector of strings called nums
 *  Loop N number of times
 *      Push a random word of length 20 into the vector
 *  EndLoop after N iterations
 *  Sort nums using quicksort
 *  Sort nums using Insertion
 *  Print the sorted list
 * End
 * ******************************************************************************************/


int main()                                  //Begin
{
    long i;                                     //Declare a variable i
    vector<string> nums;                        //Declare a vector of strings called nums


    for (i = 0; i < N; i++) {                   //Loop N number of times

        nums.push_back(wordgenerator());            //Push a random word of length 20 into the vector

    }                                           //EndLoop after N iterations
    //QuickSort<string> s(nums);                //Sort nums using quicksort
    Insertion<string> s(nums);                  //Sort nums using Insertion

    s.print();                                  //Print the sorted list

    return 0;
}                                           //End



