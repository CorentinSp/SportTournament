#include "team.hpp"

Team::Team(QString name, QObject *parent) : QObject(parent), m_name(name)
{
    connect(this, &Team::nameChanged, this, &Team::teamChanged);
}
