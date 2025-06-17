#pragma Once
#include <string>

double myabs(double a){
    if(a >= 0){
        return a;
    }
    else{
        return a * -1;
    }
}
int myfloor(double a){
    int i = 0;
    if(a >= 0){
        while(i <= a){
            i++;
        }
        return i - 1;
    }
    else{
        while(i > a){
            i--;
        }
        return i;
    }
}

int myceil(double a){
    int i = 0;
    if(a >= 0){
        while(i < a){
            i++;
        }
        return i;
    }
    else{
        while(i >= a){
            i--;
        }
        return i + 1;
    }
}

int mydiv(int a, int b){
    if(b == 0){
        return -1;
    }
    bool negativo = (a < 0) ^ (b < 0);
    int A = myabs(a);
    int B = myabs(b);
    int q = 0;

    while(A >= B){
        A -= B;
        q++;
    }
    if(negativo){
        return -q;
    }
    else{
        return q;
    }
}

int mymod(int a, int b){
    if(b == 0){
        return -1;
    }
    int B = myabs(b);
    int q = mydiv(a, b);
    int r = a - (b * q);
    if(r < 0){
        r +=B;
    }
    return r;
}
int prime(int a){
    int cont =0;
    if(a <= 1){
        return false;
    }
    else{
        for(int i=2; i < a; i++){
            if(mymod(a, i) == 0){
                return false;
            }
        }
        return true;
    }
}

void pnr(int a, int b){
    for(int i = a; i <= b; i++){
        if(prime(i)){
            std::cout << i << " ";
        }
    }
}

std::string cesar(std::string a, int b){
    int chave = mymod(b, 26);
    for(int i=0; i < a.length(); i++){
        if(a[i] >= 65 and a[i] <= 90){
            if((a[i] + chave) > 90){
                a[i] = 64 + mymod(a[i] + chave, 90);
            }
            else{
                a[i] += chave;
            }
        }
        else if(a[i] >= 97 and a[i] <= 122){
            if((a[i] + chave) > 122){
                a[i] = 96 + mymod(a[i] + chave, 122);
            }
            else{
                a[i] += chave;
            }
        }
    }
    return a;
}

int mymdc_sbs(int a, int b){

    int m = mydiv(a, b);
    int n = mymod(a, b);
    std::cout << a << " = " << m << " * " << b << " + " << n << std::endl;
    if(n == 0){
        std::cout << "Resultado: " << b << std::endl;
        return b;
    }
    else{
        return mymdc_sbs(b, n);
    }
}

int mymdc(int a, int b){
    int n = mymod(a, b);
    if(n == 0){
        return b;
    }
    else{
        return mymdc(b, n);
    }
}

int bezout(int a, int b){
    int s = 1;
    int t = mydiv(a, b);
    int result = mymod(a, b);
    if(mymod(a, b) == 0){
        return 0;
    }
    else{
        std::cout << result << " = " << '(' << s << ')' << " * " << a <<  " + "<<'(' << -t << ')' << " * " << b << std::endl;
        return bezout(b, mymod(a, b));
    }
    return 0;
}


