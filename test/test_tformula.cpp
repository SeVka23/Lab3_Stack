#include "gtest.h"
#include "TFormula.h"

TEST(TFormula, can_create_formula_without_prohibited_symbols)
{
  string s1 = "a+b";
  ASSERT_NO_THROW(TFormula f1(s1));
}

TEST(TFormula, cant_create_formula_with_prohibited_symbols)
{
  string s1 = "a!b";
  ASSERT_ANY_THROW(TFormula f1(s1));
}

TEST(TFormula, formula_getinfix_returns_correct)
{
  string s1("a+b");
  TFormula f1(s1);
  EXPECT_EQ(f1.GetInfix(), s1);
}

TEST(TFormula, formula_getpostfix_returns_correct)
{
  string s1("a/b");
  string s2("ab/");
  TFormula f1(s1);
  EXPECT_EQ(f1.GetPostfix(), s2);
}

TEST(TFormula, formula_getoperands_returns_correct)
{
  string s1("a-b");
  TFormula f1(s1);
  vector<char> op;
  op.push_back('a');
  op.push_back('b');
  EXPECT_EQ(f1.GetOperands(), op);
}

TEST(TFormula, formula_calculate_returns_correct)
{
  string s1("a*b");
  TFormula f1(s1);
  map<char, double> op = { {'a', 1}, {'b', 2} };
  EXPECT_EQ(f1.Calculate(op), 2);
}

TEST(TFormula, formula_calculate_throw_error_with_divide_by_zero)
{
  string s1("a/b");
  TFormula f1(s1);
  map<char, double> op = { {'a', 1}, {'b', 0} };
  ASSERT_ANY_THROW(f1.Calculate(op));
}