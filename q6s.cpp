// STRONGEST FIGHTER
// There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

// Input Format:
// First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

// Constraints:
// 1<=N<=10^5 1<=k<=N

// Output Format
// Space separated integers in a single line denoting strength of strongest fighters in the groups.

// Sample Input
// 5
// 1 3 1 4 5
// 3
// Sample Output
// 3 4 5
#include<iostream>
#include<deque>
using namespace std;

void strongestfighter(int n,int *a,int k){
    deque<int>q;
    int i;
    for(i=0;i<k;i++){
        while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++){
        cout << a[q.front()] << " ";
        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }
        while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << a[q.front()] << " ";
}
int main() {
    int n;
    cin>>n;
    int a[1000005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    strongestfighter(n,a,k);
	return 0;
}