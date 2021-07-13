#include "StageManager.h"

void StageManager::CreateStage(int id)
{
	switch (id)
	{
	case TITLE_STAGE_ID:
		titleStage = new TitleStage(window);
	}
}

StageManager::StageManager(GameWindow* _window) : window(_window)
{

}

Stage* StageManager::GetStage(int StageId)
{
	switch (StageId)
	{

	case TITLE_STAGE_ID:

		if (titleStage == nullptr)
		{
			CreateStage(TITLE_STAGE_ID);
		}

		return titleStage;


	default:
		return nullptr;
	}
}

Stage* StageManager::GetFucusedStage()
{
	switch (focusedStageId)
	{

	case TITLE_STAGE_ID:

		if (titleStage == nullptr)
		{
			CreateStage(TITLE_STAGE_ID);
		}

		return titleStage;


	default:
		break;
	}
}
