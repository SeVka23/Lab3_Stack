#include <iostream>
#include "TFormula.h"

using namespace std;
int main()
{
  TStack<char> st;
  st.Put('2');
  st.Put('+');
  st.Put('2');
  st.Put('=');
  st.Put('4');
  for (int i = 0; i < 5; i++)
  {
    cout << st.Pop();
  }
  cout << endl;
  string exprStr;
  cout << "Enter expression: ";
  cin >> exprStr;
  TFormula expr(exprStr);
  cout << expr.GetInfix() << endl;
  cout << expr.GetPostfix() << endl;
  vector<char> operands = expr.GetOperands();
  map<char, double> values;
  double val;
  for (const auto& op : operands)
  {
    cout << "Enter value of " << op << ": ";
    cin >> val;
    values[op] = val;
  }
  cout << expr.Calculate(values) << endl;
  setlocale(LC_ALL, "Russian");
}