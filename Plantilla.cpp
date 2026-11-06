#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define N "\n"
#define ll long long int

#define ull unsigned long long int

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define rfor0(i, n) for (int i = n - 1; i >= 0; i--)
#define rfor1(i, n) for (int i = n; i >= 1; i--)

#define FO(i, a, b) for (int i = a; i <= b; i++)
#define RFO(i, a, b) for (int i = a; i >= b; i--)

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define LEE(v) for (auto &x : v) cin >> x;
#define pairll pair<ll, ll>
#define pairint pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vpairll vector<pairll>
#define vpairint vector<pairint>

#define mira(v) for (const auto &x : v) cout << x << " "; cout << endl;

using namespace std;

// const int MOD = 1e9+7;
int check(vll v,ll mid,ll ida){
    int n = v.size();
    FO(i,1,n){
        ll obt = (ida*i) + (mid*(n-i+1));
        if(obt == v[i])continue;
        if(obt > v[i])return 3;
        else return 1;
    }
    return 2;

}
void solve(){
    ll n ; cin >> n; 
    vll v(n+1);
    FO(i,1,n) cin>>v[i];
    ll l = 0;
    ll r = v[1]/n;

    bool yes = false;
    while(l <= r){
        ll mid = l+ (r-l)/2;
        ll ida = v[1] - (mid*n);
        int c = check(v,mid,ida);
        if(c==2){
            yes = true;
            break;
        }else if(c == 1){
            r = mid-1;
        }else{
            l = mid+1;
        }   
    }

    cout << (yes?"YES":"NO")<< N;



}

int main()
{
    fastio();
    int t = 1;
     cin >> t;
    while (t--)
    {
        solve();
    }
}

