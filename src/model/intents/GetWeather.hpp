#ifndef GETWEATHER_H
#define GETWEATHER_H

#include "Intent.hpp"


class GetWeather : public Intent {

    public:
        GetWeather(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;

        static std::string ID;
        std::string execute() override;
        virtual ~GetWeather();
};

#endif