#ifndef STAGEDATA_HPP
#define STAGEDATA_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

class ObjectBase;

class StageData {
private:
  // TileMap's format:
  // 5x5, 0.Wall, 1.Space, 2.Start, 3.Goal, 4.Locked Door
  // 5~8.Medium Case(Left, Down, Right, Up), 9~12.Large Case(Left, Down, Right,
  // Up) 13~16.Medium Key Case(Left, Down, Right, Up), 17~20.Large Key
  // Case(Left, Down, Right, Up)
  class PlayerObject *player;
  std::vector<int> tileMap;
  std::vector<ObjectBase *> objects;
  bool isDoorLocked = true;
  int goalPosX, goalPosY;
  SDL_Renderer *renderer;
  std::vector<ObjectBase *> stack;
  Mix_Chunk *lightSE, *heavySE, *goalSE;
  int stackX = 0, stackY = 0;
  bool flag = false;

  void findObjectsAt(std::vector<ObjectBase *> *, int, int);
  void moveLeft();
  void moveDown();
  void moveRight();
  void moveUp();

public:
  StageData(std::vector<int> &&);
  bool mainLoop(SDL_Window *);
};

#endif /* end of include guard: STAGEDATA_HPP */
