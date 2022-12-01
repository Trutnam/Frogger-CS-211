#pragma once

#include "model.hxx"

#include <string>

class View
{
public:
    explicit View(Model const& model);

    ge211::Dims<int> initial_window_dimensions() const;

    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;

    ge211::Rectangle_sprite() frog_sprite;
    ge211::Rectangle_sprite() fly_sprite;
    ge211::Rectangle_sprite() car_sprite;
    ge211::Rectangle_sprite() bus_sprite;
    ge211::Rectangle_sprite() log_sprite;
    ge211::Rectangle_sprite() water_sprite;
    ge211::Rectangle_sprite() street_sprite;
    ge211::Rectangle_sprite() sidewalk_sprite;
    ge211::Text_sprite() score_sprite;
};
