#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main() {
    // Seed the random number generator using the current time
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    // Generate an array of random size between 2 and 6
    int n = rng() % 5 + 2; 
    cout << n << "\n";
    
    // Fill the array with random numbers between 1 and 20
    for(int i = 0; i < n; i++) {
        cout << (rng() % 20 + 1) << " ";
    }
    cout << "\n";
    return 0;
}