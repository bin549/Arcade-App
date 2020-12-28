#ifndef GAMES_BREAKOUT_H_
#define GAMES_BREAKOUT_H_

#include <vector>
#include "Game.h"

enum BreakOutGameState
{
	IN_PLAY = 0,
	IN_SERVE,
	IN_GAME_OVER
};


class BreakOut : public Game
{
public:
	virtual void Init(GameController& controller) override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& screen) override;
	virtual const std::string& GetName() const override;

private:
	const int NUM_LIVES = 3;
};

#endif