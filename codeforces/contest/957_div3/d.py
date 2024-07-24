#!/usr/bin/env python

def run() -> None:
    n,m,k = map(int, input().split())
    A = input()
    logs = [i for i in range(n) if A[i] == "L"]
    logs.append(n+1)
    i = -1
    next_log = 0
    while i < n-1:
        if m >= logs[next_log] - i:
            i = logs[next_log]
        else:
            i+=m
            if i > n-1:
                print("YES")
                return
            while i < n and i < logs[next_log]:
                if A[i] != "C" and k > 0:
                    i+=1
                    k-=1
                else:
                    print("NO")
                    return
        next_log +=1
    print("YES")

for _ in range(int(input())):
    run()
