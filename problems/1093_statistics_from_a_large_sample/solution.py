class Solution:
    def sampleStats(self, count: list[int]) -> list[float]:
        minimum = -1
        maximum = -1
        total = 0
        n = 0
        mode = 0
        max_count = 0
        for i in range(256):
            if count[i] > 0:
                if minimum == -1:
                    minimum = i
                maximum = i
                total += i * count[i]
                n += count[i]
                if count[i] > max_count:
                    max_count = count[i]
                    mode = i
        mean = total / n
        mid1 = (n - 1) // 2
        mid2 = n // 2
        median = 0
        cumul = 0
        m1 = m2 = 0
        for i in range(256):
            cumul += count[i]
            if m1 == 0 and cumul > mid1:
                m1 = i
            if m2 == 0 and cumul > mid2:
                m2 = i
        median = (m1 + m2) / 2
        return [float(minimum), float(maximum), mean, median, float(mode)]
