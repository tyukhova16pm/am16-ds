#pragma once

#include "lib.hpp"
#include <new>
#include <iostream>

using namespace std;

void InfixToPostfix(char *s, Stack &quene) {
  Stack buf;
  Lexema lexBuf;
  int count=0;
  int i=0;
  int flag=0;
  int action=0; // счетчик ценности последнего лежащего в стеке действия
  int n=0;
  int *z; // счетчик действий в n-ной скобке
  z = new int[n];
  while (s[i] != '\0') {
    if (s[i] == '1' || s[i] == '2'
        || s[i] == '3' || s[i] == '4'
        || s[i] == '5' || s[i] == '6'
        || s[i] == '7' || s[i] == '8'
        || s[i] == '9') {
          count = s[i] - '0';
          while (s[i+1] == '1' || s[i+1] == '2'
              || s[i+1] == '3' || s[i+1] == '4'
              || s[i+1] == '5' || s[i+1] == '6'
              || s[i+1] == '7' || s[i+1] == '8'
              || s[i+1] == '9' || s[i+1] == '0'){
                count = count*10 + (s[i] - '0');
                i++;
              }
          lexBuf.get(count);
          count = 0;
          quene.get(lexBuf);
          i++;
        } else if (s[i] == '(' && buf.isEmpty()) {
              flag+=20;
              i++;
              n++;
              z = new int[n];
              z[n] = 0;
          } else if (s[i] == '('  && !buf.isEmpty()) {
                while (!buf.isEmpty()){
                  quene.get(buf.push());
                  }
                flag+=20;
                i++;
                n++;
                z = new int[n];
                z[n]= 0;
            } else if (s[i] == ')') {
                flag-=20;
                while (!buf.isEmpty()){
                  quene.get(buf.push());
                  }
                i++;
                n--;
            } else if (s[i] == '+' || s[i] == '-') {
                if (action >= (1+flag)) {
                  while (z[n]!=0) {
                    quene.get(buf.push());
                    z[n]--;
                  }
                action = (1+flag);
                lexBuf.get(s[i]);
                buf.get(lexBuf);
                }

            } else if (s[i] == '/' || s[i] == '*') {
                if (action >= (2+flag)) {
                  while (z[n]!=0) {
                    quene.get(buf.push());
                    z[n]--;
                  }
                action = (2+flag);
                lexBuf.get(s[i]);
                buf.get(lexBuf);
                }
            } else if (s[i] == '^') {
                if (action >= (3+flag)) {
                  while (z[n]!=0) {
                    quene.get(buf.push());
                    z[n]--;
                  }
                action = (3+flag);
                lexBuf.get(s[i]);
                buf.get(lexBuf);
                }
            }
    }
  delete[] z;
}

int poww (int a, int b) {
  int result=0;
  result = a;
  for (int i=1; i<b; i++) {
    result=result*a;
  }
  return result;
}

int Operation (int &result, Lexema l, Stack &s) {
  Lexema lex;
  int oper1=0;
  int oper2=0;
  if (l.chDrop() == '+') {
    lex=s.push();
    if (!lex.intD()) {
          Operation (oper1, lex, s);
        } else {
          oper1+=lex.iDrop();
          if (!lex.intD()) {
                Operation (oper2, lex, s);
              } else {
                oper2+=lex.iDrop();
              }
        }
        result = oper1+oper2;
  } else if (l.chDrop() == '-') {
    lex=s.push();
    if (!lex.intD()) {
          Operation (oper1, lex, s);
        } else {
          oper1+=lex.iDrop();
          if (!lex.intD()) {
                Operation (oper2, lex, s);
              } else {
                oper2+=lex.iDrop();
              }
        }
      result = oper2 - oper1;
  } else if (l.chDrop() == '*') {
    lex=s.push();
    if (!lex.intD()) {
          Operation (oper1, lex, s);
        } else {
          oper1+=lex.iDrop();
          if (!lex.intD()) {
                Operation (oper2, lex, s);
              } else {
                oper2+=lex.iDrop();
              }
        }
        result = oper1*oper2;
  } else if (l.chDrop() == '/') {
    lex=s.push();
    if (!lex.intD()) {
          Operation (oper1, lex, s);
        } else {
          oper1+=lex.iDrop();
          if (!lex.intD()) {
                Operation (oper2, lex, s);
              } else {
                oper2+=lex.iDrop();
              }
        }
        result = oper2/oper1;
  } else if (l.chDrop() == '^') {
    lex=s.push();
    if (!lex.intD()) {
          Operation (oper1, lex, s);
        } else {
          oper1+=lex.iDrop();
          if (!lex.intD()) {
                Operation (oper2, lex, s);
              } else {
                oper2+=lex.iDrop();
              }
        }
        result = poww(oper2, oper1);
  }
  return result;
}

int Calculation(Stack &s) {
  int result;
  Lexema lexBuf;
  while (!s.isEmpty()) {
      lexBuf=s.push();
      if (!lexBuf.intD()) {
            Operation(result, lexBuf, s);
          } else
          cout << "ERROR";
  }
  return result;
}
