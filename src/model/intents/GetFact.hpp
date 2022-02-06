#ifndef GETFACT_H
#define GETFACT_H

#include "Intent.hpp"

class GetFact : public Intent {
    public:
        const std::string Name() override;
        static std::string ID;
};

#endif