#ifndef SQLSAVER_HPP
#define SQLSAVER_HPP

#include <QSqlDatabase>
#include "tournament.hpp"
#include "team.hpp"

class SQLSaver
{
public:
    SQLSaver(const QString path);
    
    bool insertNewTournament(Tournament* tournament);
    bool insertNewTeam(const Team& team);

    bool selectTeam();
private:
    bool createTables();
    QSqlDatabase m_db;
};

#endif // SQLSAVER_HPP
