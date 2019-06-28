#include "playerlist.hpp"

PlayerList::PlayerList(QObject *parent) : QObject(parent)
{

}

void PlayerList::append(Player *player)
{
    emit preItemAppended();
    int position = count();
    connect(player, &Player::playerChanged, this, [=](){ emit PlayerList::itemChanged( position ); } );
    m_players.append(player);
    emit PlayersChanged();
    emit postItemAppended();
}

Player *PlayerList::at(int place) const
{
    return m_players.at(place);
}

int PlayerList::count() const
{
    return m_players.count();
}

void PlayerList::createPlayer(QString name)
{
    Player* player = new Player(name);
    append( player);
    emit newPlayerAppended(player);

}

void PlayerList::removePlayer(int position)
{
    emit preItemRemoved(position);

    // No longer care for the file change
    disconnect ( m_players[position], &Player::playerChanged, this, 0);

    m_players.removeAt(position);

    // Reconnect to good positions
    for ( ; position < count() ; ++position ) {
        disconnect ( m_players[position], &Player::playerChanged, this, 0);
        connect( m_players[position], &Player::playerChanged, this, [=](){ emit PlayerList::itemChanged( position ); } );
    }
    emit postItemRemoved();
}
