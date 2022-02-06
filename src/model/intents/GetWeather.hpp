#ifndef GETWEATHER_H
#define GETWEATHER_H

#include <memory>
#include "Intent.hpp"
#include "../entities/Location.hpp"
#include "../entities/Date.hpp"

class GetWeather : public Intent {
    const std::string Name() override;
    std::unique_ptr<Date> Dat;
    std::unique_ptr<Location> Loc;

    public:
        static std::string ID;
};

#endif