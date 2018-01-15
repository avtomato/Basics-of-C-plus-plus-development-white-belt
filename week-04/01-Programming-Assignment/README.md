#### Задание по программированию: Структура LectureTitle ####

Дана структура *LectureTitle*:
```objectivec
struct LectureTitle {
  string specialization;
  string course;
  string week;
};
```
Допишите конструктор и структуры *Specialization*, *Course*, *Week* так, чтобы объект *LectureTitle* можно было создать с помощью кода
```objectivec
LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
```
но нельзя было с помощью следующих фрагментов кода:
```objectivec
LectureTitle title("C++", "White belt", "4th");

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
    Course("White belt"),
    Specialization("C++"),
    Week("4th")
);

LectureTitle title(
    Specialization("C++"),
    Week("4th"),
    Course("White belt")
);
```

##### Пояснение #####
В этой задаче вам надо прислать на проверку файл с реализацией необходимых классов. **Этот файл не должен содержать функцию main**. Если в нём будет функция *main*, вы получите ошибку компиляции.
