#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
// Exercice 1 : Récursivité et métaprogrammation

template<typename T>
T pow2(const T &x, const unsigned int n) {
    if (n == 0)
        return static_cast<T>(1); // Static: on connait 1 à la compilation autant le caster tout de suite à la compilation alors
    else
        return x * pow2<T>(x, n - 1);
}

/*double pow1(const double &x, const unsigned int n){
    return pow(x, n);
}*/

template<typename U>
// Une fonction constexpr peut être utilisée si elle même contient seulement des fonctions constexpr
// -> if n'est pas une fonction constexpr d'ou l'utilisationd de la fonction ternaire
constexpr U pow3(const U &x, const unsigned int n) {
    return (n == 0) ? static_cast<U>(1) : x * pow3(x, n - 1);
}

// Exercice 2 : Variadiques

template<class T>
T product(T v) {
    return v;
}

template<typename T, typename ...Args>
T product(T first, Args ...args) {
    return first * product(args...);
}

// Exercices 3 : Fonctors

template<typename T>
T productVector(const std::vector<T> &vec) {
    T result = static_cast<T>(1);
    for (const auto &v:vec) {
        result *= v;
    }
    return result;
}

template<typename T>
T productVec2(const vector<T> &vec) {
    T res = static_cast<T>(1);
    for_each(vec.begin(), vec.end(), [&res](const T &v) { res *= v; });
    return res;
}

template<typename T>
T productVec3(const vector<T> &vec) {
    return accumulate(vec.begin(), vec.end(), static_cast<T>(1), multiplies<T>());
};

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Multiplier valeurs du vecteur par 'for' : " << productVector(v) << endl;
    cout << "Multiplier valeurs du vecteur par 'fonctor' : " << productVec2(v) << endl;
    cout << "Multiplier valeurs du vecteur par 'accumulate' : " << productVec3(v) << endl;


    cout << pow2<double>(5, 2) << endl;
    cout << pow3(5, 2) << endl;

    cout << product(1, 2, 3, 4) << endl;

    return 0;
}

