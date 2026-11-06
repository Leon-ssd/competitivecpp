//ojo con el 1
bool esPrimo(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 ) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0 ) {
            return false;
        }
    }
    
    return true;
}
