#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HistoryUndoUnitTest
{		
	TEST_CLASS(HistoryUndoUnitTestClass)
	{
	public:
		
		TEST_METHOD(HistoryUndoPushState)
		{
			History history;
			history.clearState();

			vector<Task> currentState;
			history.pushState(currentState);

			history.undoState();

			Assert::AreEqual(true, history.TaskStack.empty());
		}

		TEST_METHOD(HistoryUndoEmptyState)
		{
			History history;
			history.clearState();

			Assert::AreEqual(false, history.canUndo());
		}
	};
}