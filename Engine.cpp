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
}

void Engine::run()
{
	sf::Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4,
			   {(int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2});
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

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
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			pressed = false;
		}
		if (pressed)
		{
			sf::Vector2i mPos = sf::Mouse::getPosition(m_Window);
			for (int i = 0; i < 5; i++)
			{
				m_particles.emplace_back(m_Window, dist(gen), mPos);
			}
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
		if (it->getTTL() > 0.00)
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
	int size = m_particles.size();
	for (int i = 0; i < size; i++)
	{
		m_Window.draw(m_particles[i]);
	}
	m_Window.display();
}
