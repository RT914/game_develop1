#ifndef _BALL_H_
#define _BALL_H_

#include <Eigen/Dense>

struct Ball {
	Ball(Eigen::Vector2d& pos, Eigen::Vector2d& vel) : position(pos), velocity(vel) {};

	Eigen::Vector2d position;
	Eigen::Vector2d velocity;
	int size = 5;
};

Ball createBall(Eigen::Vector2d pos, Eigen::Vector2d vel);
#endif
