// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>

using namespace std;
void transpose(int *a,int x,int y)
{
    vector<bool>isVisited ;
 
    for(int i=0;i<x*y;i++)
        isVisited.push_back(false);


    for(int i=0;i<x*y;i++)
    {
        
        if(isVisited[i])
            continue;
        //get current row and coulmn
        int currRow=i/y;
        int currColumn=i%y;

        //then get new position in array with reversing coulum and row
        int newRow=currColumn;
        int newColumn=currRow;

        int newPos=newRow*x +newColumn;

        //swap numbers
        int z=a[i];
        a[i]=a[newPos];
        a[newPos]=z;

        //mark them visited
        isVisited[i]=true;
        isVisited[newPos]=true;
     }
}

void display(int *a,int rows,int columns)
{
    cout<<"Array"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<< *(a+(i*columns+j)) <<" ";
        }
        cout<< endl;
    }
}
int main() 
{ 
  
    int a[8]={1,2,3,4,5,6,7,8};
    
    display(a,2,4);
    transpose(a,2,4);
    display(a,4,2);

    return 0; 
} 
