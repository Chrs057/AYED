// AUTOR: Christian González Martín
// FECHA: 16/02/2026
// EMAIL: alu0101631981@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1);   //constructor con parametros
  ~rational_t() {}  //destructor
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const;   //getter para obtener el atributo num_
  int get_den() const;   //getter para obtener el atributo den_
  
  // setters
  void set_num(const int);  //setter que puede modificar el atributo num_
  void set_den(const int);  //setter que puede modificar el atributo den_

  double value(void) const;  //metodo que obtiene el valor decimal del número racional

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);

  // MODIFICACIÓN
  void entero();

  // E/S
  void write(ostream& = cout) const;   //metodo que imprime en pantalla el numero racional
  void read(istream& = cin);           //metodo que lee un numero racional desde el teclado
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;    //atributos privados, numerador y denominador de la fracción, respectivamente
};
