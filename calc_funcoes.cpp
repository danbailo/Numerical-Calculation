#include <iostream>
#include <math.h>

using namespace std;

double f(double x){
    return pow(x,3)+x-1000;
}

int main(int argc, char const *argv[]){  

    cout << f(9.96875005960464477539) << endl;
    cout << fabs(f(9)) << endl;

    return 0;
}
