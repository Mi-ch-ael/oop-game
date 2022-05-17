#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <QDebug>

#include "src/defines.h"
#include "src/Observer/Publisher/ipublisher.h"

class IGameObject
{
public:
    virtual ~IGameObject();
    virtual int getGraph() const = 0;
    friend std::ostream& operator<<(std::ostream& out, const IGameObject& obj);
    friend QDebug operator<< (QDebug out, const IGameObject& player);
};

#endif // IGAMEOBJECT_H
