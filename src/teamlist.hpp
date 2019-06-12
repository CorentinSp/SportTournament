#ifndef TEAMLIST_HPP
#define TEAMLIST_HPP

#include <QObject>
#include <QList>
#include "team.hpp"



class TeamList : public QObject
{
    Q_OBJECT
    QList<Team*> m_teams;
public:
    explicit TeamList(QObject *parent = nullptr);

    void append(Team* team);
    Team *at(int place) const;
    int count() const;
    void createTeam(QString name);
    void removeTeam(int position);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);
};

#endif // TEAMLIST_HPP
