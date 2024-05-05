#!/usr/bin/env python3

import random


def generate_str(n):
    divs = []

    for i in range(n):
        if n % (i + 1) == 0:
            divs.append(i + 1)
    s = ""
    for i in range(26):
        s += chr(ord("a") + i)

    for x in divs:
        t = s[0:x]
        res = ""
        for j in range(n // x):
            l = list(t)
            random.shuffle(l)
            res += "".join(l)
        print(x, res)


if __name__ == "__main__":
    generate_str(1000)
