#include "view.hxx"

#include <iostream>

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static int const grid_size = 36;

static Color const frog_color {43, 156, 28};
static Color const fly_color {32, 32, 32};
static Color const car_color {255, 30, 0};
static Color const bus_color {0, 21, 255};
static Color const log_color {74, 44, 19};
static Color const water_color {19, 178, 207};
static Color const street_color {33, 33, 33};
static Color const sidewalk_color {120, 120, 120};

View::View(Model const& model)
        : model_(model),
        frog_sprite({grid_size, grid_size}, frog_color),
        fly_sprite({grid_size/4, grid_size/4}, fly_color),
        car_sprite({grid_size, grid_size}, car_color),
        bus_sprite({grid_size, grid_size}, bus_color),
        log_sprite({grid_size, grid_size}, log_color),
        water_sprite({grid_size, grid_size}, water_color),
        street_sprite({grid_size, grid_size}, street_color),
        sidewalk_sprite({grid_size, grid_size}, sidewalk_color)
        
{ }

ge211::Dims<int>
View::initial_window_dimensions() const
{
    int x = grid_size * 13;
    int y = grid_size * 15;

    return {x, y};
}

void
View::draw(ge211::Sprite_set& set)
{
    if (model_.get_lives() <= 0) {
        ge211::Text_sprite::Builder final_builder(sans30_);
        final_builder << "GAME OVER";
        lives_sprite.reconfigure(final_builder);

        ge211::Text_sprite::Builder score_builder(sans30_);
        score_builder << "Score:" << model_.get_score();
        score_sprite_.reconfigure(score_builder);

        set.add_sprite(lives_sprite, {grid_size * 4, grid_size * 6});
        set.add_sprite(score_sprite_, {grid_size * 5, grid_size * 7});

    }
    else {

        // draw time
        ge211::Text_sprite::Builder time_builder(sans30_);
        time_builder << "Time: " << model_.get_time();
        time_sprite.reconfigure(time_builder);

        set.add_sprite(time_sprite, {300, 470});

        // draw score
        ge211::Text_sprite::Builder score_builder(sans30_);
        score_builder << "Score: " << model_.get_score();
        score_sprite_.reconfigure(score_builder);

        set.add_sprite(score_sprite_, {25, 500});

        // draw lives
        ge211::Text_sprite::Builder lives_builder(sans30_);
        lives_builder << "Lives: " << model_.lives_;
        lives_sprite.reconfigure(lives_builder);

        set.add_sprite(lives_sprite, {25, 470});
        
        //draw flies
        set.add_sprite(fly_sprite, model_.fly_pos, 1);
            
        //i = height
        for (int i = 0; i < 13; i++) {
            //sidewalks
            if ((i == 12) || (i == 6)) {
                //j = width
                for (int j = 0; j < 23; j++) {
                    set.add_sprite(sidewalk_sprite,
                                   {j * grid_size, i * grid_size});
                }
            }

            //cars
            if ((i == 11) || (i == 9) || (i == 8)) {

                for (int j = 0; j < 23; j++) {
                    if (model_.lanes_[i].second[j] == '.') {
                        set.add_sprite(street_sprite, {j * grid_size, i *
                                                                      grid_size});
                    } else {
                        set.add_sprite(car_sprite,
                                       {j * grid_size, i * grid_size});
                    }
                }
            }

            //buses
            if ((i == 10) || (i == 7)) {

                for (int j = 0; j < 23; j++) {
                    if (model_.lanes_[i].second[j] == '.') {
                        set.add_sprite(street_sprite, {j * grid_size, i *
                                                                      grid_size});
                    } else {
                        set.add_sprite(bus_sprite,
                                       {j * grid_size, i * grid_size});
                    }
                }
            }

            //logs
            if ((i >= 1) && (i <= 5)) {

                for (int j = 0; j < 23; j++) {
                    if (model_.lanes_[i].second[j] == '.') {
                        set.add_sprite(log_sprite, {j * grid_size, i *
                                                                   grid_size});
                    } else {
                        set.add_sprite(water_sprite,
                                       {j * grid_size, i * grid_size});
                    }
                }
            }

            //wall
            if (i == 0) {
                for (int j = 0; j < 23; j++) {
                    if (model_.lanes_[i].second[j] == '.') {
                        set.add_sprite(sidewalk_sprite, {j * grid_size, i *
                                                                        grid_size});
                    } else {
                        set.add_sprite(street_sprite,
                                       {j * grid_size, i * grid_size});
                    }
                }
            }
        }

        set.add_sprite(frog_sprite, model_.frog_pos, 1);
    }
}

