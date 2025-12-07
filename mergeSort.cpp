#include<iostream>
using namespace std ;



// 1 2 3 4 5 6 7 8 9 10

// 1  , 2, 3  8 , 9


// 4 3        5       6 7 10 2 




int part( int arr[] , int left , int right ){
    int pivot = arr[right] ; 
    int i = left -1 ; 

    for ( int j = left ; j < right ; j ++ ){
        if ( arr[j] < pivot ){
            i++ ; 
            swap(arr[i] , arr[j]) ; 
        }
    }

    swap(arr[i+1] , arr[right]) ; 
    return i + 1 ;


}



void quickSort ( int arr[] , int left , int right ){
    if ( left < right ){
        int pi = part(arr , left , right ) ; 
        
        
        quickSort( arr , left , pi - 1 ) ;
        quickSort( arr , pi + 1 , right ) ;
    }

}








































// time complexity ---- O( n * log(n) )
void todna_hh ( int arr[] , int left , int right ){
    if ( left >= right ) return ; 


    // yha tk sirf mid nikala hh 


    int mid = ( left + right ) / 2 ; 

    todna_hh(arr , left , mid ) ; 
    todna_hh( arr , mid + 1 , right ) ; 

    merge(arr , left , mid , right ) ; 


}




void merge ( int arr[] , int left , int mid , int right  ){

    // ye to bs size nikaal rhe h 
    int size1 = mid - left + 1 ; 
    int size2 = right - mid ; 

    // yhaa do array bnaaye left aur right isme koi value nhi h 
    int L[size1] ; 
    int R[size2] ; 


    // array ki values ko daal diya hh 
    for ( int i = 0 ; i < size1 ; i ++ ) L[i] = arr[left + i ] ; 
    for ( int j = 0 ; j < size2 ; j ++ ) R[j] = arr[mid + j + 1] ; 


    int i = 0 ; 
    int j = 0 ; 

    int k = left ; 

    while ( i < size1 && j < size2 ){
        if ( L[i] <= R[j] ) arr[k++] = L[i++] ; 
        else arr[k++] = R[j++] ; 
    }

    while ( i < size1 ) arr[k++] = L[i++] ; 
    while ( j < size2 ) arr[k++] = R[j++] ; 


}



int main()
{


}