#pragma once
#ifndef GENPRIMOS_H
#define GENPRIMOS_H
#include <iostream>
#include <math.h>

class GeneradorPrimos {
private:
	int n_primo = 2;
public:
	GeneradorPrimos() = default;
	/*@param random: 0 para generar aleatoriamente, cualquier otro valor para setear el primo*/
	GeneradorPrimos(int);

	class Iterator {
	private:
		int* num_primo;
	public:
		using difference_type = std::ptrdiff_t;

		Iterator() : num_primo(nullptr) {}
		Iterator(int*);

		int operator*() const;
		int* operator->() const;
		Iterator operator+(difference_type );
		Iterator operator++();
		Iterator operator++(int);

		bool operator==(const Iterator& otro) const;
		bool operator!=(const Iterator& otro) const;
	};

	int next();

	int current();
	Iterator begin();

	friend std::ostream& operator<<(std::ostream& os, const GeneradorPrimos& gen) {
		os << gen.n_primo;
		return os;
	}
private:
	static int next_(int n);
	static bool esPrimo(int num);
};
#endif