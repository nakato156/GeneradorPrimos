# GeneradorPrimos

Esta librería permite generar números primos. Al estar basado en iteradores puedes generar los números primos que deseas en el momento que lo necesites.

## Ejemplos
- Para generar numeros primos a partir de un número dado puede pasar como argumento el valor inicial.
```c++
// si el numero ingresado no es primo se busca al proximo primo
GenPrimos generador(17); 
std::cout << generador.current() << std::endl;
```

- Para generar un numero primo aleatorio grande debe pasar 0 como valor inicial;
```c++
// genera un numero primo aleatorio y alto
GenPrimos generador(0); 
std::cout << generador.current() << std::endl;
```

Si queremos ir al siguiente número rpimo podemos usar el método `next()` o usar los operadores de incrementos.

```c++
// Usando next
std::cout << generador.nex() << std::endl;

// Usando los operadores de incremento
std::cout << ++generador << std::endl;
```