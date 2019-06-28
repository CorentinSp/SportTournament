#ifndef TEAMLIST_HPP
#define TEAMLIST_HPP

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include "team.hpp"

class TeamList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Team*> teams READ teams NOTIFY teamsChanged )

private:
    QList<Team*> m_teams;

public:
    explicit TeamList(QObject *parent = nullptr);
    void append(Team* team);
    Team *at(int place) const;
    int count() const;
    void createTeam(QString name);
    void removeTeam(int position);

    QList<Team*> teams() const
    {
        return m_teams;
    }

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);
    void newTeamAppended(Team* team);
    void teamsChanged();
};

#endif // TEAMLIST_HPP
