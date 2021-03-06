//
// GameOver.cpp
//

// Engine includes.
#include "EventStep.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

// Game includes.
#include "GameOver.h"
#include "GameStart.h"

// Define registerInterest in case engine does not.
static void registerInterest(std::string s) {};

GameOver::GameOver() {

  setType("GameOver");

  // Link to "message" sprite.
  df::Sprite *p_temp_sprite = RM.getSprite("gameover");
  if (!p_temp_sprite)
    LM.writeLog("GameOver::GameOver(): Warning! Sprite 'gameover' not found");
  else {
    setSprite(p_temp_sprite);
    setSpriteSlowdown(15);		  
    time_to_live = p_temp_sprite->getFrameCount() * 15;
  }

  // Put in center of window.
  setLocation(df::CENTER_CENTER);
  
  // Register for step event.
  registerInterest(df::STEP_EVENT);

  // Play "game over" sound.
  df::Sound *p_sound = RM.getSound("game over");
  p_sound->play();
}

// When done, game over so shut down.
GameOver::~GameOver() {
  WM.markForDelete(this);
  GM.setGameOver();
}

// Handle event.
// Return 0 if ignored, else 1.
int GameOver::eventHandler(const df::Event *p_e) {

  if (p_e->getType() == df::STEP_EVENT) {
    step();
    return 1;
  }

  // If get here, have ignored this event.
  return 0;
}

// Count down to end of message.
void GameOver::step() {
  time_to_live--;
  if (time_to_live <= 0) { 
    WM.markForDelete(this);
  }
}

// Override default draw so as not to display "value".
void GameOver::draw() {
  df::Object::draw();
}
