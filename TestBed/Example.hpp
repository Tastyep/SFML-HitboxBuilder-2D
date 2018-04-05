#ifndef TESTBED_EXAMPLE_HPP
#define TESTBED_EXAMPLE_HPP

#include <string>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

#include "Manager.hpp"

namespace TestBed {

class Example {
 public:
  explicit Example(const std::vector<std::string>& fonts);

  void run(const std::vector<std::string>& images);

 private:
  void updateDrawables(std::vector<sf::VertexArray>& bodyVertices, sf::VertexArray& boundingBox);
  void loadSprites(const std::vector<std::string>& images);
  std::vector<sf::VertexArray> buildPolygon();
  sf::VertexArray buildBoundingBox() const;
  bool handleEvents(const sf::Event& event);
  void close();

 private:
  struct Text {
    sf::Text text;
    sf::Font font;
  };

 private:
  sf::RenderWindow _window;
  HitboxBuilder::Manager _hitboxManager;
  std::vector<sf::Texture> _textures;
  std::vector<sf::Sprite> _sprites;

 private:
  size_t _accuracy{ 50 };
  size_t _spriteIdx{ 0 };
  sf::Vector2i _center;
  Text _polygonCount;
};

} /* namespace TestBed */

#endif
