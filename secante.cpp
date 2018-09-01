#include <stdio.h>
#include <cmath>

using namespace std;

double f(double x){
    return pow(x,2)+x-6;
}

double secante(double x0, double x1){
    return ((x1*f(x0)) - (x0*f(x1)) )/(f(x0)-f(x1));
}

int main(int argc, char const *argv[]){

    double x0,x1,e,x;
    int it=1;

    x0 = 1.5;
    x1 = 1.7;
    e = 0.0001;

    while(fabs(f(x)) > e){

        x = secante(x0,x1);

        x0 = x1;
        x1 = x;

        printf("%i %lf\n",it,x);
        it++;

    }
    
    return 0;
}
