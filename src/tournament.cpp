#include "tournament.hpp"

QString Tournament::getId() const
{
    return id.toString();
}

Tournament::Tournament(QObject *parent) : QObject(parent)
{
    this->id.createUuid();
}
