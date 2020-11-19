#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <vector>
#include <Debug.h>
#include <Sprite.h>

using namespace std;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(const Texture&);
	AnimatedSprite(const Texture&, const sf::IntRect&);
	~AnimatedSprite();

	const sf::Clock& getClock();
	const sf::Time& getTime();
	const vector<sf::IntRect>& getFrames();
	void clearFrames();
	const sf::IntRect& getFrame(int);
	void addFrame(const sf::IntRect&);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool);
	const bool getPlayed();
	void setTime(sf::Time);
	void update();
	
private:
	sf::Clock m_clock;
	sf::Time m_time;
	vector<sf::IntRect> m_frames;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;
};

#endif // !ANIMATED_SPRITE_H
