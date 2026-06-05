#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> left(n), right(n);
    stack<int> s;

    // Find how far left each element is the minimum
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        left[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    // Clear stack for reuse
    while(!s.empty()) s.pop();

    // Find how far right each element is the minimum
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - i : s.top() - i;
        s.push(i);
    }

    long long total_sum = 0;
    for(int i = 0; i < n; i++) {
        total_sum += (long long)a[i] * left[i] * right[i];
    }

    cout << total_sum << "\n";
    return 0;
}