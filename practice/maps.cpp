#include<iostream>
using namespace std ; 

#include<unordered_set> 

int freq_count ( vector<int> & arr , int target ){
    unordered_map<int , int > mp ; 
    for ( int it : arr ){
        mp[it] ++ ; 
    }
    return mp[target] ; 
}

vector<int> unique ( vector<int> &arr ){
    unordered_set <int> set ; 

    for ( int it : arr ){
        set.insert(it) ; 
    }
    vector<int> result ( set.begin() , set.end() ) ; 
    return result ; 
}

int main ()
{
    vector<int> arr = { 1,2,3,3,2,1,2,3,4,5,6,3,2,1,2,3,4 , 1 } ; 
    // int target ; 
    // cout << " give me the tatget " << endl ; 
    // cin >> target ; 
    // cout << "the frequency of the element is " << freq_count(arr , target )<< endl ;

    vector<int> distinct = unique(arr) ; 
    for ( int x : distinct ) cout << x << " " ; 
    cout << endl; 

}












int minDistance(string word1, string word2) {
        int n = word1.size() ; 
        int m = word2.size() ; 
        vector<int> prev ( m + 1 , 0 ) , curr ( m + 1 , 0 ) ; 
        
        for ( int j = 0 ; j <= m ; j ++ ) prev[j] = j ; 

        for ( int i = 1 ; i <= n ; i ++ ){
            curr[0] = i ; 
            for ( int j = 1 ; j <= m ; j ++ ){
                if ( word1[i-1] == word2[j-1] )  curr[j] = prev[j-1] ; 

                else curr[j] = 1 + min ( prev[j] , min ( curr[j-1] , prev[j-1])) ;
            }
            prev = curr ; 
        }
        return prev[m] ; 
}




