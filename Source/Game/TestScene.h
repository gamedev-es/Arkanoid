#pragma once
#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "../GDCore/Scene.h"

class TestScene : public GDES::Scene
{
public:
	TestScene() : Scene()
	{
		Initialize();
	}

	void Initialize();
private:
	
};
#endif