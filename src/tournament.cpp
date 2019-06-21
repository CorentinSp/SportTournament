#include "tournament.hpp"

QUuid Tournament::getId() const
{
    return id;
}

Tournament::Tournament(QObject *parent) : QObject(parent)
{
    this->id.createUuid();
}
