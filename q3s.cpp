// BALANCED PARENTHESIS
// You are given a string of '(' and ')'. You have to check whether the sequence of parenthesis is balanced or not. For example, "(())", "(())()" are balanced and "())(", "(()))" are not.

// Input Format:
// A string of '(' , ')' , '{' , '}' and '[' , ']' .

// Constraints:
// 1<=|S|<=10^5

// Output Format
// Print "Yes" if the parenthesis are balanced and "No" if not balanced.

// Sample Input
// (())
// Sample Output
// Yes
#include<iostream>
#include<stack>
using namespace std;

bool checkbalanced(string str){
	stack<char>s;
	for(int i=0;i<str.length();i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			s.push(str[i]);
            continue;
		}
        if(s.empty()){
            return false;
        }
		if(str[i]==')'){
            char x=s.top();
            if(x=='{'||x=='['){
                return false;
            }
            s.pop();
        }
        if(str[i]=='}'){
            char x=s.top();
            if(x=='('||x=='['){
                return false;
            }
            s.pop();
        }
        if(str[i]==']'){
            char x=s.top();
            if(x=='('||x=='{'){
                return false;
            }
            s.pop();
        }
	}
	return s.empty();

}

int main() {
	string str;
	cin>>str;
	if(checkbalanced(str) && str.length()!=0){
		cout << "Yes";
	}
	if(!checkbalanced(str) && str.length()!=0){
		cout << "No";
	}
	return 0;
}