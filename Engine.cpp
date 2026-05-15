#include "Engine.h"
#include <random>

Engine::Engine()
{
	/// YOUR CODE HERE !!!

        m_Window.create(sf::VideoMode(800, 600), "Particles");
        // I feel like there should be more to this?
}

void Engine::run()
{
	/// YOUR CODE HERE !!!
        sf::Clock clock;
        
        cout << "Starting Particle unit tests..." << endl;
        Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
        p.unitTests();
        cout << "Unit tests complete. Starting engine..." << endl;

        while (m_Window) {
          sf::Time deltaTime = clock.restart();
          float dt = deltaTime.asSeconds();
          input(); #FIXME SCOPE && ARGS
          update(); #FIXME - 
          draw(); #FIXME -
        }
}

void Engine::input()
{
	/// YOUR CODE HERE !!!
        sf::Event event;
        random_device rand;
        mt19937 gen(rand());
        uniform_int_distribution<> dist(25, 50);
 
        while(m_Window.pollEvent(event) {
          if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Escape) {
              m_Window.close();
            }
          }
          if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mPos = sf::Mouse::getPosition(m_Window);  
            for (int i = 0; i < 5; i++) { 
               Particle(RenderTarget &target, dist(gen), mPos); #FIXME what is a render target lmao
            }
          }
        }
}
void Engine::update(float dtAsSeconds)
{
	/// YOUR CODE HERE !!!
        
}
void Engine::draw()
{
	/// YOUR CODE HERE !!!
}
