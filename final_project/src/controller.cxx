#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::on_key(ge211::Key key){
    if (key == ge211::Key::up()){
        model_.move_frog_up();
    }
    if (key == ge211::Key::down()){
        model_.move_frog_down();
    }
    if (key == ge211::Key::right()){
        model_.move_frog_right();
    }
    if (key == ge211::Key::left()){
        model_.move_frog_left();
    }



}


void
Controller::on_frame(double dt)
    {
        model_.on_frame(dt);
    }

 ge211::Dims<int>
 Controller::initial_window_dimensions() const
 {
    return view_.initial_window_dimensions();
 }


    void
 Controller::draw(ge211::Sprite_set& set)
    {
        view_.draw(set);
    }
