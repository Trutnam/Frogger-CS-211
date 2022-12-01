#pragma once

#include <ge211.hxx>

class Model
{

public:

    // get score function:
    char* get_score() const;

    std::vector<std::pair<float, std::string>> lanes_ =
            {
                    { 0.0f, "xxx..xxx..xxxx.xx..xx.xx"}, //wall lane 0
                    {-2.0f, "....xxx...xxx..x.x..x...xxxxxxxx...x..xxx..x."
                            ".xxxxx...x.x.xxx.x.."}, // log lane 1
                    { 4.0f, "..xxxx...xx..x..xxx.x.x...x...xxxxxxx....xxx...x"
                            "...x.x..xxx...x."}, // log lane 2
                    {-6.0f, "..x.x..xxx..x.x.xxxxx.....xxxxxxx....x..x..xxx.."
                            ".xxxxxx..x....x."}, // log lane 3
                    { 4.0f, "...xxxx..x.x...xxx..xxxxxx...xx...x.x..x.xx..x.x"
                            "..xxx...xx..x..x"}, //log lane 4
                    {-2.0f, "xx..xx...x.x.xxx....xx..x...xxx.x.xx...xx..x..xx"
                            "....x..xx..xxx.."}, //log lane 5
                    { 0.0f, "................................................"
                            "................"}, //sidewalk lane 6
                    { 2.0f, "xxx...xxx..xxx........xxx...xxx..xxx........xxx."
                            "..xxx...xxx..xxx"}, // bus lane 7
                    {-4.0f, "....xx..xx....xx.....xx.xx.xx....xx...xx..xx.."
                            ".xx..xx....xx...xx"}, // car lane 8
                    { 6.0f, "..xx..xx..xx...xx.....xx...xx..xx.....xx.....xx."
                            ".xx....xx....xx."}, //car lane 9
                    {-4.0f, "...xxx..xxx........xxx....xxx.....xxx.....xxx..."
                            ".xxx..xxx...xxx."}, //bus lane 10
                    { 2.0f, "..xx.....xx....xx..xx........xx..xx..........xx."
                            ".....xx..xx.xx.."}, //car lane 11
                    { 0.0f, "................................................"
                            "................"}, //sidewalk lane 12

            };
    char* score_ = "Score: 0";
    bool alive_ = true;
    ge211::geometry::Posn<int> frog_pos;

};
