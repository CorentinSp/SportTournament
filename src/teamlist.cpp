#include "teamlist.hpp"

TeamList::TeamList(QObject *parent) : QObject(parent)
{

}

void TeamList::append(Team *team)
{
    emit preItemAppended();
    int position = count();
    connect(team, &Team::teamChanged, this, [=](){ emit TeamList::itemChanged( position ); } );
    m_teams.append(team);
    emit teamsChanged();
    emit postItemAppended();
}

Team *TeamList::at(int place) const
{
    return m_teams.at(place);
}

int TeamList::count() const
{
    return m_teams.count();
}

void TeamList::createTeam(QString name)
{
    Team* team = new Team(name);
    append( team);
    emit newTeamAppended(team);

}

void TeamList::removeTeam(int position)
{
    emit preItemRemoved(position);

    // No longer care for the file change
    disconnect ( m_teams[position], &Team::teamChanged, this, 0);

    m_teams.removeAt(position);

    // Reconnect to good positions
    for ( ; position < count() ; ++position ) {
        disconnect ( m_teams[position], &Team::teamChanged, this, 0);
        connect( m_teams[position], &Team::teamChanged, this, [=](){ emit TeamList::itemChanged( position ); } );
    }
    emit postItemRemoved();
}
