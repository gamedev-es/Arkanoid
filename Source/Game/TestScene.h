#pragma once
#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "../GDCore/Scene.h"
#include "Paddle.h"
#include "Ball.h"
#include "ButtonState.h"
#include "Brick.h"
#include "Light.h"

class TestScene : public GDES::Scene
{
public:
	TestScene();
	~TestScene();

	void Initialize();

private:
	void CreateBricks();

private:
	std::vector<Brick*> brickList;

};
#endif
