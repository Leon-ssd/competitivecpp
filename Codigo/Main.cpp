#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <random>
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

 const int MOD = 1e9+7;

int solve() {

    int k, p;
    if (!(cin >> k >> p)) return 0;

   
    vector<long long> p10(k + 2, 1);
    for (int i = 1; i <= k + 1; ++i) {
        p10[i] = (p10[i - 1] * 10) % p;
    }

    long long ans = 0;

    for (int L = 1; L <= k; ++L) {
        int m = (L + 1) / 2; 
        
        vector<long long> dp(p, 0);
        dp[0] = 1; 

      
        for (int i = 1; i <= m; ++i) {
            int izqdigx10 = L - i;
            int derdigx10 = i - 1;
            long long pes;
            
           
            if (i == L - i + 1) {
                pes = p10[izqdigx10] % p;
            } else {
                
                pes = (p10[izqdigx10] + p10[derdigx10]) % p;
            }

            vector<long long> next_dp(p);
            
          
            int primdig = (i == 1 && L > 1) ? 1 : 0;
            int ultdig = 9;

           
            for (int r = 0; r < p; ++r) {
                if (dp[r] == 0) continue;
                long long cantac11 = dp[r];
                for (int d = primdig; d <= ultdig; ++d) {
                    int next_r = (r + d * pes) % p;
                    next_dp[next_r] = (next_dp[next_r] + cantac11) % MOD;
                }
            }
            dp = next_dp;
        }

       
        ans = (ans + dp[0]) % MOD;
    }

    
    cout << ans << "\n";

    return 0;
}

int main()
{
    fastio();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
/*
N° Cuenta: 6021341538 
CI: 7137051
Nombre: Erick Nicolas Sivila del Castillo
Banco Económico 

N° Cuenta: 40019779388
CI: 10718352
Nombre: Alex Roger Martinez Ibañez
Banco Fie

N° Cuenta: 7500889025
CI: 10691917
Daniel Javier Aramayo Mancilla
Banco BNB

N° Cuenta: 10000066252079
CI: 10685662
Nombre: Ernesto Yucra Rengifo
Banco Unión

N° Cuenta: 7018474012 
CI: 7254011
Nombre: Max Leonardo Caceres Quiroga
Banco Bisa

*/