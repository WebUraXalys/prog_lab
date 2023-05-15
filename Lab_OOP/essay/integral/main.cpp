#include <iostream>
#include <cmath>

using namespace std;

double rectangle_method(double a, double b, int N, double (*f)(double)) {
    double h = (b - a) / N;  // обчислюємо ширину прямокутників
    double integral = 0;  // ініціалізуємо значення інтеграла
    for (int i = 0; i < N; i++) {
        double x_i = a + i * h;  // обчислюємо координату х для лівої точки прямокутника
        integral += f(x_i) * h;  // додаємо площу прямокутника до інтеграла
    }
    return integral;
}

double f(double x) {
    return x + 4 - 2*x - 1;  // приклад функції
}

int main() {
    double a, b;
    int N;
    cout << "Введіть початок інтервалу(a): ";
    cin >> a;
    cout << "Введіть кінець інтервалу(b): ";
    cin >> b;
    cout << "Введіть кількість прямокутників(N): ";
    cin >> N;
    double result = rectangle_method(a, b, N, f);
    cout << "Результат: " << result << endl;
    return 0;
}
