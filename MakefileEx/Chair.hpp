#pragma once

#include <iostream>

using namespace std;

class Chair {
    string woodType;
    string seatShape;
    int seatArea;
    int legs;
    bool broken;

    public:
    Chair()
        : seatArea(20), legs(4), broken(false) {}
    Chair(string w, string s, int sa, int l) 
        : woodType(w), seatShape(s), seatArea(sa), legs(l), broken(false) {}

    string getWoodType() { return woodType; }
    string getSeatShape() { return seatShape; }
    int getSeatArea() { return seatArea; }
    int getLegs() { return legs; }
    bool isBroken() { return broken; }

    void print();

    void setWoodType(string w) { woodType = w; }
    void setSeatShape(string s) { seatShape = s; }

    void sitDown(int force);
    void repair();
    
};