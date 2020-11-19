#ifndef __INPUTKEYBOARD_H__
#define __INPUTKEYBOARD_H__
#pragma once
///////////////////////////////
#include <SDL.h>
#include <memory>
class InputKeyboard
{
public:
	///--- Constructor/Destructor
	InputKeyboard();
	~InputKeyboard();

	///--- Object control
	bool Initialize(void);
	void Update(void);

	///--- Keyboars state function
	bool IsKeyTriggered(const SDL_Scancode iKeyCode) const;
	bool IsKeyPressed(const SDL_Scancode iKeyCode) const;
	bool IsKeyReleased(const SDL_Scancode iKeyCode) const;
private:
	///--- Last frame Keyboard state
	Uint8 m_piPreviousInput[SDL_NUM_SCANCODES];
	///--- Current frame keyboard state
	Uint8 m_piCurrentInput[SDL_NUM_SCANCODES];
};

///////////////////////////////
#endif   //__INPUTKEYBOARD_H__