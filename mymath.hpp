#pragma Once

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


