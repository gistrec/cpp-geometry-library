#include <gtest/gtest.h>

#include "SphericalUtil.hpp"


TEST(SphericalUtil, computeDistanceBetween) {
	LatLng up   = { 90.0, 0.0};
	LatLng down = {-90.0, 0.0};

	EXPECT_NEAR(SphericalUtil::computeDistanceBetween(up, down), M_PI * MathUtil::EARTH_RADIUS, 1e-6);
}
