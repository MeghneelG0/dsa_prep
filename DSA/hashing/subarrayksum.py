def subsum(nums,k):
    curr_sum = 0
    count = 0
    hashmap = {0:1}
    for num in nums:
        curr_sum += num
        if curr_sum - k in hashmap:
            count += hashmap[curr_sum-k]
        hashmap[curr_sum] = hashmap.get(curr_sum,0) + 1
    return count

def solve():
    nums = [1,2,3]
    k = 3
    print(subsum(nums,k))