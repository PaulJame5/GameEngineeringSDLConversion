#include <Events.h>

#include <ClimbPausePlayerState.h>

#include <ClimbDownPlayerState.h>
#include <ClimbUpPlayerState.h>
#include <AccendLadderPlayerState.h>
#include <DecendLadderPlayerState.h>


PlayerState* ClimbPausePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> ClimbUpPlayerState");
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> LadderClimbedPlayerState");
		return new DecendLadderPlayerState();
	}
	return nullptr;
}
void ClimbPausePlayerState::update(Player& player) {}
void ClimbPausePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering ClimbPausePlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{ 1608, 464, 282, 464 });
	
}
void ClimbPausePlayerState::exit(Player& player) 
{
	DEBUG_MSG("Exiting ClimbPausePlayerState");
}