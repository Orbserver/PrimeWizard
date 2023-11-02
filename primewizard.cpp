#include <iostream>
#include <cmath>

bool esPrimo(long long n) {
    if (n <= 1) {
        return false; // Los numeros menores o iguales a 1 no son primos.
    }

    if (n <= 3) {
        return true; // 2 y 3 son primos
    }

    if (n % 2 == 0) {
        return false; // Los numeros pares no son primos
    }

    // Iterar desde 3 hasta la raiz cuadrada de n con pasos de 2 (para verificar numeros impares)
    for (long long i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false; // Si n es divisible por algun numero en ese rango no es primo
        }
    }

    return true; // Si no se encontraron divisores, n es primo
}

int main() {
    long long numero;
    std::cout << "Introduzca un numero impar: ";
    std::cin >> numero;

    if (esPrimo(numero)) {
        std::cout << numero << " es un numero primo" << std::endl;
    } else {
        std::cout << numero << " no es un numero primo" << std::endl;
    }

    return 0;
}