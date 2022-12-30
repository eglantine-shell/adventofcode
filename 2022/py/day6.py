def solve(s, n):
    for i in range(n, len(s)):
        if len(set(s[i-n : i])) == n:
            return i

with open("input/day6.txt", "r") as f:
    data = f.read().splitlines()
    for line in data:
        print(solve(line, 4))
        print(solve(line, 14))
