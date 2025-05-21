def anagram(strs):
    hashmap = {}
    for word in strs:
        sorted_word = ''.join(sorted(word))
        hashmap[sorted_word] = hashmap.get(sorted_word, []) + [word]
    return list(hashmap.values())

def solve():
    strs = ["eat","tea","tan","ate","nat","bat"]
    print(anagram(strs))