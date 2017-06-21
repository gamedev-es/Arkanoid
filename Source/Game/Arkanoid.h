#pragma once

#include "../GDCore/GDCore.h"

constexpr unsigned SCREEN_WIDTH = 800;
constexpr unsigned SCREEN_HEIGHT = 600;

class Arkanoid : public GDES::GDCore {
  public:
    Arkanoid();

  public:
    enum SCENES { TEST = 0 };
};
