/*  Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Approach:
Given an array
We will traverse the whole array and see if the element is present in the array or not
If found we will print the index of the element
Otherwise, we will print -1.
*/

#include<stdio.h>

int search(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int num = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = search(arr,n,num);
    printf("%d",val);
}
