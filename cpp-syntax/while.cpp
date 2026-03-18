#include <iostream>

using namespace std;

int main(){
    int i = 1;
    int an = 1;
    int an_1 = 1;
    int an_2 = 0;
    while(i < 29){
        i++;
        an_2 = an_1;
        an_1 = an;
        an = an_1 + an_2;
    }
    cout << an << endl;
    return 0;
}