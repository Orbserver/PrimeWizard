#include <iostream>
#include <gmpxx.h>
#include <unistd.h>

void barraProgreso(int progreso) {
    int anchura = 100;
    int longitud = (progreso * anchura) / 100;
    std::cout << "[";
    for (int i = 0; i < anchura; i++) {
        if (i < longitud) {
            std::cout << "=";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << progreso << "%" << " \r";
    std::cout.flush();
}

bool esPrimo(const mpz_class& n) {
    if (n <= 1) {
        return false; // Los numeros menores o iguales a 1 no son primos.
    }

    if (n <= 3) {
        return true; // 2 y 3 son primos
    }

    if (n % 2 == 0) {
        return false; // Los numeros pares no son primos
    }

    mpz_t raiz;
    mpz_init(raiz);
    mpz_sqrt(raiz, n.get_mpz_t());
    // Iterar desde 3 hasta la raiz cuadrada de n con pasos de 2 (para verificar numeros impares)
    for (mpz_class i = 3; i <= mpz_class(raiz); i += 2) {
        if (n % i == 0) {
            mpz_clear(raiz);
            return false; // Si n es divisible por algun numero en ese rango no es primo
        }
    }

    mpz_clear(raiz);
    return true; // Si no se encontraron divisores, n es primo
}

int main() {
    mpz_class numero;
    std::cout << "Introduzca un numero impar: ";
    std::cin >> numero;

    std::cout << "Calculando...";

    for (int i = 0; i <= 100; i++) {
        usleep(100000);
        barraProgreso(i);
    }
    std::cout << std::endl;

    if (esPrimo(numero)) {
        std::cout << numero << " es un numero primo" << std::endl;
    } else {
        std::cout << numero << " no es un numero primo" << std::endl;
    }

    return 0;
}