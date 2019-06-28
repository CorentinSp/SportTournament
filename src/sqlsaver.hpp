#ifndef SQLSAVER_HPP
#define SQLSAVER_HPP

#include <QSqlDatabase>
#include <QObject>
#include "tournament.hpp"
#include "team.hpp"
#include "teamlist.hpp"

class SQLSaver : public QObject
{
    Q_OBJECT
public:
    SQLSaver(QObject* parent, const QString path);

    bool insertNewTournament(Tournament* tournament);

    TeamList* selectTeams();
public slots:
    bool insertNewTeam(Team* team);
    bool deleteTeam(QString nom);
    bool updateTeam(QString oldVal, Team* team);
private:
    bool createTables();
    QSqlDatabase m_db;


};

#endif // SQLSAVER_HPP
