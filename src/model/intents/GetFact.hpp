#ifndef GETFACT_H
#define GETFACT_H

#include "Intent.hpp"

class GetFact : public Intent {
    public:
        GetFact(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;
        static std::string ID;
};

#endif