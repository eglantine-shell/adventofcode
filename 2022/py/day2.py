
def score (a, x):
    if (a-1)%3 == x:
        return 1 + x
    elif a == x:
        return 4 + x
    else:
        return 7 + x

def score2 (a, x):
    if x == 0:
        return (a+2)%3 + 1
    elif x == 1:
        return a + 4
    else:
        return (a+1)%3 + 7

with open("input/day2.txt", "r") as f:
    data = f.read().splitlines()
    s = 0
    s2 = 0
    for line in data:
        a, x = line.split()
        s += score(ord(a)-ord('A'), ord(x)-ord('X'))
        s2 += score2(ord(a)-ord('A'), ord(x)-ord('X'))
print(s)
print(s2)

