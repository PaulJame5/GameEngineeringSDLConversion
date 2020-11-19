#include "InputKeyboard.h"

InputKeyboard::InputKeyboard()
{
}

InputKeyboard::~InputKeyboard()
{
}

bool InputKeyboard::Initialize(void)
{
	///--- Initialize the las frame array to 0
	memset(m_piPreviousInput, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
	///--- Copy the current status
	memcpy(m_piCurrentInput, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);
	return true;
}

void InputKeyboard::Update(void)
{
	memcpy(m_piPreviousInput, m_piCurrentInput, sizeof(Uint8) * SDL_NUM_SCANCODES);
	memcpy(m_piCurrentInput, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);
}

bool InputKeyboard::IsKeyTriggered(const SDL_Scancode iKeyCode) const
{
	return (m_piCurrentInput[iKeyCode] == 1 && m_piPreviousInput[iKeyCode] == 0);
}

bool InputKeyboard::IsKeyPressed(const SDL_Scancode iKeyCode) const
{
	return (m_piCurrentInput[iKeyCode] == 1);
}

bool InputKeyboard::IsKeyReleased(const SDL_Scancode iKeyCode) const
{
	return (m_piCurrentInput[iKeyCode] == 0 && m_piPreviousInput[iKeyCode] == 1);
}
