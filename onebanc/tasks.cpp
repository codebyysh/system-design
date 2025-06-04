#include<iostream>
using namespace std ; 


class taks_1 { //  Implement the Levenshtein Algorithm


    int f ( int i , int j , string s1 , string s2 ){
        if ( i < 0 ) return j+ 1 ; 
        if ( j < 0 ) return i + 1 ; 

        if ( s1[i] == s2[j] ) return 0 + f(i-1 , j - 1 , s1 , s2 ) ; 

        return min ( 1 + f( i , j - 1 ,s1 , s2) , min ( 1 + f ( i - 1 , j,s1 , s2 ) , 1 + f( i - 1 , j -1,s1 , s2 ))) ;
    }

    public :
    int EditDistance (string s1, string s2) {
        int n = s1.size() ; 
        int m = s2.size() ; 

        return f( n -1 , m -1 , s1 , s2 ) ; 
    }


};




class task_2 {

    private :
    int f ( int i , int j , string s1 , string s2 , int Ci , int Cd , int Cs ){
        if ( i < 0 ) return (j+1) * Ci ; 
        if ( j < 0 ) return (i+1) * Cd ; 

        if ( s1[i] == s2[j] ) return 0 + f(i-1 , j - 1 , s1 , s2 , Ci , Cd , Cs ) ; 

        return min ( Ci + f( i , j - 1 ,s1 , s2, Ci , Cd , Cs) , 
                    min ( Cd + f ( i - 1 , j,s1 , s2 , Ci , Cd , Cs) , 
                            Cs + f( i - 1 , j -1,s1 , s2, Ci , Cd , Cs ))) ;
    }

    public:

    int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int n = s1.size() ; 
        int m = s2.size() ; 

        return f( n -1 , m -1 , s1 , s2 , Ci , Cd , Cs ) ; 
    }

};




class task_3 {
    private :
    int f ( int i , int j , string s1 , string s2 , int Ci , int Cd , int Cs ){
        if ( i < 0 ) return (j+1) * Ci ; 
        if ( j < 0 ) return (i+1) * Cd ; 

        if ( s1[i] == s2[j] ) return 0 + f(i-1 , j - 1 , s1 , s2 , Ci , Cd , Cs ) ; 

        return min ( Ci + f( i , j - 1 ,s1 , s2, Ci , Cd , Cs) , 
                    min ( Cd + f ( i - 1 , j,s1 , s2 , Ci , Cd , Cs) , 
                            Cs + f( i - 1 , j -1,s1 , s2, Ci , Cd , Cs ))) ;
    }

    public:

    int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int n = s1.size() ; 
        int m = s2.size() ; 

        return f( n -1 , m -1 , s1 , s2 , Ci , Cd , Cs ) ; 
    }

    // to return the output as a collection of strings 
    vector<string> output ( vector<string> dictionary , string input , int Ci , int Cd , int Cs ){
        vector<string> ans ; 
        
        int min_cost = INT_MAX ; 
        for ( auto word_in_dict : dictionary ){
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
    
    vector<string> dict = {"cred", "bet", "shat", "that", "brad", "cart", "brat", "card"};
    string word = "dat";
    int ci = 1, cd = 1, cs = 1;

    vector<string> res = obj.output(dict, word, ci, cd, cs);

    cout << "Words close to \"" << word << "\": ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

}