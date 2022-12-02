#include "model.hxx"

// returns score
int Model::get_score() const{
    return score_;
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
    bool dir = true;
    // for each pair in lanes
    for (int i = 0; i < lanes_.size(); i ++) {
        // for each vector in a lane
        for (int j = 0; j < lanes_[0].second.size(); j++) {
            amt_of_spots = lanes_[i].second.size();
            if (lanes_[i].first < 0){
                dir = false;
            }
            else{
                dir = true;
            }

            initial_posn =
                    (int) (elapsed_time_ * lanes_[i].first) % amt_of_spots;
            if (initial_posn < 0) {
                initial_posn = amt_of_spots - (abs(initial_posn) %
                                               amt_of_spots);
            }

            if (initial_posn == 12 && dir) {

                lanes_[i].second[j] = lanes_[i].second[int(j + 1) %
                                                       amt_of_spots];


            }
            if (initial_posn == 12 && not dir) {

                lanes_[i].second[j] = lanes_[i].second[int(j - 1) %
                                                       amt_of_spots];


            }
    }
    }

}