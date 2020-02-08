#include <iostream>
#include <vector>

#include "SphericalUtil.hpp"


int main() {
    LatLng up    = { 90.0,    0.0 };
    LatLng down  = {-90.0,    0.0 };
    LatLng front = {  0.0,    0.0 };
    LatLng right = {  0.0,   90.0 };

    auto angle = SphericalUtil::computeAngleBetween(up, right);
    std::cout << "The angle between up and right is " << rad2deg(angle) << " degrees" << std::endl;

    auto distance = SphericalUtil::computeDistanceBetween(up, down);
    std::cout << "The distance between up and down is " << distance << " meters" << std::endl;

    std::vector<LatLng> points = { front, up, right };

    auto length = SphericalUtil::computeLength(points);
    std::cout << "The length between front, up and right is " << length << " meters" << std::endl;

    auto area = SphericalUtil::computeArea(points);
    std::cout << "The area between front, up and right is " << area << " square meters" << std::endl;

    return 0;
}
