#ifndef GETFACT_H
#define GETFACT_H

#include <string>
#include "Intent.hpp"

class GetFact : public Intent {
    public:
        static std::string ID;

        GetFact(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;
        std::string execute() override;
        virtual ~GetFact();
};

#endif