#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <vector>
#include <Debug.h>
#include <Sprite.h>

using namespace std;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite( Texture*);
	AnimatedSprite( Texture*, const SDL_Rect&);
	~AnimatedSprite();

	const vector<SDL_Rect>& getFrames();
	void clearFrames();
	const SDL_Rect& getFrame(int);
	void addFrame(const SDL_Rect&);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool);
	const bool getPlayed();
	void update();
	
private:
	vector<SDL_Rect> m_frames;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;
};

#endif // !ANIMATED_SPRITE_H
