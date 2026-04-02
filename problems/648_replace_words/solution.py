class Solution:
    def replaceWords(self, dictionary: list[str], sentence: str) -> str:
        root_set = set(dictionary)
        words = sentence.split()
        result = []
        for word in words:
            replaced = word
            for i in range(1, len(word) + 1):
                if word[:i] in root_set:
                    replaced = word[:i]
                    break
            result.append(replaced)
        return ' '.join(result)
