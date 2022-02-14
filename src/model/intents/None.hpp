#ifndef NONE_H
#define NONE_H

#include "Intent.hpp"


class None : public Intent {
    public:
        static std::string ID;

        None(const std::map<std::string, std::string>& entitiesConfigurations);
        const std::string Name() override;
        std::string execute() override;
        virtual ~None();
};

#endif
