#pragma once
#include <string>
#include <SFML/Audio.hpp>

namespace df {
class Sound {
private:
	sf::Sound m_sound;				// The SFML sound.
	sf::SoundBuffer m_soundBuffer;	// SFML sound buffer associated with sound.
	std::string m_label;			// Text label to identify sound.

public:
	Sound();
	~Sound();

	// Load sound buffer from file.
	// Return 0 if ok, else -1.
	int loadSound(std::string filename);

	// Get/Set label associated with sound.
	void setLabel(std::string newLabel);
	std::string getLabel() const;

	// Play sound.
	// If loop is true, repeat play when done.
	void play(bool loop = false);

	// Stop sound.
	void stop();

	// Pause sound.
	void pause();
	
	// Return SFML sound.
	sf::Sound getSound() const;
};
}