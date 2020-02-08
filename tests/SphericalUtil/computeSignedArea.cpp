#include <gtest/gtest.h>

#include "SphericalUtil.hpp"


TEST(SphericalUtil, computeSignedArea) {
    LatLng up    = { 90.0,    0.0 };
    LatLng down  = {-90.0,    0.0 };
    LatLng front = {  0.0,    0.0 };
    LatLng right = {  0.0,   90.0 };

    std::vector<LatLng> path         = { right,   up, front, down, right };
    std::vector<LatLng> pathReversed = { right, down, front,   up, right };
    
    EXPECT_NEAR(-SphericalUtil::computeSignedArea(path), SphericalUtil::computeSignedArea(pathReversed), 0);
}
