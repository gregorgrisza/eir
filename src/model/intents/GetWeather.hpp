#ifndef GETWEATHER_H
#define GETWEATHER_H

#include <memory>
#include "Intent.hpp"
#include "../entities/City.hpp"
#include "../entities/Date.hpp"

class GetWeather : public Intent {

    public:
        GetWeather(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;

        static std::string ID;
        std::string execute() override;
};

#endif