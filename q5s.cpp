// REVERSE A STACK USING RECURSION
// Reverse a Stack using Recursion.

// Input Format:
// First line contains an integer N (size of the stack). Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

// Constraints:
// Output Format
// Output the values of the reversed stack with each value in following line.

// Sample Input
// 3
// 3
// 2
// 1
// Sample Output
// 3
// 2
// 1
#include<iostream>
#include<stack>
using namespace std;

void inseratbottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    inseratbottom(s,x);
    s.push(y);
}

void recursivereverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    int x=s.top();
    s.pop();
    recursivereverse(s);
    inseratbottom(s,x);
}
int main() {
    stack<int>s;
    int n;
    cin>>n;
    int no;
    for(int i=1;i<=n;i++){
        cin>>no;
        s.push(no);
    }
    recursivereverse(s);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
	return 0;
}