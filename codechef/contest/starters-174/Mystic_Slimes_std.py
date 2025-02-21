def calc_prefix(a):
    n = len(a)
    mark = [0]*(n+1)
    pref = [0]*n
    
    ans = 0
    for i in range(n):
        mark[min(a[i], n)] = 1
        while mark[ans]: ans += 1
        pref[i] = ans
    return pref

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    premex = calc_prefix(a)
    sufmex = calc_prefix(a[::-1])[::-1]

    target = premex[-1]
    optsuf = n-1
    while sufmex[optsuf] != target: optsuf -= 1

    link = [n]*n
    nxt = [n]*n
    for i in reversed(range(n)):
        if a[i] < target:
            link[i] = nxt[a[i]]
            nxt[a[i]] = i
    
    presum = [a[0]]
    for i in range(1, n): presum.append(presum[-1] + a[i])

    from_here = 1
    if target > 0: from_here = max(nxt[:target])

    mn, mx, pref = 10**18, -10**18, 0
    for i in range(optsuf - 1):
        if a[i] < target: from_here = max(from_here, link[i])
        if target == 0: from_here = i+1
        pref += a[i]

        if premex[i] != target: continue
        if from_here >= optsuf: break

        # max: [0, i], [i+1, from_here], [from_here+1, n-1]
        # min: [0, i], [i+1, optsuf-1], [optsuf, n-1]
        mx = max(mx, pref + presum[-1] - presum[from_here] - presum[from_here] + presum[i])
        mn = min(mn, pref + presum[-1] - presum[optsuf - 1] - presum[optsuf - 1] + presum[i])
    if mn == 10**18: mn = mx = -1
    print(mn, mx)