#ifndef NONE_H
#define NONE_H

#include "Intent.hpp"


class None : public Intent {
    public:
        None(const std::map<std::string, std::string>& entitiesConfigurations);
        static std::string ID;
        const std::string Name() override;
        std::string execute() override;
};

#endif
