from functools import reduce

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


def calculate(facts, k):
    memeSet = {}
    ans = facts[0]
    memeSet[facts[0]] = 1
    for i in range(1, len(facts) - 1):
        for j in range(facts[i], facts[0], facts[i]*2):
            if j not in memeSet:
                ans += facts[i]
                memeSet[j] = 1

    # print(memeSet)
    return ans + 2*k - len(memeSet)



cases = int(input())
while cases != 0:
    k = int(input())
    facts = list(factors(4*k + 1))
    facts.sort(reverse=True)
    # print(facts)
    print(calculate(facts, k))

    cases -= 1
