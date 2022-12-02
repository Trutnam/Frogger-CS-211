#pragma once

#include <ge211.hxx>

class Model
{

public:

    // get score function:
    int get_score() const;

    std::vector<std::pair<float, std::string>> get_lanes();

    // on frame function
    void on_frame(double dt);

    // function to move frog up one unit
    void move_frog_up();

    // function to move frog down one unit
    void move_frog_down();

    // function to move frog right one unit
    void move_frog_right();

    // function to move frog left one unit
    void move_frog_left();

    // stores the furthest(lowest) y coordinate reached by the frog
    int furthest_traveled = 36 * 12;



    std::vector<std::pair<float, std::string>> lanes_ =
            {
                    {0.0f,"x.xx.x.x.xx.x..xxx.."}, //wall lane 0
                    {2.0f,"x.....xxxxxx.....xxx"}, // log lane 1
                    {1.0f,"xxx.....xxxx.....xxx"}, // log lane 2
                    {2.0f, "x.....xxxx.....xxxx"}, // log lane 3
                    {1.0f, "xxxx.......xxxx...x"}, //log lane 4
                    {2.0f, "x.....xxx......xxxx"}, //log lane 5
                    { 0.0f,"...................."}, //sidewalk lane 6
                    { 2.0f, ".........xx....xx..."}, // bus lane 7
                    {1.0f, "..xx...........xx..."}, // car lane 8
                    { 3.0f, "......xx...xx......."}, //car lane 9
                    {2.0f, "..xx....xx.......xx."}, //bus lane 10
                    { 1.0f, ".xx............xx..."}, //car lane 11
                    { 0.0f, "...................."}, //sidewalk lane 12


            };
    int score_ = 0;
    bool alive_ = true;
    float elapsed_time_ = 0;
    ge211::geometry::Posn<int> frog_pos = {36 * 6, 36 * 12};

};
