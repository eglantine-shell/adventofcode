with open("input/day10.txt", "r") as f:
    data = f.read().splitlines()
    ans = 0
    cycle = 1
    x = 1
    pix = ""
    for line in data:
        if cycle in (20, 60, 100, 140, 180, 220): ans += x * cycle
        if (cycle-1) % 40 == 0: pix += '\n'
        if (cycle-1) % 40 in (x-1, x, x+1): pix += '#'
        else: pix += '.'
        if line.startswith("noop"):
            cycle += 1
        else:
            if cycle % 40 == 0: pix += '\n'
            if cycle % 40 in (x-1, x, x+1): pix += '#'
            else: pix += '.'
            if (cycle+1) in (20, 60, 100, 140, 180, 220): ans += x * (cycle+1)
            cycle += 2
            x += int(line.split()[1])

print(ans)
print(pix)