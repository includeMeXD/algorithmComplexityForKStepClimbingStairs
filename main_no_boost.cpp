#include <iostream>
#include <cstdlib> // Required for atoi

using namespace std;

// Recursive Solution: O(k^n)
long long countWaysRecursive(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    long long ways = 0;
    for (int i = 1; i <= k; i++) {
        ways += countWaysRecursive(n - i, k);
    }
    return ways;
}

// Iterative Solution: O(n*k)
long long countWaysIterative(int n, int k) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    long long dp[10001];
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main(int argc, char* argv[]) {
    // We expect 4 arguments: program_name, n, k, and type
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " <n> <k> <type>" << endl;
        cout << "Type: 0 for Recursive, 1 for Iterative" << endl;
        return 1;
    }

    // Convert string arguments to integers
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int type = atoi(argv[3]);

    if (type == 0) {
        // Only run Recursive
        cout << countWaysRecursive(n, k) << endl;
    } else if (type == 1) {
        // Only run Iterative
        cout << countWaysIterative(n, k) << endl;
    } else {
        cout << "Invalid type. Use 0 for Recursive or 1 for Iterative." << endl;
        return 1;
    }

    return 0;
}
