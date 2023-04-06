#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <Eigen/Dense>
#include <vector>
#include "Ball.h"

using namespace std;

struct Object {
	Object();
	vector<Ball> balls;
};

Object createOblect();

#endif