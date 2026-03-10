#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <array>
#include <cmath>
#include <iostream>

//aufgabe01
template<typename T, typename Tag>
class StrongType{
private:
    T value;
public:
    explicit StrongType(T v) : value(v){}
    T get() const {return value;}
};

//struct VectorTag {};
struct AngleTag {};
struct DistanceTag{};

//using Vector = StrongType<std::array<double, 2>, VectorTag>;
using Angle = StrongType<double, AngleTag>;
using Distance = StrongType<double, DistanceTag>;

// API
inline Distance euclidian_length(const std::array<double, 2> &vec);
inline std::array<double, 2> rotate_vec(const std::array<double, 2> &vec, Angle angle_deg);
inline Angle signed_angle_between(const std::array<double, 2> &a, const std::array<double, 2> &b);

// IMPL

inline Distance euclidian_length(const std::array<double, 2> &vec) {
  return Distance (sqrt(vec[0] * vec[0] + vec[1] * vec[1]));
}

inline std::array<double, 2> rotate_vec(const std::array<double, 2> &vec, Angle angle_deg) {
  const auto [x, y] = vec;
  const auto a = angle_deg.get() * M_PI / 180.0;
  return {x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)};
}

inline Angle signed_angle_between(const std::array<double, 2> &a, const std::array<double, 2> &b) {
  double dot = a[0] * b[0] + a[1] * b[1];
  double cross = a[0] * b[1] - a[1] * b[0];
  return Angle (atan2(cross, dot) / M_PI * 180.0);
}