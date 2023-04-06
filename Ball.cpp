#include <Eigen/Dense>
#include <stdio.h>
#include "Ball.h"

Ball createBall(Eigen::Vector2d pos, Eigen::Vector2d vel) {

	Ball ball(pos, vel);

	return ball;
};