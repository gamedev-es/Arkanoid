#pragma once
#ifndef ARKANOID_H
#define ARKANOID_H
#include "../GDCore/GDCore.h"

class Arkanoid : public GDES::GDCore
{
public:
	Arkanoid();
public:
	enum SCENES { TEST = 0 };
	static const unsigned int SCREEN_WIDTH = 800;
	static const unsigned int SCREEN_HEIGHT = 600;
};

#endif // ARKANOID_H
