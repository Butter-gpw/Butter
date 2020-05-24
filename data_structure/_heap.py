class Array:
    def __init__(self, size=32):
        self.size = size
        self._item = [None] * size

    def __getitem__(self, index):
        return self._item[index]

    def __setitem__(self, index, value):
        self._item[index] = value

    def __len__(self):
        return self.size

    def clear(self, value=None):
        for i in range(self.size):
            self._item[i] = value

    def __iter__(self):
        for item in self._item:
            yield item


############
# 用数组实现堆
############

class MaxHeap:
    def __init__(self, maxsize=None):
        self.maxsize = maxsize
        self._elements = Array(maxsize)
        self._count = 0

    def __len__(self):
        return self._count

    def add(self, value):
        if self._count >= self.maxsize:
            raise Exception('full')
        self._elements[self._count] = value
        self._count += 1
        self._siftup(self._count - 1)

    def _siftup(self, ndx):  # 递归满足最大堆特性
        if ndx > 0:
            parents = int((ndx - 1) / 2)
            if self._elements[ndx] > self._elements[parents]:
                self._elements[ndx], self._elements[parents] = self._elements[parents], self._elements[ndx]
                self._siftup(parents)

    def extract(self):
        if self._count <= 0:
            raise Exception('empty')
        value = self._elements[0]
        self._count -= 1
        self._elements[0] = self._elements[self._count]
        self._siftdown(0)
        return value

    def _siftdown(self, ndx):
        left = 2 * ndx + 1
        rigth = 2 * ndx + 2
        largest = ndx

        if (left < self._count and
                self._elements[left] >= self._elements[largest] and
                self._elements[left] >= self._elements[rigth]):
            largest = left
        elif rigth < self._count and self._elements[rigth] >= self._elements[largest]:
            largest = rigth
        if largest != ndx:
            self._elements[ndx], self._elements[largest] = self._elements[largest], self._elements[ndx]
            self._siftdown(largest)
