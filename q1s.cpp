/*FIND THE GREATER ELEMENT
We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

Input Format:
First line contains the length of the array n. Second line contains the n space separated integers.

Constraints:
1 <= n <= 10^6
-10^8 <= Ai <= 10^8 , 0<= i< n

Output Format
Print n space separated integers each representing the next greater element.

Sample Input
3
1 2 3
Sample Output
2 3 -1*/
#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int front=0;
    int rear=1;
    while(front<n){
        while(front!=rear){
            if(a[rear]>a[front]){
                cout << a[rear] << " ";
                break;
            }
            rear=(rear+1)%n;
        }
        if(front==rear){
            cout << "-1" << " ";
        }
        front++;
        rear=(front+1)%n;
    }
	return 0;
}