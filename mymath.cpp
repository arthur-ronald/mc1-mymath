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
                  << "[5] Números primos no intervalo" << std::endl;
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
        else if(p == 5){
            int a, b;
            std::cout << "Digite o intervalo de procura dos numeros primos: " << std::endl;
            std::cin >> a >> b;
            pnr(a, b); 
            std::cout << std::endl;
        }
    }
    else if(n == 2){
        std::cin.ignore();
        std::string a;
        int b;
        std::cout << "Digite a frase que será cifrada: ";
        getline(std::cin, a);
        std::cout << "Digite a chave da crifra: ";
        std::cin >> b;
        std::cout << "Frase cifrada: " << cesar(a, b) << std::endl;
    }
    else if(n == 3){
        int a, b;
        std::cout << "Digite os numeros para calcular o mdc: ";
        std::cin >> a >> b;
        std::cout << "O mdc entre " << a << " e " << b << " é igual a: " << std::endl;
        mymdc_sbs(a, b);
    }
    else if(n == 4){
        int a, b;
        std::cout << "Digite os numeros para identidade de bezout: ";
        std::cin >> a >> b;
        std::cout << "o resultado é: " << std::endl;
        bezout(a, b);
    }
}