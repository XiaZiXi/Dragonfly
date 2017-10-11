#include "Sound.h"

df::Sound::Sound()
{
	m_sound = sf::Sound();
	m_soundBuffer = sf::SoundBuffer();
	m_label = "";
}

df::Sound::~Sound()
{
	m_sound.resetBuffer();
}

int df::Sound::loadSound(std::string filename)
{
	if (m_soundBuffer.loadFromFile(filename) == false)
		return -1;

	m_sound.setBuffer(m_soundBuffer);

	return 0;
}

void df::Sound::setLabel(std::string newLabel)
{
	m_label = newLabel;
}

std::string df::Sound::getLabel() const
{
	return m_label;
}

void df::Sound::play(bool loop)
{
	m_sound.play();
	m_sound.setLoop(loop);
}

void df::Sound::stop()
{
	m_sound.stop();
}

void df::Sound::pause()
{
	m_sound.pause();
}

sf::Sound df::Sound::getSound() const
{
	return m_sound;
}
