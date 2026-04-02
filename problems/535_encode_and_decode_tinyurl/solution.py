class Codec:
    def __init__(self):
        self.map = {}
        self.counter = 0
    
    def encode(self, longUrl: str) -> str:
        self.counter += 1
        key = str(self.counter)
        self.map[key] = longUrl
        return 'http://tinyurl.com/' + key
    
    def decode(self, shortUrl: str) -> str:
        key = shortUrl.split('/')[-1]
        return self.map[key]
