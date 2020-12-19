#pragma once
#include "gcd.hpp"

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}
