#include <stdio.h>
#include <cmath>

using namespace std;

double f(double x){
    return 2*x-sin(x)+4;
}

double flinha(double x){
    return 2-cos(x);
}

int main(int argc, char const *argv[]){

    double x,e;
    int it=1;

    x = -2.0;
    e = 0.0001;

    while( (fabs(f(x)) > e) ){
        x += -(f(x)/flinha(x));
        printf("%i %lf %lf\n",it,x,f(x));
        it++;
    }

    return 0;
}