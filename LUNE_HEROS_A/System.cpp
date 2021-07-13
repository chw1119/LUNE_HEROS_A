#include "System.h"

void System::Init(GameWindow* window, int stageId)
{
	this->window = window;
	stageManager = new StageManager(window, stageId);
}

System::System()
{

}

System::System(GameWindow* window)
{
	Init(window, TITLE_STAGE_ID);
}

System::System(GameWindow* window, int stageId)
{
	Init(window, stageId);
}
