#pragma once

#include "Input.h"
#include "Output.h"

class UI {
private:
	Input _input(void);
	Output _output(void);

public:
	UI(void);
	~UI(void);
};