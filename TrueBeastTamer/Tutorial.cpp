#include "pch.h"
#include "Tutorial.h"

GameView::Tutorial::Tutorial(Tamer^ t)
{
	T = t;
	Screen = gcnew GameView::Screen(0, 0, 1920, 1080, (sf::String)"Tutorial");

}
