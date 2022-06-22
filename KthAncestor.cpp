#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int dp[n][31];
    for(int i=0;i<n;i++){
        for(int j=0;j<31;j++)dp[i][j]=0;
    }
    int parent[n];
    for(int i=0;i<n;i++){
        cin>>parent[i];
        dp[i][0]=parent[i]; //1st ancestor of ith node
    }
    for(int j=1;j<31;j++){
        for(int i=0;i<n;i++){
            //2^j th ancestor of ith node
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<31;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    int q; cin>>q;
    while(q--){
        int val,k; cin>>val>>k;
        //kth ancestor of val node
        for(int i=0;i<31;i++){
            if(((1<<i)&k) > 0){
                val = dp[val][i];
            }
        }
        cout<<val<<endl;
    }

    
    return 0;
}