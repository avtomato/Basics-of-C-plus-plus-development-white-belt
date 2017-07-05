#### Тренировочное задание по программированию: Отсортированные строки ####

Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода:
```objectivec
class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
  }
private:
  // приватные поля
};
```

**Пример**

Код
```objectivec
void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}
```

Вывод
```objectivec
first second third
first second second third
```

**Пояснение**

В этой задаче вам надо прислать файл с реализацией класса *SortedStrings*. **Этот файл не должен содержать функцию main**. Если в нём будет функция *main*, вы получите ошибку компиляции.