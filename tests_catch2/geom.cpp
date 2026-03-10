#include "catch2/catch_approx.hpp"
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch_all.hpp>
#include <my_lib/geom.hpp>

TEST_CASE("length", "[geom]") {
  CHECK(euclidian_length({2.0, 0.0}).get() == Catch::Approx(2.0));
  CHECK(euclidian_length({1.0, 1.0}).get() == Catch::Approx(1.41421));
  CHECK(euclidian_length({-1.0, -1.0}).get() == Catch::Approx(1.41421));
}

TEST_CASE("angle_between", "[geom]") {
  CHECK(signed_angle_between({2.0, 0.0}, {0.0, 2.0}).get() == Catch::Approx(90.0));
  CHECK(signed_angle_between({0.0, 2.0}, {2.0, 0.0}).get() == Catch::Approx(-90.0));
  CHECK(signed_angle_between({2.0, 0.0}, {2.0, 2.0}).get() == Catch::Approx(45.0));
}

TEST_CASE("rotate", "[geom]") {
  {
    auto res = rotate_vec({2.0, 0.0}, Angle{90.0});
    CHECK(res[0] == Catch::Approx(0.0).margin(0.001));
    CHECK(res[1] == Catch::Approx(2.0));
  }
  {
    auto res = rotate_vec({0.0, 2.0}, Angle{-90.0});
    CHECK(res[0] == Catch::Approx(2.0));
    CHECK(res[1] == Catch::Approx(0.0).margin(0.001));
  }
}
