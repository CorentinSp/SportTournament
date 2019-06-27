#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <QObject>
#include <QList>
#include <QUuid>

#include "match.hpp"
#include "team.hpp"

class Tournament : public QObject
{
    Q_OBJECT
    QList<Match*> m_matchs;

    QList<Team*> m_teams;

    QUuid id;

public:
    explicit Tournament(QObject *parent = nullptr);
    Q_PROPERTY(QList<Match*> matchs READ matchs WRITE setMatchs NOTIFY matchsChanged)
    Q_PROPERTY(QList<Team*> teams READ teams WRITE setTeams NOTIFY teamsChanged)

    QList<Match*> matchs() const
    {
        return m_matchs;
    }

    QList<Team*> teams() const
    {
        return m_teams;
    }

    QString getId() const;

signals:

    void matchsChanged(QList<Match*> matchs);

    void teamsChanged(QList<Team*> teams);

public slots:
    void setMatchs(QList<Match*> matchs)
    {
        if (m_matchs == matchs)
            return;

        m_matchs = matchs;
        emit matchsChanged(m_matchs);
    }
    void setTeams(QList<Team*> teams)
    {
        if (m_teams == teams)
            return;

        m_teams = teams;
        emit teamsChanged(m_teams);
    }
};

#endif // TOURNAMENT_HPP
