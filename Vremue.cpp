#include <cstdio>

#include "vremue.hpp"

int main()
{
  constexpr auto a = vremue::lcm(21,35);
  constexpr auto b = -1 * a;
  printf("%d", b);

  return 0;
}
