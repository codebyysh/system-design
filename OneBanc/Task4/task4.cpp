#include<iostream>
#include<vector>
#include<string>


using namespace std ; 

class space_optimisation {

    public : 
    int EditDistance ( string s1 , string s2  ){
        int n = s1.size() ; 
        int m = s2.size() ; 

        vector<int> prev ( m + 1 , 0 ) ; 
        vector<int> curr ( m + 1 , 0 ) ; 

        for ( int j = 0 ; j <= m ; j ++ ) prev[j] = j ; 

        for ( int i = 1 ; i <= n ; i ++ ){
            curr[0] = i ; 

            for ( int j = 1 ; j <= m ; j ++ ){

                if ( s1[i-1] == s2[j-1] ) curr[j] = prev[j-1] ; 

                else
                {
                    int insert = 1 + prev[j] ; 
                    int del = 1 + curr[j-1] ; 
                    int substitute = 1 + prev[j-1] ; 

                    curr[j] = min( insert , min ( del , substitute )) ;
                } 
            }
            prev = curr ; 
        }

        return prev[m] ; 
        
    }


};




int main()
{
    string s1 ; 
    string s2 ; 

    cout << endl ;
    cout << "enter the string 1 " << endl ;
    cin >> s1 ; 
    cout << "enter the stirng 2 " << endl ;
    cin >> s2 ; 


    cout << endl ; 
    
    space_optimisation obj ; 
    int result  = obj.EditDistance(s1 ,s2)  ; 
    cout << result << endl ;
    cout << endl ; 

}