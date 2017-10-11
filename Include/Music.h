#pragma once
#include <string>
#include <SFML/Audio.hpp>

namespace df {
class Music {
private:
	sf::Music m_music;				// The SFML music.
	std::string m_label;			// Text label to identify sound.

public:
	Music(Music const &copy) = delete;				// Don't allow copy.
	void operator=(Music const &assign) = delete;	// Don't allow assignment.

	Music();

	// Associate music buffer with file.
	// Return 0 if ok, else -1.
	int loadMusic(std::string filename);

	// Get/Set label associated with music.
	void setLabel(std::string newLabel);
	std::string getLabel() const;

	// Play music.
	// If loop is true, repeat play when done.
	void play(bool loop = false);

	// Stop music.
	void stop();

	// Pause music.
	void pause();

	// Return pointer to SFML music.
	sf::Music *getMusic();
};
}