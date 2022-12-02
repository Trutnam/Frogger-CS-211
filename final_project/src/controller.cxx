#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

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
