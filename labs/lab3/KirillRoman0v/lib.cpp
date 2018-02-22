#pragma once

#include "lib.hpp"
#include <iostream>

using namespace std;

Lexema::Lexema () {
  flag = 1;
  x.integ = 0;
  x.ch = '0';
}

Lexema::Lexema (const Lexema &l) {
  if (flag == 1) {
    x.integ = l.x.integ;
  } else if (flag == 2) {
    x.ch = l.x.ch;
  }
  flag = l.flag;

}

int Lexema::intD() {
  if (flag == 1) {
    return 1;
  } else if (flag == 2) {
    return 0;
  } else return 2;
}

int Lexema::iDrop() {
  return x.integ;
}

char Lexema::chDrop() {
  return x.ch;
}

void Lexema::get (int i) {
  x.integ = i;
  flag = 1;
}

void Lexema::get (char charity) {
  x.ch = charity;
  flag = 2;
}

Stack::Stack() {
  size = 0;

}

int Stack::isEmpty() {
  if (size == 0) {
    return 1;
  } else {
    return 0;
  }
}

Lexema Stack::push() {
  Lexema ch = c[size];
  size--;
  return ch;
}

void Stack::get(Lexema ch) {
  size++;
  c = new Lexema[size];
  c[size] = ch;
}

Stack::~Stack() {
  delete[] c;
}
