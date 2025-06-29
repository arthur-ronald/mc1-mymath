#pragma Once
#include <string>
#include <vector>

struct Result {
    long long mdc, s, t;

};

double myabs(double a){
    if(a >= 0){
        return a;
    }
    else{
        return a * -1;
    }
}
long long myfloor(double a){
    long long i = 0;
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

long long myceil(double a){
    long long i = 0;
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

long long mydiv(long long a, long long b){
    if(b == 0){
        return -1;
    }
    bool negativo = (a < 0) ^ (b < 0);
    long long A = myabs(a);
    long long B = myabs(b);
    long long q = 0;

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

long long mymod(long long a, long long b){
    if(b == 0){
        return -1;
    }
    long long B = myabs(b);
    long long q = mydiv(a, b);
    long long r = a - (b * q);
    if(r < 0){
        r +=B;
    }
    return r;
}
long long prime(long long a){
    long long cont =0;
    if(a <= 1){
        return false;
    }
    else{
        for(long long i=2; i < a; i++){
            if(mymod(a, i) == 0){
                return false;
            }
        }
        return true;
    }
}

void pnr(long long a, long long b){
    for(long long i = a; i <= b; i++){
        if(prime(i)){
            std::cout << i << " ";
        }
    }
}

std::string cesar(std::string a, long long b){
    long long chave = mymod(b, 26);
    for(long long i=0; i < a.length(); i++){
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

long long mymdc_sbs(long long a, long long b){

    long long m = mydiv(a, b);
    long long n = mymod(a, b);
    std::cout << a << " = " << m << " * " << b << " + " << n << std::endl;
    if(n == 0){
        std::cout << "Resultado: " << b << std::endl;
        return b;
    }
    else{
        return mymdc_sbs(b, n);
    }
}

long long mymdc(long long a, long long b){
    long long n = mymod(a, b);
    if(n == 0){
        return b;
    }
    else{
        return mymdc(b, n);
    }
}

Result bezout(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    Result res = bezout(b, a % b);

    int mdc = res.mdc;
    int s1 = res.s;
    int t1 = res.t;

    int s = t1;
    int t = s1 - (a / b) * t1;

    return {mdc, s, t};
}

long long bezout_sbs(long long a, long long b){
    long long s = 1;
    long long t = mydiv(a, b);
    long long result = mymod(a, b);
    if(mymod(a, b) == 0){
        return 0;
    }
    else{
        std::cout << result << " = " << '(' << s << ')' << " * " << a <<  " + "<<'(' << -t << ')' << " * " << b << std::endl;
        return bezout_sbs(b, mymod(a, b));
    }
    return 0;
}

long long tot_pq(long long a, long long b){
    return (a - 1)*(b - 1);
}

long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

void rsa_parcial(long long a, long long b, std::string c){
    std::string letras = "abcdefghkijlmnopqrstuvwxyz ";
    std::vector<long long> criptografado;
    std::string descriptografado;
    long long n = a * b;
    long long r = tot_pq(a, b);
    long long e;
    for(int i = 0; i < c.size(); i++){
            c[i] = letras.find(c[i]);
    }
    for(long long i=2; i < r; i++){
        if(mymdc(i, r) == 1){
            e = i;
            break;
        }
    }
    Result res = bezout(e, r);
    long long d = mymod(mymod(res.s, r + r), r); 
    std::cout << "n: "<< n << " r: " << r << " e: " << e << " d: " << d << std::endl;
    for(long long i = 0; i < c.size(); i++){
        if(c[i] == ' '){
            descriptografado.push_back(26);
            criptografado.push_back(26);
        }
        else{
            int crip = mod_pow(c[i], e, n);
            int descrip = mod_pow(crip, d, n);
            criptografado.push_back(crip);
            descriptografado.push_back(mymod(descrip, 27));
        }
    }
    for(auto m : criptografado){
        std::cout << m << " ";
    }
    std::cout << std::endl;
    for(auto m : descriptografado){
        std::cout << letras[m];
    }
    std::cout << std::endl;
}
void rsa_completa(long long a, long long b, std::string c){
    std::vector<long long> criptografado;
    std::string descriptografado;
    long long n = a * b;
    long long r = tot_pq(a, b);
    long long e;
    for(long long i=2; i < r; i++){
        if(mymdc(i, r) == 1){
            e = i;
            break;
        }
    }
    Result res = bezout(e, r);
    long long d = mymod(mymod(res.s, r + r), r); 
    std::cout << "n: "<< n << " r: " << r << " e: " << e << " d: " << d << std::endl;
    for(long long i = 0; i < c.size(); i++){
        int crip = mod_pow(c[i], e, n);
        int descrip = mod_pow(crip, d, n);
        criptografado.push_back(crip);
        descriptografado += descrip;
        
    }
    for(auto m : criptografado){
        std::cout << m << " ";
    }

    std::cout << std::endl << descriptografado << std::endl;
}