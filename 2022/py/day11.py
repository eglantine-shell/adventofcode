from math import prod

monkeys = []
with open("/input/day11.txt") as file:
    for lines in file.read().strip().split("\n\n"):
        _, items, operation, div, t, f = lines.split("\n")
        items = list(map(int, items[18:].split(",")))
        operation = operation[13:].replace("new", "old").replace("old", "item")
        div = int(div[20:])
        t = int(t[28:])
        f = int(f[29:])
        monkeys.append([items, operation, div, t, f])

M = prod(monkey[2] for monkey in monkeys)


inspect = [0] * len(monkeys)
for _ in range(20):
# for _ in range(10_000):
    for i, (items, operation, div, t, f) in enumerate(monkeys):
        for item in items:
            inspect[i] += 1
            exec(operation)
            item //= 3
            # item %= M
            monkeys[f if item % div else t][0].append(item)
            monkeys[i][0] = []

print(prod(sorted(inspect)[-2:]))