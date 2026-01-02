#include <iostream>
#include <cstdlib>
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace std::chrono;
using boost::multiprecision::cpp_int;

// Recursive Solution: O(k^n)
cpp_int countWaysRecursive(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    cpp_int ways = 0;
    for (int i = 1; i <= k; i++) {
        ways += countWaysRecursive(n - i, k);
    }
    return ways;
}

// Iterative Solution: O(n*k)
cpp_int countWaysIterative(int n, int k) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    cpp_int dp[10001];
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
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " <n> <k> <type>" << endl;
        cout << "Type: 0 for Recursive, 1 for Iterative" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int type = atoi(argv[3]);

    cpp_int result;

    // First, time a single execution
    auto start = high_resolution_clock::now();
    if (type == 0) {
        result = countWaysRecursive(n, k);
    } else if (type == 1) {
        result = countWaysIterative(n, k);
    } else {
        cout << "Invalid type. Use 0 for Recursive or 1 for Iterative." << endl;
        return 1;
    }
    auto end = high_resolution_clock::now();

    auto duration_us = duration_cast<microseconds>(end - start);

    cout << "Result: " << result << endl;

    if (duration_us.count() == 0) {
        // If the single execution was too fast, run it in a loop
        int repetitions = 100000;
        cout << "Single execution too fast. Running " << repetitions << " repetitions to get an average time." << endl;

        auto loop_start = high_resolution_clock::now();
        for (int i = 0; i < repetitions; ++i) {
            if (type == 0) {
                result = countWaysRecursive(n, k);
            } else {
                result = countWaysIterative(n, k);
            }
        }
        auto loop_end = high_resolution_clock::now();

        auto total_duration = loop_end - loop_start;
        double avg_duration_ns = duration_cast<nanoseconds>(total_duration).count() / (double)repetitions;
        double avg_duration_us = avg_duration_ns / 1000.0;
        double avg_duration_ms = avg_duration_us / 1000.0;

        cout << "Average running time: " << avg_duration_us << " us (" << avg_duration_ms << " ms)" << endl;
    } else {
        auto duration_ms = duration_cast<milliseconds>(end - start);
        cout << "Running time: " << duration_us.count() << " us (" << duration_ms.count() << " ms)" << endl;
    }

    return 0;
}
