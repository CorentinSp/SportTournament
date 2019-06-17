#include "match.hpp"

Match::Match(QObject *parent) : QObject(parent)
{

}

void Match::append(Team *team)
{
    emit preItemAppended();
    int position = count();
    connect(team, &Team::teamChanged, this, [=](){ emit Match::matchChanged(position); } );
    m_participants.append(team);
    emit postItemAppended();
}

Team *Match::at(int place) const
{
    return m_participants.at(place);
}

int Match::count() const
{
    return m_participants.count();
}

void Match::removeParticipant(int position)
{
    emit preItemRemoved(position);

    // No longer care for the file change
    disconnect ( m_participants[position], &Team::teamChanged, this, 0);

    m_participants.removeAt(position);

    // Reconnect to good positions
    for ( ; position < count() ; ++position ) {
        disconnect ( m_participants[position], &Team::teamChanged, this, 0);
        connect( m_participants[position], &Team::teamChanged, this, [=](){ emit Match::matchChanged(position); } );
    }
    emit postItemRemoved();
}
