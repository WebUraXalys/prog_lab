class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None or self.table[index] == "ВИДАЛЕНО":
            self.table[index] = (key, value)
        else:
            for i in range(1, self.size):
                next_index = (index + i) % self.size
                if self.table[next_index] is None or self.table[next_index] == "ВИДАЛЕНО":
                    self.table[next_index] = (key, value)
                    break

    def search(self, key):
        index = self.hash_function(key)
        for i in range(self.size):
            next_index = (index + i) % self.size
            if self.table[next_index] is None:
                return None
            elif self.table[next_index][0] == key:
                return self.table[next_index][1]
        return None

    def HashDelete(self, key):
        index = self.hash_function(key)
        for i in range(self.size):
            next_index = (index + i) % self.size
            if self.table[next_index] is None:
                return False
            elif self.table[next_index][0] == key:
                self.table[next_index] = "ВИДАЛЕНО"
                return True
        return False

    def display(self):
        for i in range(self.size):
            print(f"{i}: {self.table[i]}")



if __name__ == "__main__":
    size = int(input("Введіть розмір хеш-таблиці: "))
    hash_table = HashTable(size)
    while True:
        print("\n1. Добавити")
        print("2. Пошук")
        print("3. Видалити")
      #   print("4. Display")
        print("4. Завершення")
        choice = int(input("Виберіть задачу: "))
        if choice == 1:
            key = int(input("Введіть ключ: "))
            value = input("Введіть значення: ")
            hash_table.insert(key, value)
            hash_table.display()
        elif choice == 2:
            key = int(input("Введіть ключ: "))
            value = hash_table.search(key)
            if value is not None:
                print(f"Value for key {key}: {value}")
            else:
                print(f"Key {key} not found")
        elif choice == 3:
            key = int(input("Enter key: "))
            if hash_table.HashDelete(key):
                print(f"Key {key} deleted successfully")
                hash_table.display()
            else:
                print(f"Key {key} not found")
        elif choice == 4:
            hash_table.display()
        elif choice == 5:
            break
        else:
            print("Invalid choice")
