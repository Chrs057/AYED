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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos
// pauta de estilo [83]: tipo retornado en línea anterior al método

// getter que devuelve el valor del atríbuto privado "num_"
int
rational_t::get_num() const {
  return num_;
}


// getter que devuelve el valor del atríbuto privado "den_"
int
rational_t::get_den() const {
  return den_;
}


// setter que puede modificar el valor del atributo "num_", no devuelve nada  
void
rational_t::set_num(const int n) {
  num_ = n;
}


// setter que puede modificar el valor del atributo "den_", no devuelve nada
void
rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}


// método que devuelve el número racional expresado como double
double
rational_t::value() const { 
  return double(get_num()) / get_den();
}

// comparaciones
// función que compara si un número es igual que otro
bool
rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}


// función que compara si un número es mayor que otro
bool
rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}
  

// función que compara si un número es menor que otro
bool
rational_t::is_less(const rational_t& r, const double precision) const {
  return (r.value() - value()) > precision;
}



// operaciones
// función que suma 2 números racionales
rational_t
rational_t::add(const rational_t& r) {
  rational_t suma;
  suma.set_num(get_num() * r.get_den() + get_den() * r.get_num());
  suma.set_den(get_den() * r.get_den());
  return suma;
}


// función que resta 2 números racionales
rational_t
rational_t::substract(const rational_t& r) {
  rational_t resta;
  resta.set_num(get_num() * r.get_den() - get_den() * r.get_num());
  resta.set_den(get_den() * r.get_den());
  return resta;
}


// función que multiplica 2 números racionales
rational_t
rational_t::multiply(const rational_t& r) {
  rational_t multiplicacion;
  multiplicacion.set_num(get_num() * r.get_num());
  multiplicacion.set_den(get_den() * r.get_den());
  return multiplicacion;
}


// función que divide 2 números racionales
rational_t
rational_t::divide(const rational_t& r) {
  rational_t division;
  division.set_num(get_num() * r.get_den());
  division.set_den(get_den() * r.get_num());
  return division;
}

// MODIFIACIÓN
// función que comprueba si un número racional es entero
void
rational_t::entero() {
  if (get_num() % get_den() == 0) {
    cout << "Es un número entero.\n";
  } else {
    cout << "No es entero.\n";
  }
}

// E/S
// imprime un racional en el flujo de salida
void
rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

// lee un racional desde el flujo de entrada
void
rational_t::read(istream& is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}