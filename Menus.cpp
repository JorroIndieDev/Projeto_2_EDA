#include "Headers/Menus.h"
#include "Headers/AirportListHandler.h"
#include "Headers/structs.h"
#include "Headers/init_planes_people.h"

void dayCycle(Airport &airport) {
    // Verifies if the airport is still working
    bool isWorking = true;

    // Menu option choice
    std::string choice;

    while (isWorking) {
        std::cout << "\n(e)mergencias (o)pcoes (g)ravar (s)next day\n";
        std::cin >> choice;
        switch (choice[0]) {
            case 'e': // Emergency;
                break;
            case 'o': // Options;
                break;
            case 'g': // Save;
                break;
            // Skip day
            case 's':

                if (airport.num_in_arrival < 10 && !airport.emergency_state) {
                    init_plane(airport);
                }

                if (airport.num_in_ramp == 7) {
                    remove_departing_plane(airport);
                }
                std::cout << "Log Arrivals" << std::endl;
                log_arrivals_passengers(airport);
                log_arrival_planes(airport);

                add_ramp_plane(airport);
                std::cout << "Log Ramp" << std::endl;
                log_ramp_planes(airport);
                log_ramp_passengers(airport);

                add_departing_plane(airport);
                std::cout << "Log Depart" << std::endl;
                log_departure_planes(airport);
                log_departures_passengers(airport);


                break;

            default:
                std::cout << "not cool";
                break;
        }
    }
}