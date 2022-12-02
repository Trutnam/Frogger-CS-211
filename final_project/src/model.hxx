#pragma once

#include <ge211.hxx>

class Model
{

public:

    // get score function:
    char* get_score() const;
    std::vector<std::pair<float, std::string>> get_lanes();

    // on frame function
    void on_frame(double dt);

    std::vector<std::pair<float, std::string>> lanes_ =
            {
                    {0.0f,"x.xx.xxx.xx.x..xxx.."}, //wall lane 0
                    {2.0f,"x....xxxxxxxx....xxx"}, // log lane 1
                    {3.0f,"xxx....xxxxx....xxxx"}, // log lane 2
                    {2.0f, "x....xxxxx....xxxxx"}, // log lane 3
                    {1.0f, "x....xxx...xxx....x"}, //log lane 4
                    {2.0f, "x....xxxx.....xxxxx"}, //log lane 5
                    { 0.0f,"...................."}, //sidewalk lane 6
                    { 2.0f, ".........xx....xx..."}, // bus lane 7
                    {1.0f, "..xx...........xx..."}, // car lane 8
                    { 3.0f, "......xx...xx......."}, //car lane 9
                    {2.0f, "..xx....xx.......xx."}, //bus lane 10
                    { 1.0f, ".xx............xx..."}, //car lane 11
                    { 0.0f, "...................."}, //sidewalk lane 12

                 //   { 0.0f, "xxx..xxx..xxxx.xx..xx.xx"}, //wall lane 0
                  //  {3.0f, "..........xxx..............xxxx............."
                  //          ".xxxx........xxx...."}, // log lane 1
                  //  { -3.0f, "..xxxx..........xxx...........xxxxxxx....xxx.
                  //  ..."
                  //          "........xxx....."}, // log lane 2
                   // {1.0f, ".......xxx......xxxxx.....xxxxxxx.........xxxx.."
                   //         ".xxxxxx........."}, // log lane 3
                   // { -2.0f, "...xxx........xxx.....xxx......................"
                   //         ".....xxx......"}, //log lane 4
                   // {3.0f, "....xxx.......xxx..........xxxx........xxx......."
                   //         ".......xxx..xxx.."}, //log lane 5
                   // { 0.0f, "................................................"
                    //        "................"}, //sidewalk lane 6
                   // { 3.0f, "xxx........xxx........xxx........xxx........xxx."
                   //         "..xxx........xxx"}, // bus lane 7
                   // {-2.0f, "....xx..xx....xx...........xx....xx.......xx.."
                   //         ".xx..xx....xx...xx"}, // car lane 8
                   // { 4.0f, "..xx......xx..........xx.......xx.....xx.....xx."
                   //         ".xx....xx....xx."}, //car lane 9
                    //{-3.0f, "...xxx.............xxx............xxx.....xxx..."
                    //        ".xxx..xxx...xxx."}, //bus lane 10
                    //{ 2.0f, "..xx.....xx........xx............xx..........xx."
                    //        ".....xx..xx.xx.."}, //car lane 11
                    //{ 0.0f, "................................................"
                    //        "................"}, //sidewalk lane 12

            };
    char* score_ = "Score: 0";
    bool alive_ = true;
    float elapsed_time_ = 0;
    //ge211::geometry::Posn<int> frog_pos;

};
