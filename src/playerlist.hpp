#ifndef PLAYERLIST_HPP
#define PLAYERLIST_HPP

#include <QObject>
#include "player.hpp"
class PlayerList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Player*> players READ players WRITE setPlayers NOTIFY playersChanged)

    QList<Player*> m_players;

public:
    explicit PlayerList(QObject* parent = nullptr);

    void append(Player* player);
    Player *at(int place) const;
    int count() const;
    void createPlayer(QString name);
    void removePlayer(int position);
    QList<Player*> players() const
    {
        return m_players;
    }

public slots:

    void setPlayers(QList<Player*> players)
    {
        if (m_players == players)
            return;

        m_players = players;
        emit playersChanged(m_players);
    }

signals:

    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);
    void newPlayerAppended(Player* player);
    void PlayersChanged();
    void playersChanged(QList<Player*> players);
};

#endif // PLAYERLIST_HPP
