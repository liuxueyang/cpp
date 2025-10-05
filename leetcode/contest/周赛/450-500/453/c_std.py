from collections import deque

class Solution(object):
    def countPartitions(self, nums, k):
      MOD = 10**9 + 7
      n = len(nums)
      nums = [0] + nums  # Make nums 1-based
      dp = [0] * (n + 1)
      dp[0] = 1
      prefix = [0] * (n + 1)
      prefix[0] = 1
      max_deque = deque()
      min_deque = deque()
      left = 1  # left starts from 1

      for right in range(1, n + 1):
          # Maintain max_deque (monotonic decreasing)
          while max_deque and nums[right] > nums[max_deque[-1]]:
              max_deque.pop()
          max_deque.append(right)
          # Maintain min_deque (monotonic increasing)
          while min_deque and nums[right] < nums[min_deque[-1]]:
              min_deque.pop()
          min_deque.append(right)

          # Adjust left to satisfy max - min <= k
          while nums[max_deque[0]] - nums[min_deque[0]] > k:
              if max_deque[0] == left:
                  max_deque.popleft()
              if min_deque[0] == left:
                  min_deque.popleft()
              left += 1
          
          # Compute dp[right]
          if left == 1:
              dp[right] = prefix[right - 1]
          else:
              dp[right] = (prefix[right - 1] - prefix[left - 2]) % MOD
          prefix[right] = (prefix[right - 1] + dp[right]) % MOD
    
      return dp[n] % MOD
