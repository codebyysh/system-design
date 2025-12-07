#include<iostream>
using namespace std ;

int b_s ( int start ,int end , int target ){
    while ( start <= end) {
        int mid = start + ( end - start ) / 2 ; 
        if ( mid == target )return mid ;
        else if ( mid < target ) start = mid + 1 ;
        else end = mid - 1 ; 
    }
    return -1 ; 
}

int stack_op ( ) {
    stack<int> st ; 

    st.pop() ; 
    st.push(10) ;
    st.top() ;
    st.empty() ;
    st.size() ;
}

int queue_op ( ) {
    queue<int> q ; 

    q.push(10) ;
    q.pop() ;
    q.front() ;
    q.back() ;
    q.empty() ;
    q.size() ;
}


int priority_queue_op ( ) {
    priority_queue<int> pq ; 

    pq.push(10) ;
    pq.pop() ;
    pq.top() ;
    pq.empty() ;
    pq.size() ;
}

int map(){
    unordered_map<int, int > mp ; 
    mp[1] = 10 ;
    mp.insert({2,20}) ;
    mp.find(1) ;
    mp.erase(2) ;
    mp.size() ;
}

int main(){
    cout << "hello world " << endl ; 
    return 0 ; 

    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
