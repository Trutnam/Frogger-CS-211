#include "model.hxx"

#include <string>

class View
{
public:
    explicit View(Model const& model);

    ge211::Dims<int> initial_window_dimensions() const;

    void draw(ge211::Sprite_set& set);
    
    ge211::Posn<int> fly_pos = {36 * (1 + 3/8), 3/8};
    std::vector<ge211::geometry::Posn<int>> fly_spaces = {{36 + 3/8, 3/8}, 
    {(36 * 4) + 3/8, 3/8}, {(36 * 6) + 3/8, 3/8}, {(36 * 8) + 3/8, 3/8}, 
    {(36 * 11) + 3/8, 3/8}, {(36 * 13) + 3/8, 3/8}, {(36 * 14) + 3/8, 3/8}, 
    {(36 * 18) + 3/8, 3/8}, {(36 * 19) + 3/8, 3/8}};

private:
    Model const& model_;

    ge211::Rectangle_sprite frog_sprite;
    ge211::Rectangle_sprite fly_sprite;
    ge211::Rectangle_sprite car_sprite;
    ge211::Rectangle_sprite bus_sprite;
    ge211::Rectangle_sprite log_sprite;
    ge211::Rectangle_sprite water_sprite;
    ge211::Rectangle_sprite street_sprite;
    ge211::Rectangle_sprite sidewalk_sprite;

    ge211::Font sans30_{"sans.ttf", 30};
    ge211::Text_sprite score_sprite_;
    ge211::Text_sprite lives_sprite;
    ge211::Text_sprite time_sprite;

};
