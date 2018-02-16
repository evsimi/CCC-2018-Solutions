n = int(input())
v = [int(input()) for i in range(n)]
v.sort()
print(min((v[i + 1] - v[i - 1]) / 2 for i in range(1, n - 1)))
