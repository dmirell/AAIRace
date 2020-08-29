#ifndef AAIRACE_SOURCE_ROAD_H_
#define AAIRACE_SOURCE_ROAD_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include <common/drawable_unit.h>

class RacingCar;

class Road : public DrawableUnit {
 public:
  Road() = delete;
  Road(const Road& road) = delete;
  Road(Road&& road) = delete;
  Road&& operator=(const Road& road) = delete;
  Road&& operator=(Road&& road) = delete;

  Road(int screen_width, int screen_height, const DrawFunction& draw_function);

  void SetHeroCar(const std::shared_ptr<RacingCar>& hero_car);

  // DrawableUnit
  virtual void Draw() override;
  virtual void Update(float elapsed_time, const UserControllersContext& context) override;

  float left_x() const;
  float right_x() const;
  float width() const;

  float finish_line_sprite_y() const;
  float start_line_sprite_y() const;

 private:
  sf::Sprite sprite1_;
  sf::Sprite sprite2_;
  sf::Sprite start_line_sprite_;
  sf::Sprite finish_line_sprite_;

  sf::Texture road_texture_;
  sf::Texture start_finish_line_texture_;

  int screen_width_;
  int screen_height_;
  
  float sprite1_y_;
  float sprite2_y_;
  float start_line_sprite_y_;
  float finish_line_sprite_y_;
  float start_finish_line_x_;
  float speed_;

  std::shared_ptr<RacingCar> hero_car_;
};

#endif  // AAIRACE_SOURCE_ROAD_H_