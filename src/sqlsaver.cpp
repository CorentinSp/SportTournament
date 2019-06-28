#include "sqlsaver.hpp"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "teamlist.hpp"

SQLSaver::SQLSaver(QObject *parent, const QString path) : QObject(parent)
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
    query.prepare("INSERT INTO tournament (id) VALUES (:id);");
    query.bindValue(":id", tournament->getId());
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

bool SQLSaver::updateTeam(QString oldVal, Team *team)
{
    bool success = false;
    QSqlQuery query;
    qDebug()<< "JE SUIS DANS LE UPDATE, TEAM.NAME   "<< team->name();
    query.prepare("UPDATE Team SET name = :name where name = :oldval;");
    query.bindValue(":name", team->name());
    query.bindValue(":oldval", oldVal);
    if(query.exec())
    {
        success = true;

    }
    else
    {
        qDebug() << "updateTeam error:  "
                 << query.lastError();
    }

    return success;
}

bool SQLSaver::insertNewTeam(Team *team)
{
    bool success = false;
    QSqlQuery query;
    qDebug()<< "JE SUIS DANS LE INSERT, TEAM.NAME   "<< team->name();
    query.prepare("INSERT INTO Team (name) VALUES (:name);");
    query.bindValue(":name", team->name());
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addNewTeam error:  "
                 << query.lastError();
    }

    return success;
}

bool SQLSaver::deleteTeam(QString nom)
{
    bool success = false;
    QSqlQuery query;
    qDebug()<< "JE SUIS DANS LE DELETE, TEAM.NAME   "<< nom;
    query.prepare("DELETE FROM Team Where name = :name;");
    query.bindValue(":name", nom);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Delete error:  "
                 << query.lastError();
    }

    return success;
}

TeamList* SQLSaver::selectTeams()
{
    TeamList* listteam = new TeamList();
    bool success = false;
    QSqlQuery query;
    qDebug()<< "JE SUIS DANS LE SELECT "<<endl;
    query.prepare("SELECT name FROM Team;");
    if(query.exec())
    {
        while (query.next()) {
            listteam->append(new Team(query.value(0).toString()));
            qDebug() << "VALEUR DU SELECT / "<< query.value(0).toString() <<endl;
        }
        success = true;
    }
    else
    {
        qDebug() << "Select error:  "
                 << query.lastError();
    }

    return listteam;
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
    query.prepare("CREATE TABLE Team (id INTEGER PRIMARY KEY NOT NULL, name CHAR(100) NOT NULL);");
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
