class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.hash_func_type = 1


    def hash1(self, key):
        return key % self.size
    
    def hash2(self, key, i):

        if self.hash_func_type == 1:
            return i
        elif self.hash_func_type == 2:
            return i**2
        else:
            return 1 + (key%(self.size - 1))
    
    def insert(self, key, value):
        index = self.hash1(key)
        i = 0
        if None in self.table or "ВИДАЛЕНО" in self.table or self.table[index][0] == key:
            pass
        else:
            print("Overflowed")
            return 

        while self.table[index] is not None and self.table[index] != "ВИДАЛЕНО":
            if self.table[index][0] == key:
                self.table[index][1] = value
                return
            index = (self.hash1(key) + self.hash2(key, i)) % self.size
            i += 1
        self.table[index] = [key, value]


    def search(self, key):
        index = self.hash1(key)
        i = 0
        while self.table[index] is not None and self.table[index] != "ВИДАЛЕНО":
            if self.table[index][0] == key:
                return self.table[index]
            index = (self.hash1(key) + self.hash2(key, i)) % self.size
            i += 1


    def delete(self, key):
        index = self.hash1(key)
        i = 0
        while self.table[index] is not None and self.table[index] != "ВИДАЛЕНО":
            if self.table[index][0] == key:
                self.table[index] = "ВИДАЛЕНО"
                return True
            index = (self.hash1(key) + self.hash2(key, i)) % self.size
            i += 1
            
        return False

    def chained_insert(self, key, value):
        index = self.hash1(key)
        if not self.table[index]:
            self.table[index] = [[key, value],]
        for item in self.table[index]:
            if item[0] == key:
                item[1] = value
                return
        self.table[index].append([key, value])

    def chained_delete(self, key):
        index = self.hash1(key)

        for item in self.table[index]:
            if item[0] == key:
                self.table[index].remove(item)
                return True
        return False
    
    def chained_search(self, key):
        index = self.hash1(key)
        if self.table[index]:
            for item in self.table[index]:
                if item[0] == key:
                    return item[1]
    
    def display(self):
        for i in range(self.size):
            print(f"{i}: {self.table[i]}")


if __name__ == "__main__":
    size = int(input("Введіть розмір хеш таблиці: "))
    hash_table = HashTable(size)
    chained_or_oa = int(input("Відкирита адресація '1', Адресація ланцюгом '2': "))
    if chained_or_oa == 1:
        hash_table.hash_func_type = int(input("Виберіть хеш функцію (1:лінійна, 2:квадратична, 3: подвійна) для хеш таблиці: "))
    
    
    while True:
        print("\n1. Додати")
        print("2. Пошук")
        print("3. Видалити")
        print("4. Вивести")
        print("5. Завершення")
        choice = int(input("Ваш вибір: "))
        
        if chained_or_oa == 1:
            if choice == 1:
                key = int(input("Введіть ключ: "))
                value = input("Введіть значення: ")
                hash_table.insert(key, value)
                hash_table.display()
            elif choice == 2:
                key = int(input("Введіть ключ: "))
                value = hash_table.search(key)
                if value is not None:
                    print(f"Значення для ключа {key}: {value}")
                else:
                    print(f"Ключ {key} не знайдений")
            elif choice == 3:
                key = int(input("Введіть значення: "))
                if hash_table.delete(key):
                    print(f"Ключ {key} видалено успішно")
                    hash_table.display()
                else:
                    print(f"Ключ {key} не знайдений")
            elif choice == 4:
                hash_table.display()
            elif choice == 5:
                break
            else:
                print("Некоректний вибір")
        else:
            if choice == 1:
                key = int(input("Enter key: "))
                value = input("Enter value: ")
                hash_table.chained_insert(key, value)
                hash_table.display()
            elif choice == 2:
                key = int(input("Введіть ключ: "))
                value = hash_table.chained_search(key)
                if value is not None:
                    print(f"Value for key {key}: {value}")
                else:
                    print(f"Key {key} not found")
            elif choice == 3:
                key = int(input("Введіть ключ: "))
                if hash_table.chained_delete(key):
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