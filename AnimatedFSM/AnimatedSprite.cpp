#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() : 
	m_current_frame(0),
	m_loop(true),
	m_play_count(0),
	m_max_plays(0),
	m_played(false)
{
	DEBUG_MSG("AnimatedSprite()");
}

AnimatedSprite::AnimatedSprite(Texture* t) : AnimatedSprite(){
	DEBUG_MSG("AnimatedSprite(const Texture&)");
	setTexture(t);
}

AnimatedSprite::AnimatedSprite(Texture* t, const SDL_Rect& rect) : 
	AnimatedSprite(t)
{
	DEBUG_MSG("AnimatedSprite(const Texture&, const IntRect&)");
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {
	DEBUG_MSG("~AnimatedSprite()");
}


const vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

void AnimatedSprite::clearFrames() {
	m_current_frame = 0;
	m_played = false;
	if (!m_frames.empty())
	{
		m_frames.clear();
	}
}

const SDL_Rect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(const SDL_Rect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::setLooped(bool loop) {
	this->m_loop = loop;
}

const bool AnimatedSprite::getLooped() {
	return this->m_loop;
}

void AnimatedSprite::setPlayed(bool played) {
	this->m_played = played;
}

const bool AnimatedSprite::getPlayed() {
	return this->m_played;
}

void AnimatedSprite::update() {

	// If not looped only play once
	if (m_played == true && !m_loop)
	{
		m_current_frame = m_frames.size() - 1;
		return;
	}
	if (m_frames.size() > m_current_frame + 1)
	{
		m_current_frame++;
	}
	else {
		m_current_frame = 0;
		m_played = true;
	}
}

