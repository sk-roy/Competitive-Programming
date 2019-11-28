// Topic   : Digit DP
// Problem : LightOJ 1140

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[12][90][2][2];
vector <ll> v;
ll vz;

ll roy(ll i, ll zero, bool lw, bool nlz){
    if(i==vz){
        if(lw && !nlz) return 1;
        else if(lw) return zero;
        else return 0;
    }
    if(dp[i][zero][lw][nlz] != -1) return dp[i][zero][lw][nlz];

    ll k = 0;
    for(ll j=0; j<10; j++){
        if(!lw && j>v[i]) break;

        if(!j) k += roy(i+1, zero+((nlz)?1:0), (lw | (j<v[i])), nlz);
        else k += roy(i+1, zero, (lw | (j<v[i])), 1);
    }

    return dp[i][zero][lw][nlz] = k;
}

ll solve(ll n){

    v.clear();
    while(n){
        v.push_back(n%10);
        n /= 10;
    }
    if(v.empty()) v.push_back(0);
    vz = v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));

    ll k = roy(0, 0, 0, 0);
    return k;
}

int main(){
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,tc,m,n,k;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>m>>n;
        k = solve(n+1) - solve(m);
        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
