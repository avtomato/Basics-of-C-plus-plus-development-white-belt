#### Задание по программированию: Обратимая функция с умножением и делением ####

Добавьте в класс *Function* из задачи «Обратимая функция» обработку умножения (__'*'__) и деления (__'/'__). Гарантируется отсутствие элементарных операций умножения и деления на 0.

##### Пример #####
###### Код ######
```objectivec
struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
```
###### Вывод ######
```objectivec
72
5
```

##### Пояснение #####
В этой задаче вам надо прислать на проверку файл с реализацией необходимых классов. **Этот файл не должен содержать функцию main**. Если в нём будет функция *main*, вы получите ошибку компиляции.
