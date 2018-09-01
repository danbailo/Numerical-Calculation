#include <stdio.h>
#include <cmath>

using namespace std;

double f(double x){
    return pow(x,3)+x-1000;
}

int main(int argc, char const *argv[]){

    double a,b,e,x;

    
    a = 8.0;
    b = 10.0;
    e = 0.01;
    int k = 0;
    if((f(a)*f(b)) <= 0){
        while(fabs(b-a) > e){
            x = (a+b)/2.0;
            if((f(a)*f(b)) <= 0){
                a = x;
                // cout << a << "\n";
            }
            else{
                b = x;
                // cout << "b: " << b << "\n";
            }
            k++;
        }
        printf("A raiz do intervalo é %e\n", x);
        printf("Iterações: %d\n",k);
        return 0;
    }
    printf("Não há raizes no intervalo dado\n");
    
    return 0;
}
