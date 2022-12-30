from collections import defaultdict


with open("input/day7.txt", "r") as f:
    dirs = defaultdict(int)
    cwd = []
    for line in f.read().splitlines():
        if line.startswith("$ cd"):
            if line[5:] == "..":
                cwd.pop()
            else:
                cwd.append(line[5:])
        elif line.startswith("$ ls"):
            continue
        else:
            try:
                dirs["/".join(cwd)] += int(line.split()[0])
            except:
                pass

for d in sorted(dirs.keys(), key=lambda x: x.count("/"), reverse=True):
    dirs["/".join(d.split("/")[:-1])] += dirs[d]

print(sum(s for s in dirs.values() if s <= 100_000))

need = dirs["/"] - 40_000_000
print(min(v for v in dirs.values() if v > need))