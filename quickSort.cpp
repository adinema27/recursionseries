#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[s];

    int cnt =0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i]<=pivot)
        {
            cnt++;
        }    
    }
    // place pivot at right index
    int pivotIndex = s+ cnt;
    swap(arr[pivotIndex], arr[s]);

    // left or right wale part ko sambhal lete hai
    int i =s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i]<= pivot)
        {
            i++;
        }
        while (arr[j]>= pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex/* condition */)
        {
           swap(arr[i++], arr[j--]); /* code */
        }    
        
    }
    
    return pivotIndex;  
}
void quickSort(int arr[], int s, int e){
    // base case
    if(s>=e)
        return;
    
    // partition
    int p = partition(arr, s, e);

    // left part ko sort kro
    quickSort(arr, s, p-1);

    // right part ko sort kro 
    quickSort(arr, p+1, e);
}
int main()
{
    int arr[6]= {2,4,1,5,9,9};
    int n = 6;

    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}