def solve(data, rope):
    v = [[0, 0] for _ in range(rope)]
    st = set()
    for line in data.splitlines():
        act, step = line.split(' ')
        for _ in range(int(step)):
            if act == "D":
                v[0][1] += 1
            elif act == "U":
                v[0][1] -= 1
            elif act == "L":
                v[0][0] -= 1
            else:
                v[0][0] += 1
            for i, ((hx, hy), (tx, ty)) in enumerate(zip(v, v[1:])):
                if abs(hx - tx) > 1:
                    tx += 1 if hx > tx else -1
                    if abs(hy - ty) > 0:
                        ty += 1 if hy > ty else -1
                elif abs(hy - ty) > 1:
                    ty += 1 if hy > ty else -1
                    if abs(hx - tx) > 0:
                        tx += 1 if hx > tx else -1
                v[i + 1][0] = tx
                v[i + 1][1] = ty
                st.add(tuple(v[-1]))
    return len(st)

with open("input/day9.txt", "r") as f:
    data = f.read()
    print(solve(data, 2))
    print(solve(data, 10))