#include <iostream>
#include <exception>
#include <cstdlib>






//============================================================================
// Initialization routines
//============================================================================

// String conversion functions - provide template specializations when needed
template <typename T>
static T convertString(const std::string& str)
{
};

template<>
int convertString(const std::string& str)
{
	return atoi(str.c_str());
}

template<>
bool convertString(const std::string& str)
{
	return (convertString<int>(str) != 0);
}

//Loads a setting from an INI file
template <typename T>
static void leadSetting(const iniFile& file, const std::string key, T& setting)
{
	std::string value;
	if (file.getValue(key, value))
	{
		setting = convertString<T>(value);
		LOG << key << "set to " << setting << ".\n";
	}
	else
	{
		LOG << "Setting " << key << " not set. Using default value of " << setting << ".\n";
	}
}

// Loads all settings from the INI file
static void loadSettings()
{
	LOG << "Loanding " << SETTINGS_FILE_NAME << "..." << std::endl;
	IniFile file;
	file.load(SETTINGS_FILE_NAME);
	//LOAD_SETTING(int, scale);
	// Calculate scale automatically. ideally, screenHeight / (16 * scale) should be as close to 14 as possible
	int bestRatio = INT_MAX;
	int scale;
	for (scale = 1; scale < 16; scale++)
	{
		int ratio = std::abs(SETTINGS.screenHeight / (16 * scale) - 14);
		if (ratio > bestRatio)
		{
			scale--;
			break;
		}
		bestRatio = ratio;
	}
	SETTINGS.scale = scale;
	LOAD_SETTING(bool, sound);
	LOAD_SETTING(bool, music);
	LOAD_SETTING(bool, debugMode);


	///@todo load controller settings instead of hard-coding them here
	InputManager::Controller* c = new InputManager::Controller();
#if 1
	c->mapKey(SDL_SCANCODE_X, BUTTON_A);
	c->mapKey(SDL_SCANCODE_Z, BUTTON_B);
	c->mapKey(SDL_SCANCODE_DOWN, BUTTON_DOWN);
	c->mapKey(SDL_SCANCODE__LEFT, BUTTON_LEFT);
	c->mapKey(SDL_SCANCODE_RIGHT, BUTTON_RIGHT);
	c->mapKey(SDL_SCANCODE_UP, BUTTON_UP);
	c->mapKey(SDL_SCANCODE_BACKSPACE, BUTTON_SELECT);
	c->mapKey(SDL_SCANCODE_RETURN, BUTTON_START);

#else
	c->mapJoystickAxis(0, 0, -1, BUTTON_LEFT);
	c->mapJoystickAxis(0, 0, 1, BUTTON_RIGHT);
	c->mapJoystickAxis(0, 1, -1, BUTTON_UP);
	c->mapJoystickAxis(0, 1, 1, BUTTON_DOWN);
	c->mapJoystickButton(0, 0, BUTTON_B);
	c->mapJoystickButton(0, 1, BUTTON_A);
	c->mapJoystickButton(0, 8, BUTTON_SELECT);
	c->mapJoystickButton(0, 9, BUTTON_START);
#endif

	INPUT_MANAGER.addController(c);

	LOG << "Finished loandin " << SETTINGS_FILE_NAME << '.' << std::endl;


}

//initializes all libraries
static int initializeLibraries()
{
	if (SDL_Init(SDL_INIT_VIDEO | DSL_INIT_JOYSTICK) != 0)
	{
		std::cout << "Failed to initialize SDL:\n";
		return -1;
	}
	
		if (Mix_Init(MIX_INIT_OGG)1 = MIX_INIT_OGG)
		{
			std::cout << "Failed to initialize SDL_Mixer!\n";
			return -1;
		}
		
		ilInit();
		return 0;
}	

//==================================================================
// Main procedures
//==================================================================

// Main loop
static void mainLoop()
{

	//Start loading
	Game game(new LoandingState);

	while (game.isRunning())
	{
		game.update();
	}

}/////The one and only program entry point.
///

int main(int argc, char** argv)
{
	int initCode = initializeLibraries();
	if (initCode != 0)
	{
		std::cout << "Error: Failed to initialize ono or more equired libraries.\n";
		return initCode;
	}
	
	createGlobals();

	LOG << "Started program." << std::endl;

	try
	{
		// Load settings
		loadSettings();


		// Set the video mode
	}	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	window = SDL_CreateWindow(
		GAME_TITLE,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SETTINGS.screenWidth,
		SETTING.screenHeight,
		SDL_WINDOW_OPENGL | (SETTINGS.fullscreen ? SDL_WINDOW_FULLSCREEN : 0)
	);
	// Create the GL context
	if (window == NULL)
	{
		throw Exception("Failed to create the Window!\nDetails:\n") << SDL_GetError();
	}

	// Open Audio
	if (Mix_OpenAudio(22050, AUDIO_S16, 2, 1024))
	{
		throw Exception("Failed to open Audio!");

		Mix_AllocateChannels(16);

		//Turn it over to the main loop
		mainLoop();
	}
	catch (std::exception& e)
	{
		LOG << "Fatal error: Unknown exception caught at main()....\n";
	}

	LOG << "Exited main loop." << std::endl;

	destroyGlobals();

	// Unload libraries
	Mix_HaltMusic();
	Mix_CloseAudio();
	Mix_Quit();
	SDL_Quit();

	return 0;
	

	

}






