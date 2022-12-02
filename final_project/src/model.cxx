#include "model.hxx"

// returns score
char* Model::get_score() const{
    return score_;
}

std::vector<std::pair<float, std::string>> Model::get_lanes(){
    return lanes_;
}



void Model::on_frame(double dt){
    elapsed_time_ += dt;
    int initial_posn;
    // for each pair in lanes
    for (int i = 0; i < lanes_.size(); i ++){
        // for each vector in a lane
       for (int j = 0; j < lanes_[0].second.size(); j++) {
           initial_posn = (int)(elapsed_time_ * lanes_[i].first) % 60;
           if (initial_posn < 0){
               initial_posn = 60 - (abs(initial_posn) % 60);
           }
           lanes_[i].second[j] = lanes_[i].second[(initial_posn + j) % 60];

       }
    }

}