def main():
    jar = Jar()
    print(jar.capacity)
class Jar:
    def __init__(self, capacity=12):
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if n > self.capacity:
            raise ValueError
        else:
            self.size += n
            self.capacity -= n

    def withdraw(self, n):
        if n > self.size:
            raise ValueError
        else:
            self.size -= n
            self.capacity += n
    @property
    def capacity(self):
        return self._capacity
    @property
    def size(self):
        return self._size


if __name__ == "__main__":
    main()