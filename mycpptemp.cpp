// Soldier - focus on doing the little things you know you should do
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <iterator>
#include <set>
    
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fr(i,n) for (ll i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std; 

bool compareInterval(pair<ll, ll> p1, pair<ll, ll> p2){
    return (p1.second < p2.second);
}

const int MOD = 1e9 + 7; 

void solve(){
    ll n; cin>>n;   
    vector<ll> v(n, 0); fr(i, n) {cin>>v[i];}
    
    sort(v.begin(), v.end());
    // sort(v.begin(), v.end(), compareInterval);
    // multiset<ll> ms;
} 
    
int main(){
    fast
    
    #ifndef ONLINE_JUDGE
    freopen( "input.txt" , "r" , stdin);
    #endif
    
    ull tc; cin>>tc;
    while (tc--)
    solve();
    
    return 0;
}
