#include<iostream>
using namespace std ; 



class taks_1 { 


    int f ( int i , int j , string & s1 , string &s2 , vector<vector<int>> &dp ){
        if ( i < 0 ) return j+ 1 ; 
        if ( j < 0 ) return i + 1 ; 

        if ( dp[i][j] != -1 ) return dp[i][j] ; 

        if ( s1[i] == s2[j] ) return dp[i][j] = 0 + f(i-1 , j - 1 , s1 , s2 , dp ) ; 

        int insert = 1 + f( i , j - 1 ,s1 , s2 , dp) ; 
        int del = 1 + f ( i - 1 , j,s1 , s2 , dp) ; 
        int replace = 1 + f( i - 1 , j -1,s1 , s2 , dp ) ; 

        return dp[i][j] = min ( insert , min( del , replace )) ;
    }


    public :
    int EditDistance (string s1, string s2) {
        int n = s1.size() ; 
        int m = s2.size() ; 
        vector<vector<int>> dp ( n , vector<int> ( m , -1 )) ; 
        return f( n -1 , m -1 , s1 , s2 , dp ) ; 
    }


};




class task_2 {

    private :
    int f ( int i , int j , string & s1 , string & s2 , int Ci , int Cd , int Cs , vector<vector<int>>& dp ){
        if ( i < 0 ) return (j+1) * Ci ; 
        if ( j < 0 ) return (i+1) * Cd ; 

        if ( dp[i][j] != -1 ) return dp[i][j] ; 

        if ( s1[i] == s2[j] ) return 0 + f(i-1 , j - 1 , s1 , s2 , Ci , Cd , Cs ,dp  ) ; 

        
        int insert = Ci + f( i , j - 1 ,s1 , s2 , Ci , Cd , Cs ,dp) ; 
        int del = Cd + f ( i - 1 , j,s1 , s2 , Ci , Cd , Cs ,dp) ; 
        int replace = Cs + f( i - 1 , j -1,s1 , s2 , Ci , Cd , Cs ,dp ) ; 

        return dp[i][j] = min ( insert , min( del , replace )) ;
    }

    public:

    int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int n = s1.size() ; 
        int m = s2.size() ; 

        vector<vector<int>> dp ( n , vector<int>(m , -1 )) ; 

        return f( n -1 , m -1 , s1 , s2 , Ci , Cd , Cs , dp ) ; 
    }

};












class task_3 {

    private :
    int f ( int i , int j , string & s1 , string & s2 , int Ci , int Cd , int Cs , vector<vector<int>>& dp ){
        if ( i < 0 ) return (j+1) * Ci ; 
        if ( j < 0 ) return (i+1) * Cd ; 

        if ( dp[i][j] != -1 ) return dp[i][j] ; 

        if ( s1[i] == s2[j] ) return 0 + f(i-1 , j - 1 , s1 , s2 , Ci , Cd , Cs ,dp  ) ; 

        
        int insert = Ci + f( i , j - 1 ,s1 , s2 , Ci , Cd , Cs ,dp) ; 
        int del = Cd + f ( i - 1 , j,s1 , s2 , Ci , Cd , Cs ,dp) ; 
        int replace = Cs + f( i - 1 , j -1,s1 , s2 , Ci , Cd , Cs ,dp ) ; 

        return dp[i][j] = min ( insert , min( del , replace )) ;
    }




    int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int n = s1.size() ; 
        int m = s2.size() ; 

        vector<vector<int>> dp ( n , vector<int>(m , -1 )) ; 

        return f( n -1 , m -1 , s1 , s2 , Ci , Cd , Cs , dp ) ; 
    }
    

    public : 
    
    vector<string> output ( vector<string> dictionary , string input , int Ci , int Cd , int Cs ){

        vector<string> ans ; 
        
        int min_cost = INT_MAX ; 

        for ( string word_in_dict : dictionary ){
            int d = EditDistance(input , word_in_dict , Ci , Cd , Cs ) ; 
            if ( d < min_cost ) {
                min_cost = d ; 
                ans.clear() ; 
                ans.push_back(word_in_dict) ; 


            }
            else if ( d == min_cost ) ans.push_back(word_in_dict) ; 
        }

        return ans ; 

    }

};



int main()
{
    // string s1 ; 
    // string s2 ; 

    // cout << " enter the string 1 " << endl ;
    // cin >> s1 ; 
    // cout << " enter the stirng 2 " << endl ;
    // cin >> s2 ; 

    // int Ci ; 
    // cout << " enter the value of Ci (the cost for insertion ) " << endl ; 
    // cin >> Ci ; 

    // int Cd ; 
    // cout << " enter the value of Cd (the cost for deletion ) " << endl ; 
    // cin >> Cd ; 

    // int Cs ; 
    // cout << " enter the value of Cs (the cost for replacing )" << endl ; 
    // cin >> Cs ; 


    // task_2 obj ; 
    // cout << obj.EditDistance(s1 , s2 ,  Ci , Cd , Cs) << endl  ; 


    // taks_1 obj ; 
    // cout << obj.EditDistance(s1 , s2) << endl ; 


    task_3 obj ; 
    
    vector<string> dict = { "cred" ,  "bet" , "shat",  "that",  "brad" , "cart", "brat" , "card"}  ;
    string input = "dat" ;
    

    vector<string> result = obj.output( dict, input ,1 , 1 ,1 );

    for ( auto i : result ){
        cout << i << " " ; 
    }
    cout << endl;

}