

#include "reservation_logic.h"

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    // TODO
   
    if (!is_valid_for_route(reservation, stops)) {
        throw std::invalid_argument("Reservation wurde nicht gefunden.");
    }

    reservations.push_back(reservation);
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{
    // TODO

    return Reservation();
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    // TODO

    return true;
}
