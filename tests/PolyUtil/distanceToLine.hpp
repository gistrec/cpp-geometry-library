#include <gtest/gtest.h>
#include <vector>

#include "PolyUtil.hpp"
#include "SphericalUtil.hpp"


TEST(PolyUtil, distanceToLine) {
    LatLng startLine(28.05359, -82.41632);
    LatLng endLine(28.05310, -82.41634);
    LatLng point(28.05342, -82.41594);

    double distance = PolyUtil::distanceToLine(point, startLine, endLine);

    EXPECT_NEAR(37.947946, distance, 1e-6);
}

TEST(PolyUtil, distanceToLine_LessThanDistanceToExtrems) {
    LatLng startLine(28.05359, -82.41632);
    LatLng endLine(28.05310, -82.41634);
    LatLng point(28.05342, -82.41594);

    double distance        = PolyUtil::distanceToLine(point, startLine, endLine);
    double distanceToStart = SphericalUtil::computeDistanceBetween(point, startLine);
    double distanceToEnd   = SphericalUtil::computeDistanceBetween(point, endLine);

    EXPECT_TRUE(distance <= distanceToStart && distance <= distanceToEnd);
}
