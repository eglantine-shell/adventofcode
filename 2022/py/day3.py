from string import ascii_letters

with open("input/day3.txt", "r") as f:
    data = f.read().splitlines()
    s = 0
    s2 = 0
    i = 0
    for line in data:
        # part1
        mid = int(len(line)/2)
        p = (set(line[:mid]) & set(line[mid:])).pop()
        s += ascii_letters.index(p) + 1
        # part2
        if i % 3 == 0:
            t = set(line)
        else:
            t = set(line) & t
            if i % 3 == 2:
                s2 += ascii_letters.index(t.pop()) + 1
        i += 1

print(s)
print(s2)