///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Turner
// Email:            slturner980@gmail.com
// Label:            A04
// Title:            Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */

class ArrayStack{
private:
  int *A;               // pointer to array of int's
  int size;             // current max stack size
  int top;              // top of stack 
  ifstream fin;         // input stream
  ofstream fout;        // output stream
  int fileval;          // int value from input file.
  string filestr;       // string value from input file
  int maxsize = 0;      // max size that the array got 
  int shrgrow = 0;      // Tracks both array shrinkage and growth

public:
 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 10;
    A = new int[size];
    top = -1;
  }

 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    A = new int[s];
    top = -1;
  }

  /**
  * ~ArrayStack
  * 
  * Description:
  *      Destructor, writes the output
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */

  ~ ArrayStack(){
      Writefile();
  }

 /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }
  
 /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full(){
    return (top >= size-1);
  }

 /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }
    
    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    if(!Empty()){
      CheckResize();
      return A[top--];
    }

    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print(){
    cout <<"size of array "<< size << endl;
    cout<< "top number: "<< top << endl;
    cout <<"Maxsize of array "<< maxsize << endl;
    cout <<"Growths and Shrinkages "<< shrgrow << endl;

    for(int i=0;i<=top;i++){
      cout<<A[i]<<" ";
    }
    cout <<"\n"<<endl;
  } 

 /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    if(Full()){
      CheckResize();
    }
    if(!Full()){
      A[++top] = x;
      return true;
    }
    
    return false;
    
  }

 /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow(){
    int newSize = size*2;       // double size of original
    int *B = new int[newSize];  // allocate new memory

    for(int i=0;i<size;i++){    // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                // delete old array

    size = newSize;             // save new size

    TrackSize();

    A = B;                      // reset array pointer

    shrgrow++;

  }

  /**
  * Public void: ContainerShrink
  * 
  * Description:
  *      Resizes the container for the stack by halving
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
   void ContainerShrink(){

    int newSize = size / 2;       // half size of original
    
    int *B = new int[newSize];  // allocate new memory

    for(int i=0;i< top;i++){    // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                // delete old array

    size = newSize;             // save new size

    A = B;                      // reset array pointer

    shrgrow++;

  }

/**
  * Public void: CheckResize
  * 
  * Description:
  *      Checks the ratio of the top of the stack and
  *      the array's size to see if the container needs
  *      to shrink or grow.
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void CheckResize(){

    float ratio =  ((float) top) / size;

    if(ratio <= .50){
    
        if (size <= 10){
            return;
        }
        else{

        ContainerShrink();
        }
    }

    if (ratio >= .75){

        ContainerGrow();
    }
      
  }

/**
  * Public void: Readfile
  * 
  * Description:
  *      Reads the input file and pushs numbers if they
  *      are even. If they are odd, then it will pop
  *      numbers.
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  
void Readfile(){
    fin.open("nums_test.dat");

    while(fin >> fileval){
    
    //for (int i; i <= 574; i++){
        
        fin >> fileval;
        if (fileval % 2 == 0){
             Push(fileval);
        }
        else{
            Pop();
        }
    }
   
     
    fin.close();
}

 /**
    *  TrackSize:
    *    Tracks how high the stack size got.
    * Params:
    *    Void
    * 
    * Returns:
    *     Void
    */    

    void TrackSize(){
        if(size > maxsize){
            maxsize = size;
        }
    }

/**
    *  Writefile:
    *    Writes out info in a seperate output file.
    * Params:
    *    Void
    * 
    * Returns:
    *     Void
    */  

void Writefile(){
    fout.open("output.txt");

    fout << "######################################################################" << endl;
    fout << "Assignment 4 - Resizing the Stack" << endl;
    fout << "CMPS 3013" << endl;
    fout << "Sarah Turner " << endl;
    fout << "Max Stack Size: "<< maxsize << endl;
    fout << "End Stack Size: " << size << endl;
    fout << "Stack Resized: " << shrgrow << " times"<< endl;
    fout << "######################################################################" << endl;

    fout.close();
}

};


// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  ArrayStack stack;

  stack.Readfile();
}