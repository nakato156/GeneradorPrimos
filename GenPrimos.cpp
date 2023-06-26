#include "GenPrimos.h"

GeneradorPrimos::Iterator::Iterator(int* num) { num_primo = num; }
int GeneradorPrimos::Iterator::operator*() const { return *num_primo; }
int* GeneradorPrimos::Iterator::operator->() const { return num_primo; }
GeneradorPrimos::Iterator GeneradorPrimos::Iterator::operator+(difference_type n) {
    int* nuevo_primo = num_primo;
    for (int i = 0; i < n; i++) {
        nuevo_primo = new int(next_(*nuevo_primo));
    }
    return Iterator(nuevo_primo);
}
GeneradorPrimos::Iterator GeneradorPrimos::Iterator::operator++() {
    num_primo = new int(next_(*num_primo));
    return *this;
}
GeneradorPrimos::Iterator GeneradorPrimos::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}
bool GeneradorPrimos::Iterator::operator==(const Iterator& otro) const {
    return num_primo == otro.num_primo;
}
bool GeneradorPrimos::Iterator::operator!=(const Iterator& otro) const {
    return !(*this == otro);
}

GeneradorPrimos::GeneradorPrimos(int random) {
    if (random == 0) {
        n_primo = next_(2 + rand() % 1000000000);
    }
    else if (esPrimo(random)) n_primo = random;
    else { n_primo = next_(random); }

}

int GeneradorPrimos::next(){
    n_primo = next_(n_primo);
    return n_primo;
}

int GeneradorPrimos::current(){ return n_primo; }

GeneradorPrimos::Iterator GeneradorPrimos::begin(){ return Iterator(new int(n_primo)); }

int GeneradorPrimos::next_(int n){
    while (true) {
        if (esPrimo(++n)) return n;
    }
}

bool GeneradorPrimos::esPrimo(int num){
    if (num <= 1) return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}