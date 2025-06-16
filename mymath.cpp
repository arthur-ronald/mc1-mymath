#include <iostream>
#include "mymath.hpp"

int main(){
    int n;
    std::cout << "[1] Para funções:\n"
              << "[2] Para Cifra de cesar:\n"
              << "[3] Para MDC\n"
              << "[4] Para identidade de Bézout\n"
              << "[5] RSA Parcial\n"
              << "[6] RSA Completa" << std::endl;
    std::cin >> n;
    if(n == 1){
        int p;
        std::cout << "Escolha a função desejada:\n"
                  << "[1] Piso\n"
                  << "[2] Teto\n"
                  << "[3] Div\n"
                  << "[4] Mod\n"
                  << "[5] PNI" << std::endl;
        std::cin >> p;
        if(p == 1){
            double j;
            std::cout << "Digite o valor a ser calculado: " << std::endl;
            std::cin >> j;
            std::cout << "O piso de " << j << " é " << myfloor(j) << std::endl;
        }
        else if(p == 2){
            double j;
            std::cout << "Digite o valor a ser calculado: " << std::endl;
            std::cin >> j;
            std::cout << "O teto de " << j << " é " << myceil(j) << std::endl;
        }
        else if(p == 3){
            int a, b;
            std::cout << "Digite o dividendo: ";
            std::cin >> a;
            std::cout << "Digite o divisor: ";
            std::cin >> b;
            std::cout << a << " dividido por " << b << " é igual a:\n" << mydiv(a, b) << std::endl;
        }
        else if(p == 4){
            int a, b;
            std::cout << "Digite o primeiro dividendo: ";
            std::cin >> a;
            std::cout << "Digite o divisor: ";
            std::cin >> b;
            std::cout << a << " MOD " << b << " = " << mymod(a, b) << std::endl;
        }
    }
}