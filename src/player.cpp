#include "player.hpp"

Player::Player(QString name, QObject *parent) : QObject(parent), m_name(name)
{
    connect(this, &Player::nameChanged, this, &Player::playerChanged);
}
