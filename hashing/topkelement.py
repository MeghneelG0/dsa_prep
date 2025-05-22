def topkelement(nums,k):
    hashmap = {}
    for num in nums:
        hashmap[num] = hashmap.get(num,0)+1
    sorted_keys = sorted(hashmap, key = lambda x: hashmap[x], reverse=True)
    return sorted_keys[:k]


def topkelement(nums,k):
    hashmap = {}
    for num in nums:
        hashmap[num] = hashmap.get(num,0)+1
    freq_list = list(hashmap.items())
    freq_list.sort(key = lambda pair: pair[1], reverse=True)
    result = []
    for i in range(k):
        result.append(freq_list[i][0])
    return result

def solve():
    nums = [1,1,1,2,2,3]
    k = 2
    print(topkelement(nums,k))
