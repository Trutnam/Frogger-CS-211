#include "model.hxx"

// returns score
char* Model::get_score() const{
    return score_;
}

std::vector<std::pair<float, std::string>> Model::get_lanes(){
    return lanes_;
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
    }
    }

}