#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::run() {
	while (true) {
		_viewUI.inputUserCommand();
	}
}