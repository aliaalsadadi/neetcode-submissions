class TimeMap:

    def __init__(self):
        self.keys = []
        self.values = []
        self.timestamps = []

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.keys.append(key)
        self.values.append(value)
        self.timestamps.append(timestamp)

    def get(self, key: str, timestamp: int) -> str:
        result = ""
        for i in range(len(self.keys)):
            if self.keys[i] == key and self.timestamps[i] <= timestamp:
                result = self.values[i]
        return result