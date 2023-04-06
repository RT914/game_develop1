#include <Eigen/Dense>
#include <stdio.h>
#include <vector>
#include "Ball.h"
#include "Object.h"

using namespace std;

int ball_num = 100;

Object::Object() {};

Object createOblect() {

	Object object;

	// ƒ{[ƒ‹‚Ì¶¬

	for (int i = 0; i < ball_num; i++) {

		Eigen::Vector2d pos{10, 10};


		// —”‚Ì¶¬
		double random_velocity_x = rand() % 40 - 20; // -20`20
		double random_velocity_y = rand() % 40 - 20; // -20`20

		Eigen::Vector2d vel{ random_velocity_x, random_velocity_y };


		Ball ball = createBall(pos, vel);
		object.balls.emplace_back(ball);
	}
	
	
	return object;
}