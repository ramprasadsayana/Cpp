#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class MultiplyLargeNumbers
{
public :
    int * Multiply(string str1,string str2 ,int &resArrayLength)
    {
        //converting first string to integer array
        int len1=str1.length();
        int *arr1= new int[len1]();

        for(int i=0;i<len1;i++)
        {
            char c=str1[i];
            arr1[i]=atoi(const_cast<char*>(&c));
        }
         
        //converting 2nd string to integer array
        int len2=str2.length();
        int *arr2= new int[len2]();
        for(int i=0;i<len2;i++)
        {
            char c=str2[i];
            arr2[i]=atoi(const_cast<char*>(&c));
        }
       
    
        //calculating resultant array length
        resArrayLength=len1+len2+1;

        int *arr= new int[resArrayLength]();

        int carry=0;
        for(int i=len2-1;i>=0;i--)
        {
            
            for(int j=len1-1;j>=0;j--)
            {
                int val=*(arr+i+j+2);
                int res= val+arr1[j]*arr2[i] +carry;
                carry=res/10;
                *(arr+i+j+2)=res%10;
            }
           
            if(carry>0)
             {
                   *(arr+i+1)+=carry;
                   carry=0;
             }
        }

        return arr;
    }
};

int main() 
{ 
  
    MultiplyLargeNumbers m;
    int resultArrayLength=0;
    int * arr=m.Multiply("999999999","877777",resultArrayLength);
    
    for(int i=0;i<resultArrayLength;i++)
    {
        cout<<arr[i];
    }
    return 0; 
} 