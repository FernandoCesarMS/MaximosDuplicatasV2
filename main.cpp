#include <vector>
#include <iostream>
#include <map>

#include "Algoritmos.hpp"

using namespace std;
template <class T>
void read_input(std::vector<T> &vec)
{
  T val;
  while (std::cin >> val)
  {
    vec.push_back(val);
  }
}

template <class T>
void print_input(std::vector<T> &vec)
{
  T x = vec[vec.size() - 1];
  vec.pop_back();
  for (T &c : vec)
  {
    cout << c << ", ";
  }
  cout << x << "\n";
}

template <class T>
T get_max(std::vector<T> &vec)
{
  if (vec.empty())
  {
    std::cout << "Erro: vetor vazio.\n";
  }
  T x = vec[0];
  for (T &c : vec)
  {
    if (x < c)
    {
      x = c;
    }
  }
  return x;
}

template <class T>
unsigned int count_duplicates(std::vector<T> &vec)
{
  int duplicates = 0, size = vec.size();

  for (int c = 0; c < size; c++)
  {
    bool notFirst = false;
    for (int c3 = c; c3 >= 0; c3--)
    {
      if (c3 != c && vec[c3] == vec[c])
      {
        notFirst = true;
      }
    }
    if (notFirst == true)
    {
      continue;
    }
    for (int c2 = c; c2 < size; c2++)
    {
      if (c2 != c && vec[c2] == vec[c])
      {
        duplicates++;
      }
    }
  }
  return duplicates;
}

template <class T>
void test_print_input()
{
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T>
void test_get_max()
{
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T>
void test_count_dups()
{
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main()
{
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste)
  {
  case 0:
    test_print_input<std::string>();
    break;
  case 1:
    test_print_input<int>();
    break;
  case 2:
    test_get_max<double>();
    break;
  case 3:
    test_get_max<char>();
    break;
  case 4:
    test_count_dups<int>();
    break;
  case 5:
    test_count_dups<std::string>();
    break;
  default:
    std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}