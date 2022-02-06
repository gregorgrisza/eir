#ifndef NONE_H
#define NONE_H

#include "Intent.hpp"

class None : public Intent {
    public:
        static std::string ID;
        const std::string Name() override;
};

#endif
