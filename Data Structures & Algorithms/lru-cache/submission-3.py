class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity
    def get(self, key: int) -> int:
        if key in self.cache:
            # Move key to the most recently used position
            value = self.cache.pop(key)
            self.cache[key] = value
            return value
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
        else:
            if len(self.cache) == self.capacity:
                self.cache.pop(next(iter(self.cache)))
        self.cache[key] = value
