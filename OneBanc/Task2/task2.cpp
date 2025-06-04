#include<iostream>
#include<vector>
#include<string>


using namespace std ; 




class task_2 {

    private :
    int f ( int i , int j , string & s1 , string & s2 , int Ci , int Cd , int Cs , vector<vector<int>>& dp ){
        if ( i < 0 ) return (j+1) * Ci ; 
        if ( j < 0 ) return (i+1) * Cd ; 

        if ( dp[i][j] != -1 ) return dp[i][j] ; 

        if ( s1[i] == s2[j] ) return 0 + f(i-1 , j - 1 , s1 , s2 , Ci , Cd , Cs ,dp  ) ; 

        
        int insert = Ci + f( i , j - 1 ,s1 , s2 , Ci , Cd , Cs ,dp) ; 
        int del = Cd + f ( i - 1 , j,s1 , s2 , Ci , Cd , Cs ,dp) ; 
        int substitute = Cs + f( i - 1 , j -1,s1 , s2 , Ci , Cd , Cs ,dp ) ; 

        return dp[i][j] = min ( insert , min( del , substitute )) ;
    }

    public:

    int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int n = s1.size() ; 
        int m = s2.size() ; 

        vector<vector<int>> dp ( n , vector<int>(m , -1 )) ; 

        return f( n -1 , m -1 , s1 , s2 , Ci , Cd , Cs , dp ) ; 
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

    int Ci ; 
    cout << "enter the value of Ci (the cost for insertion ) " << endl ; 
    cin >> Ci ; 

    int Cd ; 
    cout << "enter the value of Cd (the cost for deletion ) " << endl ; 
    cin >> Cd ; 

    int Cs ; 
    cout << "enter the value of Cs (the cost for replacing )" << endl ; 
    cin >> Cs ; 


    task_2 obj ; 
    cout << endl; 
    cout << obj.EditDistance(s1 , s2 ,  Ci , Cd , Cs) << endl  ; 



}

