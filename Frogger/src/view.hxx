#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);

    ge211::Dims<int> inial_window_dimensions() const;

    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;

    ge211::Rectangle_sprite ()


};
