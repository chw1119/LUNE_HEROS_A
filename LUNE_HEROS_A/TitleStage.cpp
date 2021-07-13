#include "TitleStage.h"

static float bounding = 0.f;

TitleStage::TitleStage(GameWindow* window) : Stage(window)
{
	standardShader = new Shader("./resource/shaders/vertex/standardVertexShader.glsl", "./resource/shaders/fragment/standardFragmentShader.glsl");

	logoTexture = new Texture(TITLE_LOGO_FILE_ROUTE);
	backTexture = new Texture(BACKGROUND_FILE_ROUTE);
	buttonTexture = new Texture(STARTBUTTON_FILE_ROUTE);

	titleLogo  = new Model(GetWindow(), standardShader, logoTexture);
	background = new Model(GetWindow(), standardShader, backTexture);

	startButton = new Button(GetWindow(), standardShader, buttonTexture, nullptr);

	startButton->SetOnSelect([&]()
		{
			std::cout << "test button" << std::endl;
		}
	);

	startButton->SetOnNotSelect([&]()
		{
			std::cout << "test button NOT" << std::endl;
		}
	);


	//titleLogo - new Model();

	eventManager = new EventManager();


	eventManager->SetOnKeyDown(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_KEYDOWN)
			{
				auto key = event->key.keysym.sym;
				eventManager->SetIsKeyDown(key,true);
			}
		}
	);


	eventManager->SetOnKeyUp(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_KEYUP)
			{
				auto key = event->key.keysym.sym;
				eventManager->SetIsKeyDown(key, false);
			}
		}
	);


	eventManager->SetOnMouseDown(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_MOUSEBUTTONDOWN)
			{
				eventManager->SetIsMouseDown(true);
			}
		}
	);


	eventManager->SetOnMouseMove(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_MOUSEMOTION)
			{
				
			}
		}
	);


	eventManager->SetOnMouseUp(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_MOUSEBUTTONUP)
			{
				eventManager->SetIsMouseDown(false);
			}
		}
	);

	eventManager->SetWindowEvent(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_WINDOWEVENT) {
				switch (event->window.event) {
				case SDL_WINDOWEVENT_SHOWN:
					SDL_Log("Window %d shown", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					SDL_Log("Window %d hidden", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_EXPOSED:
					SDL_Log("Window %d exposed", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_MOVED:
					SDL_Log("Window %d moved to %d,%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
					break;
				case SDL_WINDOWEVENT_RESIZED:
					SDL_Log("Window %d resized to %dx%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					SDL_Log("Window %d size changed to %dx%d",
						event->window.windowID, event->window.data1,
						event->window.data2);

					GetWindow()->Resize(event->window.data1, event->window.data2);

					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					SDL_Log("Window %d minimized", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_MAXIMIZED:
					SDL_Log("Window %d maximized", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_RESTORED:
					SDL_Log("Window %d restored", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_ENTER:
					SDL_Log("Mouse entered window %d",
						event->window.windowID);
					break;
				case SDL_WINDOWEVENT_LEAVE:
					SDL_Log("Mouse left window %d", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					SDL_Log("Window %d gained keyboard focus",
						event->window.windowID);
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					SDL_Log("Window %d lost keyboard focus",
						event->window.windowID);
					break;
				case SDL_WINDOWEVENT_CLOSE:
					SDL_Log("Window %d closed", event->window.windowID);
					break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
				case SDL_WINDOWEVENT_TAKE_FOCUS:
					SDL_Log("Window %d is offered a focus", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_HIT_TEST:
					SDL_Log("Window %d has a special hit test", event->window.windowID);
					break;
#endif
				default:
					SDL_Log("Window %d got unknown event %d",
						event->window.windowID, event->window.event);
					break;
				}
			}
		}
	);
}


void TitleStage::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
 
	int w;
	int h;

	SDL_GetWindowSize(GetWindow()->GetWindow(), &w, &h);

	//printf("w : %d h : %d", w, h);

	background->Resize(w, h);
	background->Draw();

	titleLogo->Resize(300, 300);
	titleLogo->Position(0.f, 120 + 20 * cos(bounding += 0.1));
	titleLogo->Draw();

	startButton->Resize(300, 200);
	startButton->Position(0.f, -300.f);

	startButton->Draw();

	//std::cout << "123";
	
}

void TitleStage::Process(SDL_Event* event)
{
	eventManager->Process(event);

	startButton->Process(event);
}


void TitleStage::Resize(float x, float y)
{

}

/*
				switch (key)
				{
				case SDLK_UP:
				case SDLK_w:


					break;

				case SDLK_LEFT:
				case SDLK_a:

					break;

				case SDLK_DOWN:
				case SDLK_s:

					break;

				case SDLK_RIGHT:
				case SDLK_d:

					break;

				case SDLK_j:
				case SDLK_c:

					break;

				case SDLK_k:
				case SDLK_x:
					break;

				case SDLK_l:
				case SDLK_z:

					break;



				default:
					break;
				}
*/