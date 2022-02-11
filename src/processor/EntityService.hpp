#ifndef ENTITYSERVICE_H
#define ENTITYSERVICE_H

template<class T>
class EntityService {
    public:
        virtual void getEntities(std::set<std::string> const& token, std::map<std::string, T>& entitiesConfigurations) = 0;
        virtual bool isEntity(std::string const& token) = 0;
};

#endif