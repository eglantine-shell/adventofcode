with open("input/day1.txt", "r") as f:
    data = f.read().split("\n\n")
    s = []
    for elf in data:
        cur = 0
        for c in elf.splitlines():
            cur += c
        s.append(cur)
    s= sorted(s)

print(s[-1])
print(sum(s[-3:]))