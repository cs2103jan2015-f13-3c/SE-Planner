#pragma once

#include "ViewUI.h"
#include "Logic.h"

class UI {
private:
	ViewUI *_viewUI;
	Logic *_logic;

public:
	UI(void);
	~UI(void);

	void run();

};