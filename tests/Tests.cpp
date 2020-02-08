/** Including all tests */
#include "SphericalUtil/interpolate.hpp"
#include "SphericalUtil/computeAngleBetween.hpp"
#include "SphericalUtil/computeSignedArea.hpp"
#include "SphericalUtil/computeArea.hpp"
#include "SphericalUtil/computeLength.hpp"
#include "SphericalUtil/computeOffset.hpp"
#include "SphericalUtil/computeHeading.hpp"
#include "SphericalUtil/computeOffsetOrigin.hpp"
#include "SphericalUtil/computeDistanceBetween.hpp"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
