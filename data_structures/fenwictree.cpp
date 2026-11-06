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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define rfor0(i, n) for (int i = n - 1; i >= 0; i--)
#define rfor1(i, n) for (int i = n; i >= 1; i--)
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vll>

using namespace std;

// const int MOD = 1e9+7;


 struct Fenwic{
    vll v;
    int n;
    Fenwic(int n){
        this->n = n +1;
        v.resize(n+1);
    }
    ll sum(int r){
        ll su  = 0;
        for(;r>0;r -= r&-r)su += v[r];
        return su;
    }

    void insert(int pos,ll val){
        for(;pos<=n;pos += pos & -pos)v[pos] += val;
    }

    ll suran(int l,int r){
        return (sum(r) - sum(l-1));
    }
};

void solvekin(){
 int n,q; cin >> n >> q;
 Fenwic fen(n);
 for1(i, n){
    ll a; cin >> a;
    fen.insert(i, a);
 }
 for1(i, q){
    int l,r;cin>> l >> r;
    cout << fen.suran( l,  r) << N;
 }

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

  //   cin >> t;
    while (t--)
    {
        solvekin();
    }
}

