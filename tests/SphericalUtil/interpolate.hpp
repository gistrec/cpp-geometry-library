#include <gtest/gtest.h>

#include "SphericalUtil.hpp"


#define EXPECT_NEAR_LatLan(actual, expected) \
    EXPECT_NEAR(actual.lat, expected.lat, 1e-6);
    // Issue #2
    // Account for the convergence of longitude lines at the poles
    // double cosLat = cos(deg2rad(actual.lat));
    // EXPECT_NEAR(cosLat * actual.lng, cosLat * expected.lng, 1e-6);


TEST(SphericalUtil, interpolate) {
    LatLng up    = { 90.0,    0.0 };
    LatLng down  = {-90.0,    0.0 };
    LatLng front = {  0.0,    0.0 };
    LatLng back  = {  0.0, -180.0 };
    LatLng left  = {  0.0,  -90.0 };

    EXPECT_NEAR_LatLan(up,   SphericalUtil::interpolate(up,     up, 1 / 2.0));
    EXPECT_NEAR_LatLan(down, SphericalUtil::interpolate(down, down, 1 / 2.0));
    EXPECT_NEAR_LatLan(left, SphericalUtil::interpolate(left, left, 1 / 2.0));

    // Between front and up
    EXPECT_NEAR_LatLan(LatLng(1, 0),  SphericalUtil::interpolate(front, up,  1 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(1, 0),  SphericalUtil::interpolate(up, front, 89 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(89, 0), SphericalUtil::interpolate(front, up, 89 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(89, 0), SphericalUtil::interpolate(up, front,  1 / 90.0));

    // Between front and down
    EXPECT_NEAR_LatLan(LatLng(-1, 0), SphericalUtil::interpolate(front, down,   1 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(-1, 0), SphericalUtil::interpolate(down, front,  89 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(-89, 0), SphericalUtil::interpolate(front, down, 89 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(-89, 0), SphericalUtil::interpolate(down, front,  1 / 90.0));

    // Between left and back
    EXPECT_NEAR_LatLan(LatLng(0, -91), SphericalUtil::interpolate(left, back,   1 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(0, -91), SphericalUtil::interpolate(back, left,  89 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(0, -179), SphericalUtil::interpolate(left, back, 89 / 90.0));
    EXPECT_NEAR_LatLan(LatLng(0, -179), SphericalUtil::interpolate(back, left,  1 / 90.0));

    // geodesic crosses pole
    EXPECT_NEAR_LatLan(up,   SphericalUtil::interpolate(LatLng(45, 0),  LatLng(45, 180),  1 / 2.0));
    EXPECT_NEAR_LatLan(down, SphericalUtil::interpolate(LatLng(-45, 0), LatLng(-45, 180), 1 / 2.0));

    // boundary values for fraction, between left and back
    EXPECT_NEAR_LatLan(left, SphericalUtil::interpolate(left, back, 0.0));
    EXPECT_NEAR_LatLan(back, SphericalUtil::interpolate(left, back, 1.0));

    // two nearby points, separated by ~4m, for which the Slerp algorithm is not stable and we
    // have to fall back to linear interpolation.
    LatLng interpolateResult = SphericalUtil::interpolate(LatLng(-37.756891, 175.325262), LatLng(-37.756853, 175.325242), 0.5);
    LatLng goldenResult(-37.756872, 175.325252);

    EXPECT_NEAR(interpolateResult.lat, goldenResult.lat, 2e-5);
}
