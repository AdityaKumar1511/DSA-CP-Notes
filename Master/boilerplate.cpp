#include <bits/stdc++.h>
using namespace std;

// --- Fast I/O Optimization ---
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// --- Shortcuts & Aliases ---
#define pb push_back
#define po pop_back
#define gcd __gcd
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define v vector
#define bits __builtin_popcountll
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

// --- Data Type Redefinition ---
#define int long long

// --- Constants ---
const int mod = 998244353;
const int MAX_PRIME = 1000000;

// --- Global Data Structures ---
v<int> prime(MAX_PRIME + 1, 1);

// --- Precomputation (Sieve of Eratosthenes) ---
void sieve() {
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= MAX_PRIME; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                prime[j] = 0;
            }
        }
    }
}

// --- Binary Exponentiation ---
int binexp(int a, int b) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// --- Core Logic Block ---
void solve() {
    
}

// --- Execution Entry Point ---
signed main() {
    fastio();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // sieve();

    int t = 1;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    #ifndef ONLINE_JUDGE
    fflush(stdout);
    #endif

    return 0;
}