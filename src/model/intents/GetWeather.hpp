#ifndef GETWEATHER_H
#define GETWEATHER_H

#include <memory>
#include "Intent.hpp"
#include "../entities/Location.hpp"
#include "../entities/Date.hpp"

class GetWeather : public Intent {
    std::unique_ptr<Date> Dat;
    std::unique_ptr<Location> Loc;

    public:
        GetWeather(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;
        static std::string ID;
};

#endif