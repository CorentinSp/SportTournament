#ifndef TEAM_H
#define TEAM_H

#include <QObject>
#include "playerlist.hpp"
class Team : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(PlayerList* playerList READ playerList WRITE setPlayerList NOTIFY playerListChanged)
    QString m_name;

    PlayerList* m_playerList;

public:
    Team(QString name, QObject* parent = nullptr);
    QString name() const
    {
        return m_name;
    }
    PlayerList* playerList() const
    {
        return m_playerList;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }
    void setPlayerList(PlayerList* playerList)
    {
        if (m_playerList == playerList)
            return;

        m_playerList = playerList;
        emit playerListChanged(m_playerList);
    }

signals:
    void nameChanged(QString name);
    void teamChanged();
    void playerListChanged(PlayerList* playerList);
};

#endif // TEAM_H
