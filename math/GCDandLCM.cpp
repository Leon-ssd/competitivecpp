#define ll long long

ll mcd(ll a,ll b){
    while (b!=0) {
        ll t = b;
        b = a%b;
        a = t;
    }
    return a;
}
ll mcm(ll a,ll b){
    return (a*b)/ mcd(a,b);
}
