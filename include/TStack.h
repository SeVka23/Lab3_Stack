#ifndef __TStack_H__
#define __TStack_H__

#include <iostream>

using namespace std;

const int maxMemsize = 25;

template <class T>
class TStack
{
protected:
  T* pMem;
  int memSize;
  int dataCount;
  int top;
public:
  TStack(int n = maxMemsize);
  ~TStack();
  int IsEmpty() const;
  int IsFull() const;
  void Put(const T& v);
  virtual T Pop();
};
#endif

template<class T>
inline TStack<T>::TStack(int n = maxMemsize)
{
  dataCount = 0;
  if (n == 0)
    n = maxMemsize;
  memSize = n;
  pMem = new T[memSize];
  top = -1;
}

template<class T>
inline TStack<T>::~TStack()
{
  memSize = 0;
  dataCount = 0;
  top = 0;
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = nullptr;
  }
}

template<class T>
inline int TStack<T>::IsEmpty() const
{
  return dataCount == 0;
}

template<class T>
inline int TStack<T>::IsFull() const
{
  return dataCount == memSize;
}

template<class T>
inline void TStack<T>::Put(const T& v)
{
  if (IsFull()) throw "error";
  pMem[++top] = v;
  dataCount++;
}

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty()) throw "error";
  dataCount--;
  return pMem[top--];
}
