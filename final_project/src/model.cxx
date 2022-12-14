#include "model.hxx"

// returns score
int Model::get_score() const{
    return score_;
}

int Model::get_lives() const{
    return lives_;
}

int Model::get_time() const
{
    return int( 30 - (elapsed_time_ / 60));
}

ge211::Posn<int> Model::change_fly_pos()
{
    if (int(elapsed_time_) % 150 == 0)
    {
        int index = 0 + (rand() % 5);
        fly_pos = fly_spaces[index];
    }
    return fly_pos;
}

std::vector<std::pair<float, std::string>> Model::get_lanes(){
    return lanes_;
}

void Model::move_frog_up()
{
    // keep frog in screen domain
    if (frog_pos.y != 0) {
        frog_pos = {frog_pos.x, frog_pos.y - 36};
    }
    // increases score by 10 if frog reaches furthest position
    if(furthest_traveled > frog_pos.y) {
        score_ += 10;
        furthest_traveled = furthest_traveled - 36;
    }
}

void Model::move_frog_down()
{
    // keep frog in screen domain
    if (frog_pos.y != 36 * 12) {
        frog_pos = {frog_pos.x, frog_pos.y + 36};
    }
}


void Model::move_frog_right()
{
    // keep frog in screen domain
    if (frog_pos.x != 36 * 12) {
        frog_pos = {frog_pos.x + 36, frog_pos.y};
    }
}

void Model::move_frog_left()
{
    // keep frog in screen domain
    if (frog_pos.x != 0) {
        frog_pos = {frog_pos.x - 36, frog_pos.y};
    }
}



void Model::on_frame(double dt){
    elapsed_time_ = int(elapsed_time_ + 1);
    int initial_posn;
    int amt_of_spots;

    if (get_time() <= 0){
        lives_ = 0;
    }

    //change fly position
    change_fly_pos();



    // for each pair in lanes
    for (int i = 0; i < lanes_.size(); i ++) {

        // if frog is in this lane, move it according to lane velocity
        if (frog_pos.y < 36 * 6 && frog_pos.y == 36 * i){
           if((int) (elapsed_time_ * lanes_[i].first) % amt_of_spots == 12){
               frog_pos.x = frog_pos.x - 36;
        }
        }

        // if frog is in the last lane, reset the position
        if(frog_pos.y < 36) {
            if (frog_pos.x + (36 * 3 / 8) == fly_pos.x) {
                score_ += 200;
            }
            lives_ = lives_ - 1;
            frog_pos = {36 * 6, 36 * 12};
            furthest_traveled = 36 * 12;
        }


        // for each vector in a lane
        for (int j = 0; j < lanes_[0].second.size(); j++) {

            amt_of_spots = lanes_[i].second.size();

            initial_posn =(int) (elapsed_time_ * lanes_[i].first) % amt_of_spots;



            if (initial_posn == 12 ) {

                lanes_[i].second[j] = lanes_[i].second[int(j + 1) %
                                                       amt_of_spots];

            }


            // if frog pos collides with car, bus, or water, IT DIES!!!!
            if (lanes_[i].second[j] == 'x' && frog_pos ==
            ge211::geometry::Posn<int> {36 * j, 36 * i}){
                frog_pos = {36 * 6, 36 * 12};
                lives_ = lives_ - 1;
                furthest_traveled = 36 * 12;
            }

            // if frog is left or right of the screen, IT DIES!!!!
            if (frog_pos.x < 0 || frog_pos.x > 36 * 12){
                frog_pos = {36 * 6, 36 * 12};
                lives_ = lives_ - 1;
                furthest_traveled = 36 * 12;
            }


    }
    }

}