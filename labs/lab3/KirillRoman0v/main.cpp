#pragma once

#include "finish.cpp"

using namespace std;

int main () {

  char *in;
  Stack q;
  int result;
  cout<<"VVedite virazhenie, razresheno ispolzovat:\n";
  cout<<"+, -, *, /, ^, (, )\n";

  in = new char[64];
  cin>>in;

  InfixToPostfix(in, q);

  result = Calculation(q);

  cout<<result;

  return 0;
}
