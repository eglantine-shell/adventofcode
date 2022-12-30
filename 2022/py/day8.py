with open("/Users/yetingzhi/Documents/GIT/adventofcode/input/day8.txt", "r") as f:
    trees = [list(map(int, line)) for line in f.read().splitlines()]
    count = 0
    mx = 0
    for i in range(len(trees)):
        for j in range(len(trees[i])):
            see = 0
            score = 1
            flag = 0
            for x in range(i-1, -1, -1):
                if trees[x][j] >= trees[i][j]:
                    score *= i-x
                    flag = 1
                    break
            if flag == 0: 
                score *= i
                see = 1
            flag = 0
            for x in range(i+1, len(trees)):
                if trees[x][j] >= trees[i][j]:
                    score *= x-i
                    flag = 1
                    break
            if flag == 0: 
                score *= len(trees)-i-1
                see = 1
            flag = 0
            for y in range(j-1, -1, -1):
                if trees[i][y] >= trees[i][j]:
                    score *= j-y
                    flag = 1
                    break
            if flag == 0: 
                score *= j
                see = 1
            flag = 0
            for y in range(j+1, len(trees[i])):
                if (trees[i][y] >= trees[i][j]):
                    score *= y-j
                    flag = 1
                    break
            if flag == 0: 
                score *= len(trees[i])-j-1
                see = 1
            count += see
            if score > mx: mx = score
                    
    print(count)
    print(mx)