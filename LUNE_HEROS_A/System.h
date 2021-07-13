#ifndef _System
#define _System

#include "Stage.h"
#include "Looper.h"
#include "TitleStage.h"
#include "GameWindow.h"
#include "StageManager.h"

class System
{
private:

	int loopDelay     = 0;
	int lastFrameTime = 0;

	GameWindow* window         = nullptr;

	/* 매니저 클래스 */
	StageManager* stageManager = nullptr;


private:
	
	void Init(GameWindow* window, int stageId);

public:

	System();
	System(GameWindow* window);
	System(GameWindow* window, int stageId);

	

};


#endif