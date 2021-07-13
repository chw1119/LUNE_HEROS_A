#ifndef _STAGE_MANAGER
#define _STAGE_MANAGER

#include "Stage.h"
#include "TitleStage.h"

class StageManager
{
private:
	
	TitleStage* titleStage = nullptr;

	int focusedStageId = TITLE_STAGE_ID;

private:
	void CreateStage(int id);

public:
	StageManager();
};


#endif
