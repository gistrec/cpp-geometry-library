#ifndef GEOMETRY_LIBRARY_LATLNG
#define GEOMETRY_LIBRARY_LATLNG

struct LatLng {
	double lat;
	double lng;

	LatLng(double lat, double lng)
		: lat(lat), lng(lng) {};
};

#endif // GEOMETRY_LIBRARY_LATLNG
