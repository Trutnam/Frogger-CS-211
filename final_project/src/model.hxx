#pragma once

#include <ge211.hxx>

class Model
{

public:
    std::vector<std::pair<float, std::string>> lanes_ =
            {
                    { 0.0f, "................................................................"}, //sidewalk lane 0
                    { 2.0f, "..xx.....xx....xx..xx........xx..xx..........xx......xx..xx.xx.."}, //car lane 1
                    {-4.0f, "...xxx..xxx........xxx....xxx.....xxx.....xxx....xxx..xxx...xxx."}, //bus lane 2
                    { 6.0f, "..xx..xx..xx...xx.....xx...xx..xx.....xx.....xx..xx....xx....xx."}, //car lane 3
                    {-4.0f, "....xx..xx....xx.....xx.xx.xx....xx...xx..xx...xx..xx....xx...xx"}, // car lane 4
                    { 2.0f, "xxx...xxx..xxx........xxx...xxx..xxx........xxx...xxx...xxx..xxx"}, // bus lane 5
                    { 0.0f, "................................................................"}, //sidewalk lane 4
                    {-2.0f, "xx..xx...x.x.xxx....xx..x...xxx.x.xx...xx..x..xx....x..xx..xxx.."}, //log lane 5
                    { 4.0f, "...xx.x..x.x...xxx..xx.x.x...xx...x.x..x.xx..x.x..xxx...xx..x..x"}, //log lane 6
                    {-6.0f, "..x.x..xxx..x.x.x.xxx.....xxx..xx....x..x..x.x...xxxxxx..x....x."}, // log lane 7
                    { 4.0f, "..xxxx...xx..x..x.x.x.x...x...x.xxxxx....xxx...x...x.x..xxx...x."}, // log lane 8
                    {-2.0f, "....xxx...xxx..x.x..x...x..xxxx...x..xx...x..xxxxx...x.x.xxx.x.."}, // log lane 9
                    { 0.0f, "xxxxxxx...xxxxxx...xxxxxxxxxxxx....xxxxxxxxx..xxxxxxxx..xxxxxxxx"}, //wall lane 10
            };
    int score_ = 0;
    bool alive_ = true;

};
