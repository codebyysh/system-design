#include <iostream>
using namespace std;


void matrix ( ){
    int row = 3 ; 
    int cols = 2 ; 

    for ( int i = 0 ; i < row ;i ++ ){
        for ( int j = 0 ; j < cols ; j ++ ){
            cout << "* " ; 
        }
        cout << endl ; 
    }
}

int main() {
    // int n = 6;  // height of pyramid
    // for (int i = 0; i < n; i++) {
    //     // spaces before stars
    //     for (int j = 0; j < n - i - 1; j++) {
    //         cout << "  ";
    //     }
    //     // stars
    //     for (int j = 0; j < 2 * i + 1; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    matrix() ; 
    return 0;
}