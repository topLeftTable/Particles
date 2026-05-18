#include "Engine.h"
#include <random>

Engine::Engine()
{
	unsigned int w = VideoMode::getDesktopMode().width;
	unsigned int h = VideoMode::getDesktopMode().height;
	if (w % 2 != 0)
		w--; // bandaid fix for off-by-one
	if (h % 2 != 0)
		h--;
	m_Window.create(sf::VideoMode(w, h), "Particles", Style::Default);

	font.loadFromFile("fonts/IBMPlexMono-Regular.ttf");
}

void Engine::run()
{
	sf::Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4,
			   {(int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2});
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	text.setFillColor(Color::White);
	text.setCharacterSize(30);
	text.setPosition(20, 20);
	text.setFont(font);

	while (m_Window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		float dt = deltaTime.asSeconds();
		input();
		update(dt);
		draw();
	}
}

void Engine::input()
{
	sf::Event event;
	random_device rand;
	mt19937 gen(rand());
	uniform_int_distribution<> dist(25, 50);

	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Key::Escape)
			{
				m_Window.close();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			pressed = true;
			framesSinceLastDrag = 0;
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			pressed = false;
		}
		if (pressed)
		{
			if (framesSinceLastDrag == 0)
			{
				sf::Vector2i mPos = sf::Mouse::getPosition(m_Window);
				for (int i = 0; i < 5; i++)
				{
					m_particles.emplace_back(m_Window, dist(gen), mPos);
				}
			}
			if (framesSinceLastDrag == 5) framesSinceLastDrag = 0;
			else framesSinceLastDrag++;
		}
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}
	}
}
void Engine::update(float dtAsSeconds)
{
	for (vector<Particle>::iterator it = m_particles.begin();
		 it != m_particles.end();)
	{
		it->colorShift(1, 2);
		if (it->getTTL() > 3.00)
		{
			it->update(dtAsSeconds);
			++it;
		}
		else
		{
			it = m_particles.erase(it);
		}
	}
}
void Engine::draw()
{
	m_Window.clear();
	size_t size = m_particles.size();
	for (int i = 0; i < size; i++)
	{
		m_Window.draw(m_particles[i]);
	}

	ostringstream message;
	message<<"Number of particles: "<<size;
	text.setString(message.str());
	m_Window.draw(text);
	m_Window.display();
}
