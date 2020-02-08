#include <gtest/gtest.h>

#include "SphericalUtil.hpp"

inline void EXPECT_NEAR_LatLan(LatLng actual, LatLng expected) {
	EXPECT_NEAR(actual.lat, expected.lat, 1e-6);
    // Issue #2
	// Account for the convergence of longitude lines at the poles
	// double cosLat = cos(deg2rad(actual.lat));
	// EXPECT_NEAR(cosLat * actual.lng, cosLat * expected.lng, 1e-6);
}

TEST(SphericalUtil, computeOffset) {
    LatLng up    = { 90.0,    0.0 };
    LatLng down  = {-90.0,    0.0 };
    LatLng front = {  0.0,    0.0 };
    LatLng right = {  0.0,   90.0 };
    LatLng back  = {  0.0, -180.0 };
    LatLng left  = {  0.0,  -90.0 };

	EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffset(front, 0, 0));
	EXPECT_NEAR_LatLan(up,    SphericalUtil::computeOffset(front, M_PI * MathUtil::EARTH_RADIUS / 2,   0));
    EXPECT_NEAR_LatLan(down,  SphericalUtil::computeOffset(front, M_PI * MathUtil::EARTH_RADIUS / 2, 180));
	EXPECT_NEAR_LatLan(left,  SphericalUtil::computeOffset(front, M_PI * MathUtil::EARTH_RADIUS / 2, -90));
    EXPECT_NEAR_LatLan(right, SphericalUtil::computeOffset(front, M_PI * MathUtil::EARTH_RADIUS / 2,  90));
    EXPECT_NEAR_LatLan(back,  SphericalUtil::computeOffset(front, M_PI * MathUtil::EARTH_RADIUS,       0));
    EXPECT_NEAR_LatLan(back,  SphericalUtil::computeOffset(front, M_PI * MathUtil::EARTH_RADIUS,      90));

	// From left
	EXPECT_NEAR_LatLan(left,  SphericalUtil::computeOffset(left, 0, 0));
	EXPECT_NEAR_LatLan(up,    SphericalUtil::computeOffset(left, M_PI * MathUtil::EARTH_RADIUS / 2,   0));
	EXPECT_NEAR_LatLan(down,  SphericalUtil::computeOffset(left, M_PI * MathUtil::EARTH_RADIUS / 2, 180));
	EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffset(left, M_PI * MathUtil::EARTH_RADIUS / 2,  90));
	EXPECT_NEAR_LatLan(back,  SphericalUtil::computeOffset(left, M_PI * MathUtil::EARTH_RADIUS / 2, -90));
	EXPECT_NEAR_LatLan(right, SphericalUtil::computeOffset(left, M_PI * MathUtil::EARTH_RADIUS,       0));
	EXPECT_NEAR_LatLan(right, SphericalUtil::computeOffset(left, M_PI * MathUtil::EARTH_RADIUS,      90));
   
	// NOTE: Heading is undefined at the poles, so we do not test from up/down.
}
