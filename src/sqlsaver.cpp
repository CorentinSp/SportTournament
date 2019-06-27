#include "sqlsaver.hpp"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
SQLSaver::SQLSaver(const QString path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail CAUSE : "<< m_db.lastError();
    }
    else
    {
        qDebug() << "Database: connection ok";
        createTables();
    }
}

bool SQLSaver::insertNewTournament(Tournament* tournament)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO tournament (id) VALUES (:tournament->getId());");
    query.bindValue(":tournament->getId()", tournament->getId());
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addNewTournament error:  "
                 << query.lastError();
    }

    return success;
}

bool SQLSaver::insertNewTeam(const Team &team)
{
    bool success = false;
    QSqlQuery query;
    qDebug()<< "JE SUIS DANS LE INSERT, TEAM.NAME   "<< team.name();
    query.prepare("INSERT INTO Team VALUES (:team.name());");
    query.bindValue(":team->name()", team.name());
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addNewTournament error:  "
                 << query.lastError();
    }

    return success;
}

bool SQLSaver::selectTeam()
{
    bool success = false;
    QSqlQuery query;
    qDebug()<< "JE SUIS DANS LE SELECT "<<endl;
    query.prepare("SELECT * FROM Team;");
    if(query.exec())
    {
        query.next();
        qDebug() << "VALEUR DU SELECT / "<< query.value(1) <<endl;
        success = true;
    }
    else
    {
        qDebug() << "addNewTournament error:  "
                 << query.lastError();
    }

    return success;
}

bool SQLSaver::createTables()
{
    bool success = false;
    qDebug() << " DANS LE CREATE " << endl;
    QSqlQuery query;
    query.prepare("CREATE TABLE Tournament (id CHAR(100) PRIMARY KEY NOT NULL);");
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "createTables error:  "
                 << query.lastError();
    }
    query.clear();
    query.prepare("CREATE TABLE Team (name CHAR(100) PRIMARY KEY NOT NULL);");
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "createTables error:  "
                 << query.lastError();
    }
    return success;
}
