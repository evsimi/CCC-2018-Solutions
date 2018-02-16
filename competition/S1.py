# Read the number of villages and village positions
n = int(input())
v = [int(input()) for i in range(n)]

# Sort the village positions so they are in order
v.sort()

# Print the smallest value of (next position - previous positions) / 2, excluding first and last
print(min((v[i + 1] - v[i - 1]) / 2 for i in range(1, n - 1)))
