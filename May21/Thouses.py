cases = int(input())

while cases > 0:
    nodes, start = map(int, input().split())

    tree = [[] for i in range(nodes + 1)]
    values = [0 for i in range(nodes + 1)]

    for i in range(nodes - 1):
        parent, child = map(int, input().split())
        tree[parent].append(child)

    ans = start

    def getOrder(index):
        global tree
        global lengths

        toSort = []
        for node in tree[index]:
            toSort.append([node, values[node]])
        
        toSort.sort(key=lambda x: x[1], reverse=True)
        return toSort


    def recCalculateValues(index):
        global tree
        global values

        if len(tree[index]) == 0:
            values[index] = 1
            return 1

        count = 0
        for node in tree[index]:
            count += recCalculateValues(node)

        n = len(tree[index])
        count = count + int(n*(n+1) / 2)

        values[index] = count
        return count


    def solve(index, value):
        global tree
        global values
        global ans

        order = getOrder(index)
        for i in range(len(order)):
            ans += value * (i + 1)
            solve(order[i][0], value*(i + 1))


    # print()
    # print()
    recCalculateValues(1)
    solve(1, start)
    # print()
    # print()

    # for i in range(1, len(values)):
        # print(i, " ", values[i])

    # print(tree)
    # print(values)
    print(ans)

    cases -= 1




# 1
# 11 1
# 1 2
# 1 3
# 2 4
# 2 5
# 3 6
# 3 7
# 3 8
# 4 9
# 4 10
# 6 11