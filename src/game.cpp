#include "game.hpp"

Game::Game() : QObject()
{

}

void Game::append(Match *match)
{
    emit preItemAppended();
    int position = count();
    connect(match, &Match::matchChanged, this, [=](){ emit Game::itemChanged( position ); } );
    m_matchs.append(match);
    emit postItemAppended();
}

Match *Game::at(int place) const
{
    return m_matchs.at(place);
}

int Game::count() const
{
    return m_matchs.count();
}

void Game::removeMatch(int position)
{
    emit preItemRemoved(position);

    // No longer care for the file change
    disconnect ( m_matchs[position], &Match::matchChanged, this, 0);

    m_matchs.removeAt(position);

    // Reconnect to good positions
    for ( ; position < count() ; ++position ) {
        disconnect ( m_matchs[position], &Match::matchChanged, this, 0);
        connect( m_matchs[position], &Match::matchChanged, this, [=](){ emit Game::itemChanged( position ); } );
    }
    emit postItemRemoved();
}
