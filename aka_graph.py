import time

import matplotlib.pyplot as plt


# Recursive Solution: O(k^n)
def countWaysRecursive(n, k):
    if n == 0:
        return 1
    if n < 0:
        return 0
    ways = 0
    for i in range(1, k + 1):
        ways += countWaysRecursive(n - i, k)
    return ways


# Iterative Solution: O(n*k)
def countWaysIterative(n, k):
    if n < 0:
        return 0
    if n == 0:
        return 1

    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if i - j >= 0:
                dp[i] += dp[i - j]
    return dp[n]


# Fixed k value
k = 5

# Range of n values (keep small for recursion)
n_values = range(1, 30)

recursive_times = []
iterative_times = []

for n in n_values:
    # Measure recursive time
    start = time.perf_counter()
    countWaysRecursive(n, k)
    recursive_times.append(time.perf_counter() - start)

    # Measure iterative time
    start = time.perf_counter()
    countWaysIterative(n, k)
    iterative_times.append(time.perf_counter() - start)

# Plot the results
plt.figure()
plt.plot(n_values, recursive_times, label="Recursive O(k^n)")
plt.plot(n_values, iterative_times, label="Iterative O(n·k)")
plt.xlabel("n")
plt.ylabel("Execution Time (seconds)")
plt.title("Running Time Comparison (k = 5)")
plt.legend()
plt.show()
