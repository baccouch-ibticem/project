#include <iostream>
using namespace std;

int main() { 
    int i=0;
    while( i<10 ) {
        if ( i == 5 ) continue;
        if ( i == 8 ) break;
        cout << ++i;
    }
    cout << "bonjour branche 1" << endl;
    return 0;
}