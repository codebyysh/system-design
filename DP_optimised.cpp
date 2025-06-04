#include<iostream>

using namespace std ; 


class task_4_optimisation {

    public : 

    int EditDistance ( string s1 , string s2 ){
        int n = s1.size() ; 
        int m = s2.size() ; 

        vector<vector<int>> dp ( n + 1 , vector<int> ( m+ 1 , 0 ) ) ; 

        for ( int i = 0 ; i <= n ; i ++ ) dp[i][0] = i ; 
        for ( int j = 0 ; j <= m ; j ++ ) dp[0][j] = j ; 

        for ( int i = 1 ; i <= n ; i ++ ){
            for ( int j = 1 ; j <= m ; j ++ ){


                if ( s1[i-1] == s2[j-1] ) dp[i][j] = 0 + dp[i-1][j-1] ; 


                else {
                    int insert = 1 + dp[i][j-1] ; 
                    int del = 1 + dp[i-1][j] ; 
                    int replace  =  1 + dp[i-1][j-1] ; 

                    dp[i][j] = min( insert , min(del , replace )) ; 
                }
            }
        }

        return dp[n][m] ; 
    }
};




class space_optimisation {

    public : 
    int EditDistance ( string s1 , string s2 ){
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
                    int replace = 1 + prev[j-1] ; 

                    curr[j] = min( insert , min ( del , replace )) ;
                } 
            }
            prev = curr ; 
        }

        return prev[m] ; 
        
    }


};

int main ()
{
    
}