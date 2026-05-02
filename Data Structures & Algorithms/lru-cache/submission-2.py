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
            # Update the value and move the key to the most recently used position
            self.cache.pop(key)
        elif len(self.cache) == self.capacity:
            # Remove the least recently used item (the first item in the dictionary)
            self.cache.pop(next(iter(self.cache)))
        self.cache[key] = value

