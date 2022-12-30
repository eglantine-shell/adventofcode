
import re

with open("input/day4.txt", "r") as f:
    data = re.findall(r'(\d+)-(\d+),(\d+)-(\d+)', f.read())
    data = [[int(n) for n in line] for line in data]
    count = 0
    count2 = 0
    for a, b, c, d in data:
        if (c <= a and b <= d) or (a <= c and d <= b):
            count += 1
        if (max(a, c) <= min(b, d)):
            count2 += 1
    
print(count)
print(count2)
