#pragma once


class Keyboard
{
	struct Keystate
{
		bool ArrowUp, ArrowDown, ArrowLeft, ArrowRight,Plus,Minus;
}Key;
	WPARAM key;
public: Keystate GetKeyState() { return Key;}
	    void OnKeyPressed(unsigned);
		void OnKeyReleased(unsigned);
		void OnPlusPressed() { Key.Plus = true; }
		void OnPlusReleased() { Key.Plus = false; }
		void OnMinusPressed() { Key.Minus = true; }
		void OnMinusReleased() { Key.Minus = false; }
};