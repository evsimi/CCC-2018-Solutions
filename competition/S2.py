# Read the size and values of the table
n = int(input())
t = [[int(v) for v in input().split(' ')] for i in range(n)]

# Determine the number of times to rotate
r = (2 if t[0][0] > t[1][0] else 1) if t[0][0] > t[0][1] else (3 if t[0][0] > t[1][0] else 0)

# Rotate r times by transforming coordinates
while r > 0:
    t = [[t[j][n - i - 1] for j in range(n)] for i in range(n)]
    r -= 1

# Print the table
for row in t:
    print(' '.join(str(v) for v in row))
