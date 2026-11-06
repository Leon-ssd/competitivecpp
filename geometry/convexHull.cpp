#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
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

// const int MOD = 1e9+7;
vi dsu;
vvi pueblos;

vpairint puntos;
vll areas;

struct Point {
    double x, y;

    // Operator to check equality of two points
    bool operator==(const Point& t) const {
        return x == t.x && y == t.y;
    }
};

 // Function to find orientation of the triplet (a, b, c)
 // Returns -1 if clockwise, 1 if counter-clockwise, 0 if collinear
int orientation(Point a, Point b, Point c) {
    double v = a.x * (b.y - c.y) + 
               b.x * (c.y - a.y) + 
               c.x * (a.y - b.y);
    if (v < 0) return -1; 
    if (v > 0) return +1; 
    return 0;
}

 // Function to calculate the squared distance between two points
double distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + 
           (a.y - b.y) * (a.y - b.y);
}

 // Function to find the convex hull of a set of 2D points
vector<vector<ll>> findConvexHull(vector<vector<int>> points) {

    // Store number of points points
    int n = points.size();

    // Convex hull is not possible if there are fewer than 3 points
    if (n < 3) return {{-1}};

    // Convert points 2D vector into vector of Point structures
    vector<Point> a;
    for (auto& p : points) {
        a.push_back({(double)p[0], (double)p[1]});
    }

    // Find the point with the lowest y-coordinate (and leftmost in case of tie)
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    // Sort points based on polar angle with respect to the reference point p0
    sort(a.begin(), a.end(), [&p0](const Point& a, const Point& b) {
        int o = orientation(p0, a, b);

        // If points are collinear, keep the farthest one last
        if (o == 0) {
            return distSq(p0, a) < distSq(p0, b);
        }

        // Otherwise, sort by counter-clockwise order
        return o < 0;
    });

    // Vector to store the points on the convex hull
    vector<Point> st;

    // Process each point to build the hull
    for (int i = 0; i < (int)a.size(); ++i) {

        // While last two points and current point make a non-left turn, remove the middle one
        while (st.size() > 1 && orientation(st[st.size() - 2], st.back(), a[i]) >= 0)
            st.pop_back();

        // Add the current point to the hull
        st.push_back(a[i]);
    }

    // If fewer than 3 points in the final hull, return {-1}
    if (st.size() < 3) return {{-1}};

    // Convert the final hull into a vector of vectors of integers
    vector<vector<ll>> result;
    for (auto& p : st) {
        result.push_back({(ll)p.x, (ll)p.y});
    }

    return result;
}

ll polygonArea(vvll puntos)
{
    int n = puntos.size();
    
    ll area = 0;

    
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {

        area += (puntos[j][0] + puntos[i][0]) * (puntos[j][1]  - puntos[i][1]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area);
}

int find(int fa){
    if(dsu[fa] == fa){
        return fa;
    }
    return find(dsu[fa]);
}
void pasar(int a,int b){
    // todo a pasa a b
    // A es el nuevo padre 
    for(auto e: pueblos[a]){
        pueblos[b].push_back(e);
    }
    // FO(i, 0, pueblos[a].size()-1){
    //     pueblos[b].push_back(pueblos[a][i]);
    // }
}
int unir(int a,int b){
    int padr = 1 ;
    
    if(pueblos[a].size() > pueblos[b].size()){
        dsu[b] = a;
        pasar(b, a);
        padr = a;  
        //pasar todo a a
        
    }else{
        dsu[a]= b;
        pasar(a, b);
        padr = b;
        //pasar todo a b
    }
   
    vvi puntox ;
    for(auto pu: pueblos[padr]){
        puntox.push_back({puntos[pu].first,puntos[pu].second});
    }
    vvll convex = findConvexHull(puntox) ;
    //convex 
    if(convex.size() == 1 && convex[0][0] == -1){
        areas[padr] = 0;
        return padr;
    }

    
    // area del convex
    areas[padr] = polygonArea(convex);
    return padr;
}

void solve(){
    int n,m; cin >> n >> m;
    dsu.resize(n+1);
    pueblos.resize(n+1);
    puntos.resize(n+1);
    areas.resize(n+1);
    FO(i,1,n){
        dsu[i]= i;
        pueblos[i].push_back(i);
    }

    FO(i,1,n){
        cin >> puntos[i].first >> puntos[i].second;
       // cout << puntos[i].first << puntos[i].second << N;
    }
    int p1,p2;
    FO(i,1,m){
        cin >> p1 >> p2;
        int fa = find(p1);
        int fb = find(p2);
        if(fa==fb){
            cout << areas[fa] << N;
            continue;
        }
       // dsu[fa]= fb;

        int padredetodo =   unir(fa, fb);
        cout << areas[padredetodo] << N;

       // mira(dsu);
    }

}

int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

