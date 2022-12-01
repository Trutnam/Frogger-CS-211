#include "view.hxx"

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static int const grid_size = 36;

static Color const frog_color {43, 156, 28};
static Color const fly_color {92, 92, 92};
static Color const car_color {255, 30, 0};
static Color const bus_color {0, 21, 255};
static Color const log_color {74, 44, 19};
static Color const water_color {19, 178, 207};
static Color const street_color {33, 33, 33};
static Color const sidewalk_color {120, 120, 120};

View::View(Model const& model)
        : model_(model),
        frog_sprite({grid_size/2, grid_size/2}, frog_color),
        fly_sprite({grid_size/4, grid_size/4}, fly_color),
        car_sprite({grid_size, grid_size}, car_color),
        bus_sprite({grid_size, grid_size}, bus_color),
        log_sprite({grid_size, grid_size}, log_color),
        water_sprite({grid_size, grid_size}, water_color),
        street_sprite({grid_size, grid_size}, street_color),
        sidewalk_sprite({grid_size, grid_size}, sidewalk_color)
        
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // draw score
    ge211::Text_sprite::Builder score_builder(sans30_);
    // this should print the value of the score eventually
    score_builder << model_.get_score();
    score_sprite_.reconfigure(score_builder);

    set.add_sprite(score_sprite_, {50, 500});
}
