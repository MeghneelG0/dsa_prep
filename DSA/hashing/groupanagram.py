def anagram(strs):
    hashmap = {}
    for word in strs:
        sorted_word = ''.join(sorted(word))
        hashmap[sorted_word] = hashmap.get(sorted_word, []) + [word]
    return list(hashmap.values())

def anagram(strs):
    hashmap = {}
    for word in strs:
        sorted_word = ''.join(sorted(word))
        if sorted_word not in hashmap:
            hashmap[sorted_word] = []

        hashmap[sorted_word].append(word)
    result = []
    for groups in hashmap.values():
        result.append(groups)
    return result
def solve():
    strs = ["eat","tea","tan","ate","nat","bat"]
    print(anagram(strs))