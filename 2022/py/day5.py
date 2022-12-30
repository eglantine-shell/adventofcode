import re

with open("input/day5.txt", "r") as f:
    part1, part2 = f.read().split("\n\n")
    stacks = [[] for _ in range(10)]
    for line in part1.splitlines():
        for i in range(1, len(line), 4):
            if line[i].strip().isalpha():
                stacks[(i-1)//4+1].append(line[i])

    moves = re.findall(r"move (\d+) from (\d+) to (\d+)", part2)
    moves = [[int(n) for n in move] for move in moves]
    for num, f, t in moves:
        move = stacks[f][:num]
        # move = move[::-1]
        stacks[f] = stacks[f][num:]
        stacks[t] = move + stacks[t]

print("".join(stack[0] for stack in stacks[1:]))