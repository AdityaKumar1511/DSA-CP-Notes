#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_sum = 0;

    // Outer loop sets the STARTING point of the subarray
    for (int i = 0; i < n; i++) {
        int current_min = a[i];

        // Inner loop expands the ENDING point of the subarray
        for (int j = i; j < n; j++) {
            // Keep track of the minimum value seen in the current subarray a[i...j]
            current_min = min(current_min, a[j]);
            
            // Add it to our total answer
            total_sum += current_min;
        }
    }

    cout << total_sum << "\n";
    return 0;
}