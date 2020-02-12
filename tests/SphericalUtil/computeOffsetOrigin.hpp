#include <gtest/gtest.h>

#include "SphericalUtil.hpp"


#define EXPECT_NEAR_LatLan(actual, expected) \
    EXPECT_NEAR(actual.lat, expected.lat, 1e-6);
    // Issue #2
    // Account for the convergence of longitude lines at the poles
    // double cosLat = cos(deg2rad(actual.lat));
    // EXPECT_NEAR(cosLat * actual.lng, cosLat * expected.lng, 1e-6);

TEST(SphericalUtil, computeOffsetOrigin) {
    LatLng front = {  0.0,    0.0 };

    EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffsetOrigin(front, 0, 0));

    EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffsetOrigin(LatLng(  0,  45), M_PI * MathUtil::EARTH_RADIUS / 4,  90));
    EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffsetOrigin(LatLng(  0, -45), M_PI * MathUtil::EARTH_RADIUS / 4, -90));
    EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffsetOrigin(LatLng( 45,   0), M_PI * MathUtil::EARTH_RADIUS / 4,   0));
    EXPECT_NEAR_LatLan(front, SphericalUtil::computeOffsetOrigin(LatLng(-45,   0), M_PI * MathUtil::EARTH_RADIUS / 4, 180));

    // Issue #3
    // Situations with no solution, should return null.
    //
    // First 'over' the pole.
    // EXPECT_NULL(SphericalUtil::computeOffsetOrigin(LatLng(80, 0), M_PI * MathUtil::EARTH_RADIUS / 4, 180));
    
    // Second a distance that doesn't fit on the earth.
    // EXPECT_NULL(SphericalUtil::computeOffsetOrigin(LatLng(80, 0), M_PI * MathUtil::EARTH_RADIUS / 4, 90));
}
