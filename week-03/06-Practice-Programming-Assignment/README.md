#### Тренировочное задание по программированию: Строка ####

Реализуйте класс *ReversibleString*, хранящий строку и поддерживающий методы *Reverse* для переворота строки и *ToString* для получения строки.

##### Пример #####
###### Код ######
```objectivec
int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
```

###### Вывод ######
```objectivec
evil
live
""
```

##### Пояснение #####
В этой задаче вам надо прислать на проверку файл с реализацией класса *ReversibleString*. **Этот файл не должен содержать функцию main**. Если в нём будет функция *main*, вы получите ошибку компиляции.
