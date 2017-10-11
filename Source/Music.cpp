#include "Music.h"

df::Music::Music()
{
	m_label = "";
}

int df::Music::loadMusic(std::string filename)
{
	if (m_music.openFromFile(filename) == false)
	{
		return -1;
	}

	return 0;
}

void df::Music::setLabel(std::string newLabel)
{
	m_label = newLabel;
}

std::string df::Music::getLabel() const
{
	return m_label;
}

void df::Music::play(bool loop)
{
	m_music.play();
	m_music.setLoop(loop);
}

void df::Music::stop()
{
	m_music.stop();
}

void df::Music::pause()
{
	m_music.pause();
}

sf::Music *df::Music::getMusic()
{
	return &m_music;
}
