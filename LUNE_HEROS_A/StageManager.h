#ifndef _STAGE_MANAGER
#define _STAGE_MANAGER

#include "Stage.h"
#include "TitleStage.h"

#include "GameWindow.h"

class StageManager
{
private:
	GameWindow* window     = nullptr;
	TitleStage* titleStage = nullptr;

	int focusedStageId = TITLE_STAGE_ID;

private:
	void CreateStage(int id);

public:
	StageManager();
	StageManager(GameWindow* window);
	StageManager(GameWindow* window, int stageId);

	Stage* GetStage(int StageId);
	Stage* GetFucusedStage();
};


#endif
