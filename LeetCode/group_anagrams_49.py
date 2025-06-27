class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for word in strs:
            count = [0]*26
            for w in word:
                count[ord(w) - ord("a")] += 1
            res[tuple(count)].append(word)
        return list(res.values())


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for word in strs:
            res[tuple(sorted(word))].append(word)
        return list(res.values())


            