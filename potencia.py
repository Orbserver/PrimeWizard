import sys

sys.set_int_max_str_digits(12000000)

def potencia(x, y):
    print(x**y)

x = int(input("Introduzca un numero: "))
y = int(input("Introduzca la potencia a elevar: "))

potencia(x, y)
