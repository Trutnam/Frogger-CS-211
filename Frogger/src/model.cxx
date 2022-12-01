#include "model.hxx"

Model::lanes_ =
        {
                { 0.0f, "................................................................"}, //sidewalk lane 0
                { 2.0f, "..xx.....xx....xx..xx........xx..xx..........xx......xx..xx.xx.."}, //car lane 1
                {-4.0f, "...xxx..xxx........xxx....xxx.....xxx.....xxx....xxx..xxx...xxx."}, //bus lane 2
                { 6.0f, "..xx..xx..xx...xx.....xx...xx..xx.....xx.....xx..xx....xx....xx."}, //car lane 3
                { 0.0f, "................................................................"}, //sidewalk lane 4
                {-2.0f, "xx..xx...x.x.xxx....xx..x...xxx.x.xx...xx..x..xx....x..xx..xxx.."}, //log lane 5
                { 4.0f, "...xx.x..x.x...xxx..xx.x.x...xx...x.x..x.xx..x.x..xxx...xx..x..x"}, //log lane 6
                { 0.0f, "xxxxxxx...xxxxxx...xxxxxxxxxxxx....xxxxxxxxx..xxxxxxxx..xxxxxx.."}, //wall lane 7
        };
