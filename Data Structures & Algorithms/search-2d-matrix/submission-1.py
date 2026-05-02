class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def binarySearch(row):
            l, r = 0, len(row)
            while l <= r:
                mid = l + (r-l) // 2
                if row[mid] > target:
                    r = mid -1
                elif row[mid] < target:
                    l = mid + 1
                else:
                    return True
            return False
        R, C = len(matrix), len(matrix[0])
        t, b = 0, R-1
        while t <= b:
            mid = t + (b-t) // 2
            if matrix[mid][0] > target:
                b = mid - 1
            elif matrix[mid][-1] < target:
                t = mid + 1
            else:
                break
        if not (t <= b):
            return False
        row = (t+b) // 2
        return binarySearch(matrix[row])

            