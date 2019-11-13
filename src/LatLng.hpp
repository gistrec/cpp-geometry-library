//******************************************************************************
// Copyright 2013 Google Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// This software and the related documents are provided  as is,  with no express
// or implied  warranties,  other than  those that are  expressly stated  in the
// License.
//******************************************************************************

#ifndef GEOMETRY_LIBRARY_LATLNG
#define GEOMETRY_LIBRARY_LATLNG

struct LatLng {
	double lat;
	double lng;

	LatLng(double lat, double lng)
		: lat(lat), lng(lng) {};

	bool operator==(const LatLng& other) {
		return lat == other.lat && lng == other.lng;
	}
};

#endif // GEOMETRY_LIBRARY_LATLNG
