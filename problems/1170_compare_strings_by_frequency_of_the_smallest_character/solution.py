class Solution:
    def numSmallerByFrequency(self, queries: list[str], words: list[str]) -> list[int]:
        import bisect
        def f(s: str) -> int:
            return s.count(min(s))
        word_freqs = sorted(f(w) for w in words)
        return [len(word_freqs) - bisect.bisect_right(word_freqs, f(q)) for q in queries]
