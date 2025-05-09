#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    // TODO
    coaches.push_back(coach);
    reservations.push_back(std::unordered_map<std::string, std::vector<Reservation>>());

}

void Vehicle::addStop(std::string const& stop)
{
    // TODO
    route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // TODO
    if (coachIndex < reservations.size()){
        auto& coach_res = reservations[coachIndex];
        if (!coach_res.contains(seatId)) {
            coach_res[seatId] = std::vector<Reservation>();
        }
        auto& seat_res = reservations[coachIndex][seatId];
        insert_reservation(reservation, seat_res, route);
    } else {
        std::cerr << "Wagen-Index " << coachIndex << " nicht gefunden." << std::endl;
    }


}

void Vehicle::showAllDisplays() const
{
    // TODO
    for (const auto& coach : coaches){
        coach.showAllDisplays();
    }
}

void Vehicle::showAllReservations() const
{
    // TODO
    for (size_t i = 0; i < coaches.size(); ++i) {
        for (const auto& [seatId, reservations] : reservations[i]) {
            std::cout << "Wagen " << i << ", ";
            std::cout << "Platz " << seatId << ": ";
            for (const auto& reservation : reservations) {
                std::cout << reservation.getDisplayText() << ", ";
            }
            std::cout << std::endl;
        }
    }
}

void Vehicle::setCurrentStop(size_t pos)
{
    // TODO
    if(pos < route.size()){
        next_stop = route[pos];
    }else {
        next_stop = " ";
    }
    
}

void Vehicle::arriveAtStop()
{
    // TODO
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays(next_stop);
    }
    auto it = std::find(route.begin(), route.end(), next_stop);
    auto current_pos = it - route.begin();
    setCurrentStop(current_pos + 1);
    updateSeatDisplays();

}

void Vehicle::departFromStop()
{
    // TODO
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays("Nächster Halt: " + next_stop);
    }
}

void Vehicle::updateSeatDisplays()
{
    // TODO
    for (size_t i = 0; i < coaches.size(); ++i) {
        auto& coach = coaches[i];
        for (const auto& [seatId, reservations] : reservations[i]) {
            auto reservation = get_next_reservation(reservations, next_stop, route);
            if (!reservation.isEmpty()) {
                coach.updateSeatDisplay(seatId, reservation.getDisplayText());
            }
        }
    }
}
