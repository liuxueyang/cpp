MOD = 998244353

n, k = map(int, input().split())
S = input().strip()

from collections import defaultdict

prev_dp = defaultdict(lambda: defaultdict(int))

# Initialize first position
if S[0] == '0':
    for d in range(1, k + 1):
        prev_dp[d][1] = 1
else:
    d = int(S[0])
    prev_dp[d][1] = 1

for i in range(1, n):
    curr_dp = defaultdict(lambda: defaultdict(int))
    for prev_d in prev_dp:
        for l in prev_dp[prev_d]:
            count = prev_dp[prev_d][l]
            if S[i] == '0':
                possible_digits = range(1, k + 1)
            else:
                possible_digits = [int(S[i])]
            for d in possible_digits:
                if d == prev_d:
                    new_l = l + 1
                    if new_l < k:
                        curr_dp[d][new_l] = (curr_dp[d][new_l] + count) % MOD
                else:
                    curr_dp[d][1] = (curr_dp[d][1] + count) % MOD
    prev_dp = curr_dp

result = 0
for d in prev_dp:
    for l in prev_dp[d]:
        result = (result + prev_dp[d][l]) % MOD

print(result)
