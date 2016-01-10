//
//  main.cpp
//  2DArray_A3
//
//  Created by Ian Murphy on 1/8/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include "Array2D.h"

template <typename T>
void DisplayContents(Array2D<T> &arr);

template <typename T>
void TestDuplication(Array2D<T> &arr);

template <typename T>
void TestSpecialCases(Array2D<T> &arr);

template <typename T>
void TestOtherFeatures(Array2D<T> &arr);

int main() {
    
    //Initialize Array
    
    Array2D<int> myArray(5,5);
    int i = 0;
    for (int row = 0; row<5; row++) {
        for(int col = 0; col< 5; col++)
        {
            myArray[row][col] = i;
            i++;
        }
    }
    
    DisplayContents(myArray);
    
    TestDuplication(myArray);
    
    TestSpecialCases(myArray);
    
    TestOtherFeatures(myArray);
    
    return 0;
}

template <typename T>
void DisplayContents(Array2D<T> &arr)
{
    int row_s = arr.getRow();
    int col_s = arr.getColumn();
    
    for (int row = 0; row<row_s; row++) {
        for(int col = 0; col< col_s; col++)
        {
            cout<<"["<<row<<"]"<<"["<<col<<"]: "<<arr[row][col]<<endl;
        }
    }
}

template <typename T>
void TestDuplication(Array2D<T> &arr)
{
    cout<<"************* TESTING COPY CTOR **************"<<endl;
    cout<<"************* After pass by reference ************"<<endl;
    DisplayContents(arr);
    
    Array2D<T> arr2(arr);
    cout<<"************* After copy ctor ************"<<endl;
    DisplayContents(arr2);
    
    cout<<"************ Change some values **********"<<endl;
    
    arr2[0][0] = 100;
    arr2[2][2] = 1000;
    DisplayContents(arr2);
    
    cout<<"************ Testing OP =  **********"<<endl;
    
    arr = arr2;
    DisplayContents(arr);
    
    
}

template <typename T>
void TestSpecialCases(Array2D<T> &arr)
{
    cout<<"************* TESTING SPECIAL CASES **************"<<endl;
    cout<<"************* Testing out of bounds **************"<<endl;
    try{
        cout<<arr[6][7]<<endl;
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
    
    cout<<"************* Testing set column to -1 **************"<<endl;
    
    try{
        arr.setColumn(-1);
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
    cout<<"************* Testing ser row to -1 **************"<<endl;
    try{
        arr.setRow(-1);
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
}

template <typename T>
void TestOtherFeatures(Array2D<T> &arr)
{
    cout<<"************* TESTING OTHER FEATURES **************"<<endl;
    cout<<"************* Testing set lower bounds **************"<<endl;
    arr.setRow(3);
    arr.setColumn(2);
    DisplayContents(arr);
    
    cout<<"\n************* Testing set higher bounds **************"<<endl;
    arr.setRow(4);
    arr.setColumn(6);
    DisplayContents(arr);
    
}