int Factorial(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return x * Factorial(x - 1);  // вычисляем факториал от x-1 и умножаем на x
    }
}