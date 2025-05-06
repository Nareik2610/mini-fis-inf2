#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    // TODO
    ceiling_displays.push_back(display);
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    // TODO
    seat_displays[seatId] = display;
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    // TODO
    for(auto& display : ceiling_displays){
        display.updateText(newText);
    }
    
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    // TODO
   // for (auto & display : seat_displays){
   //     if(display.first == seatId){
   //         display.second.updateText(newText);
   //     }
   // }
   for( auto & [id,display]: seat_displays){
    if (id==seatId){
       display.updateText(newText);
    }
  }

 // seat_displays[seatId].updateText(newText);
}

void Coach::showCeilingDisplays() const
{
    // TODO
}

void Coach::showSeatDisplays() const
{
    // TODO
}

void Coach::showAllDisplays() const
{
    // TODO
}
