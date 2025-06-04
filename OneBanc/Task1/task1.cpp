#include<iostream>
#include<vector>
#include<string>


using namespace std ; 



class task_1 { 

    private :
    int f ( int i , int j , string & s1 , string &s2 , vector<vector<int>> &dp ){
        if ( i < 0 ) return j+ 1 ; 
        if ( j < 0 ) return i + 1 ; 

        if ( dp[i][j] != -1 ) return dp[i][j] ; 

        if ( s1[i] == s2[j] ) return dp[i][j] = 0 + f(i-1 , j - 1 , s1 , s2 , dp ) ; 

        int insert = 1 + f( i , j - 1 ,s1 , s2 , dp) ; 
        int del = 1 + f ( i - 1 , j,s1 , s2 , dp) ; 
        int substitute = 1 + f( i - 1 , j -1,s1 , s2 , dp ) ; 

        return dp[i][j] = min ( insert , min( del , substitute )) ;
    }


    public :
    int EditDistance (string s1, string s2) {
        int n = s1.size() ; 
        int m = s2.size() ; 
        vector<vector<int>> dp ( n , vector<int> ( m , -1 )) ; 
        return f( n -1 , m -1 , s1 , s2 , dp ) ; 
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

    
    task_1 obj ; 
    int result = obj.EditDistance(s1 , s2);
    cout << endl ; 
    cout << result << endl ; 



}