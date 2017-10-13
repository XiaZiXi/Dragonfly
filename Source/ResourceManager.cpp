#include "LogManager.h"

#include "ResourceManager.h"

df::ResourceManager::ResourceManager()
{
	m_spriteCount = 0;
}

std::string df::ResourceManager::readLine(std::ifstream *p_file, const char *tag)
{
	if (!p_file->good())
	{
		LM.writeLog("ResourceManager::readLine(): ERROR! file pointer is bad.");
		return std::string();
	}

	std::string line;
	std::getline(*p_file, line);
	if (!line.compare(tag))
	{
		LM.writeLog("ResourceManager::readLine(): ERROR! Not right tag.");
		return std::string();
	}

	return line;
}

int df::ResourceManager::readLineInt(std::ifstream *p_file, int *p_lineNum, const char *tag)
{
	std::string line = readLine(p_file, tag);
	if (line.empty())
	{
		return -1;
	}

	int number = std::atoi(line.substr(strlen(tag) + 1).c_str());

	(*p_lineNum)++;

	return number;
}

std::string df::ResourceManager::readLineStr(std::ifstream *p_file, int *p_lineNum, const char *tag)
{
	std::string line = readLine(p_file, tag);
	if (line.empty())
	{
		return line;
	}

	std::string str = line.substr(strlen(tag) + 1);

	(*p_lineNum)++;

	return str;
}

df::Frame df::ResourceManager::readFrame(std::ifstream *p_file, int *p_lineNum, int width, int height)
{
	std::string line;
	std::string frameStr;

	for (int i = 1; i <= height; i++)
	{
		if (!p_file->good())
		{
			LM.writeLog("ResourceManager::readFrame(): ERROR! file pointer is bad.");
			return Frame();
		}

		std::getline(*p_file, line);
		if (line.length() != width)
		{
			LM.writeLog("ResourceManager::readFrame(): ERROR! Incorrect width.\nLine:%s\t With: %d", line.c_str(), width);
			return Frame();
		}
		(*p_lineNum)++;
		frameStr += line;
	}

	std::getline(*p_file, line);
	(*p_lineNum)++;
	if (line != END_FRAME_TOKEN)
	{
		LM.writeLog("ResourceManager::readFrame(): ERROR! Did not reach end of frame.");
		return Frame();
	}

	return Frame(width, height, frameStr);
}

df::ResourceManager &df::ResourceManager::getInstance()
{
	static ResourceManager resourceManager;
	return resourceManager;
}

int df::ResourceManager::startUp()
{
	Manager::startUp();
	return 0;
}

void df::ResourceManager::shutDown()
{
	Manager::shutDown();
}

int df::ResourceManager::loadSprite(std::string filename, std::string label)
{
	std::ifstream file(filename, std::ifstream::in);

	int lineNum = 0;

	int frames = readLineInt(&file, &lineNum, FRAMES_TOKEN.c_str());
	int width = readLineInt(&file, &lineNum, WIDTH_TOKEN.c_str());
	int height = readLineInt(&file, &lineNum, HEIGHT_TOKEN.c_str());
	std::string color = readLineStr(&file, &lineNum, COLOR_TOKEN.c_str());

	// Check if the header returned reasonable values.
	if (frames == -1 || width == -1 || height == -1)
	{
		LM.writeLog("ResourceManager::loadSprite(): ERROR! unable to read header.");
		return -1;
	}

	Sprite *p_sprite = new Sprite(frames);

	while (!file.eof())
	{
		Frame frame = readFrame(&file, &lineNum, width, height);
		p_sprite->addFrame(frame);
	}

	file.close();

	p_sprite->setLabel(label);
	p_sprite->setWidth(width);
	p_sprite->setHeight(height);
	p_sprite->setColor(df::ColorHelper::stringToColor(color));

	// Add sprite to sprite array.
	m_p_sprite[m_spriteCount] = p_sprite;
	m_spriteCount++;

	return 0;
}

int df::ResourceManager::unloadSprite(std::string label)
{
	for (int i = 0; i < m_spriteCount; i++)
	{
		if (label == m_p_sprite[i]->getLabel())
		{
			delete m_p_sprite[i];

			// Shift over remaining sprites.
			for (int j = i; j < m_spriteCount - 1; j++)
			{
				m_p_sprite[j] = m_p_sprite[j + 1];
			}

			m_spriteCount--;
			return 0;
		}
	}
	return -1; // Sprite not found.
}

df::Sprite *df::ResourceManager::getSprite(std::string label) const
{
	for (int i = 0; i < m_spriteCount; i++)
	{
		if (label == m_p_sprite[i]->getLabel())
		{
			return m_p_sprite[i];
		}
	}

	return NULL; // Sprite not found.
}

int df::ResourceManager::loadSound(std::string filename, std::string label)
{
	if (m_soundCount == MAX_SOUNDS)
	{
		LM.writeLog("Sound array full.");
		return -1;
	}

	if (m_sound[m_soundCount].loadSound(filename) == -1)
	{
		LM.writeLog("Unable to load from file.");
		return -1;
	}

	// All set.
	m_sound[m_soundCount].setLabel(label);
	m_soundCount++;
	return 0;
}

int df::ResourceManager::unloadSound(std::string label)
{
	for (int i = 0; i < m_soundCount; i++)
	{
		if (m_sound[i].getLabel() == label)
		{
			// Scoot over remaining sounds.
			for (int j = i; j < m_soundCount - 1; j++)
			{
				m_sound[j] = m_sound[j + 1];
			}

			m_soundCount--;
			return 0;
		}
	}

	return -1; // Sound not found.
}

df::Sound *df::ResourceManager::getSound(std::string label)
{
	for (int i = 0; i < m_soundCount; i++)
	{
		if (m_sound[i].getLabel() == label)
		{
			return (&m_sound[i]);
		}
	}
	return NULL; // Sound not found.
}

int df::ResourceManager::loadMusic(std::string filename, std::string label)
{
	if (label == "")
	{
		LM.writeLog("Label cannot be empty stringt.");
		return -1;
	}

	if (m_musicCount == MAX_SOUNDS)
	{
		LM.writeLog("Music array full.");
		return -1;
	}

	if (m_music[m_musicCount].loadMusic(filename) == -1)
	{
		LM.writeLog("Unable to load from file.");
		return -1;
	}

	// All set.
	m_music[m_musicCount].setLabel(label);
	m_musicCount++;
	return 0;
}

int df::ResourceManager::unloadMusic(std::string label)
{
	for (int i = 0; i < m_musicCount; i++)
	{
		if (m_music[i].getLabel() == label)
		{
			m_music[i].setLabel("");
			return 0;
		}
	}

	return -1; // Music not found.
}

df::Music *df::ResourceManager::getMusic(std::string label)
{
	for (int i = 0; i < m_musicCount; i++)
	{
		if (m_music[i].getLabel() == label)
		{
			return (&m_music[i]);
		}
	}
	return NULL; // Music not found.
}
