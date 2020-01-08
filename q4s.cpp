// DEQUEUE EFFICIENT QUEUE USING STACK
// Implement a Queue using two stacks Make it Dequeue efficient.

// Input Format:
// Enter the size of the queue N add 0 - N-1 numbers in the queue

// Constraints:
// Output Format
// Display the numbers in the order they are dequeued and in a space separated manner

// Sample Input
// 5
// Sample Output
// 0 1 2 3 4
#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int>s1,s2;
    int cs;
public:
    queue(){
        cs=0;
    }

    bool empty(){
        return cs==0;
    }

    void push(int data){
        s1.push(data);
        cs++;
    }

    void pop(){
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        cs--;
    }

    int front(){
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int temp=s1.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }
};
int main() {
    queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
	return 0;
}