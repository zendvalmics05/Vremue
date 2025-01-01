#pragma once

#include <type_traits>

namespace vremue {

  template<typename T>
  concept Numeric = std::is_arithmetic_v<T>;

  template<typename T>
  concept Integral = std::is_integral_v<T>;

  template<typename T>
  concept Floating = std::is_floating_point_v<T>;

  template <Numeric N = int>
  constexpr N abs(const N n) noexcept {
    return n < N(0) ? -n : n;
  }

  template <Numeric N = int>
  constexpr N signum(const N n) noexcept {
    return n / abs(n);
  }

  template <Numeric N = int>
  constexpr N sum(const N n1, const N n2) noexcept {
    return n1 + n2;
  }

  template <Numeric N = int, Numeric... Args>
  constexpr N sum(const N n1, const Args... args) noexcept {
    return n1 + sum(args...);
  }

  template <Numeric N = int>
  constexpr N difference(const N n1, const N n2) noexcept {
    return n1 - n2;
  }

  template <Numeric N = int>
  constexpr N product(const N n1, const N n2) noexcept {
    return n1 * n2;
  }

  template <Numeric N = int, Numeric... Args>
  constexpr N product(const N n1, const Args... args) noexcept {
    return n1 * product(args...);
  }

  template <Numeric N = int>
  constexpr N quotient(const N n1, const N n2) noexcept {
    return n1 / n2;
  }

  template <Integral I1 = int, Integral I2 = I1, Integral I3 = std::common_type_t<I1, I2>>
  constexpr I3 remainder(const I1 i1, const I2 i2) noexcept {
    return i1 % i2;
  }

  template <Floating F = double, Numeric N = F>
  constexpr F reciprocal(const N n) noexcept {
    return 1 / static_cast<F>(n);
  }

  template <Numeric N = int>
  constexpr N fact(const N n) noexcept {
    if (n == N(0)) return 1;
    return n * fact(n - 1);
  }

  template <Numeric N = int>
  constexpr N max(const N n1, const N n2) noexcept {
    return n1 > n2 ? n1 : n2;
  }

  template <Numeric N = int, Numeric... Args>
  constexpr N max(const N n, const Args... args) noexcept {
    return max(n, max(args...));
  }

  template <Numeric N = int>
  constexpr N min(const N n1, const N n2) noexcept {
    return n1 < n2 ? n1 : n2;
  }

  template <Numeric N = int, Numeric... Args>
  constexpr N min(const N n, const Args... args) noexcept {
    return min(n, min(args...));
  }

  template <Integral I = int>
  constexpr I permutation(const I i1, const I i2) noexcept {
    return fact(i1) / fact(i1 - i2);
  }

  template <Integral I = int>
  constexpr I combination(const I i1, const I i2) noexcept {
    return fact(i1) / (fact(i2) * fact(i1 - i2));
  }

  template <Integral I = int>
  constexpr I gcd(const I i1, const I i2) noexcept {
    if (i2 == I(0)) return abs(i1);
    return gcd(abs(i2), abs(i1 % i2));
  }

  template <Integral I = int>
  constexpr I lcm(const I i1, const I i2) noexcept {
    return abs(i1 * i2) / gcd(i1, i2);
  }
}