import time


# Recursive Solution: O(k^n)
def count_ways_recursive(n, k):
    if n == 0:
        return 1
    if n < 0:
        return 0

    ways = 0
    for i in range(1, k + 1):
        ways += count_ways_recursive(n - i, k)
    return ways


# Iterative Solution: O(n * k)
def count_ways_iterative(n, k):
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


def main():
    print("Count Ways Program")
    print("Type 0 for Recursive, 1 for Iterative")

    n = int(input("Enter n: "))
    k = int(input("Enter k: "))
    method_type = int(input("Enter type (0 or 1): "))

    # Start timing
    start_time = time.perf_counter()

    if method_type == 0:
        result = count_ways_recursive(n, k)
    elif method_type == 1:
        result = count_ways_iterative(n, k)
    else:
        print("Invalid type. Use 0 for Recursive or 1 for Iterative.")
        return

    # End timing
    end_time = time.perf_counter()
    elapsed_ms = (end_time - start_time) * 1000

    print(f"\nResult: {result}")
    print(f"Running time: {elapsed_ms:.3f} ms")


if __name__ == "__main__":
    main()
