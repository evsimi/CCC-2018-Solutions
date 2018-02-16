n = int(input())
t = [[int(v) for v in input().split(' ')] for i in range(n)]

r = (2 if t[0][0] > t[1][0] else 1) if t[0][0] > t[0][1] else (3 if t[0][0] > t[1][0] else 0)

while r > 0:
    t = [[t[j][n - i - 1] for j in range(n)] for i in range(n)]
    r -= 1

for row in t:
    print(' '.join(str(v) for v in row))
