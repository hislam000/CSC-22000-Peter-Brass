
//Course: CSc 220-Algorithms
//Project1: main.cpp 
//Name: Hasibul Islam
//Date: 10/08/2017

#include <iostream>
using namespace std;

int quickselect( int *A, int k, int n);

void swap(int *arr, int left, int right) {
    int l=left, r=right;
    int tmp;
    tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}
int quickselect( int *A, int k, int n){
    // swap
    // index (0 & n/2)
    swap(A,0,n/2);

     // p is pivot
     int p=0; int j;
    
    //element in array
    if(n<=1) { return A[0];
}
    for(j=n-1;  j>p; --j) {
        if(A[j] <=A[p])  {
            //swap
            swap(A,j, p+1); ++j;
            swap(A,p, p+1); ++p;

        }
    }
    // k is equal
    if (p+1==k){
        return A[k-1];}
    // k is greater than    
    else if (p+1>k){
        return quickselect(A,k,p);
    }
     // k is the less than
    else if (p+1<k){
        return quickselect(A+p+1, k-p-1, n-p-1);
    }
    else{ 
        return A[p];
    }
    
}

//-----------------------test.c (file)
int main()
{
    long i;
    int *space; int tmp;
    space =  (int *) malloc( 1000000*sizeof(int));
    for( i=0; i< 500000; i++ )
    {  *(space + i) = ((139*i)%500000);
        *(space + i + 500000) = 1000000 + ((141*i)%500000);
    }
    if( (tmp = quickselect(  space, 500001, 1000000)) != 1000000 )
    {  cout<<" Failed test 1. Returned"<<tmp<<"instead of 1000000\n";
        fflush(stdout); exit(-1);
    }
    else cout<<"passed test1\n";
    for( i=0; i< 500000; i++ )
    {  *(space + i) = ((139*i)%500000);
        *(space + i + 500000) = 1000000 + ((141*i)%500000);
    }
    if( (tmp = quickselect(  space, 1, 1000000)) != 0 )
    {  cout<<" Failed test 2. Returned "<<tmp<<" instead of 0\n";
        fflush(stdout); exit(-1);
    }
    else cout<<"passed test2\n";
    for( i=0; i< 500000; i++ )
    {  *(space + i) = ((139*i)%500000);
        *(space + i + 500000) = 1000000 + ((141*i)%500000);
    }
    if( (tmp = quickselect(  space, 124, 1000000)) != 123 )
    { cout<<" Failed test 3. Returned "<<tmp<<" instead of 123\n";
        fflush(stdout); exit(-1);
    }
    else cout<<"passed test3\n";



    cout<<"Quickselect successful\n";
    exit(0);
}
//-----------------------test.c (file)