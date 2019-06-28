#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "tournament.hpp"
#include "teammodel.hpp"
#include "team.hpp"
#include "teamlist.hpp"
#include "player.hpp"
#include "playerlist.hpp"
#include "playermodel.hpp"
#include "sqlsaver.hpp"
#include "teamnamevalidator.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/SportTournament.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).
    //Tournament tournament(0);
    QGuiApplication* app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();

    SQLSaver *db = new SQLSaver(nullptr, QDir::homePath()+ QDir::separator()+"sportTournament.db");
    TeamList* teams = db->selectTeams();
    qmlRegisterType<TeamModel>("TeamModel", 1, 0, "TeamModel" );
    qmlRegisterType<TeamNameValidator>("TeamNameValidator", 1, 0, "TeamNameValidator");
    qmlRegisterUncreatableType<TeamList>("TeamModel", 1, 0, "TeamList", QStringLiteral("Don't define TeamList in QML!!") );
    qmlRegisterUncreatableType<Team>("TeamModel", 1, 0, "Team", QStringLiteral("Don't define Team in QML!!") );

    qmlRegisterType<PlayerModel>("PlayerModel", 1, 0, "PlayerModel" );
    qmlRegisterUncreatableType<PlayerList>("PlayerModel", 1, 0, "PlayerList", QStringLiteral("Don't define PlayerList in QML!!") );
    qmlRegisterUncreatableType<Player>("PlayerModel", 1, 0, "Player", QStringLiteral("Don't define Player in QML!!") );

    //teams->at(0)->playerList()->append(new Player("Michel"));
    //teams->at(0)->playerList()->append(new Player("Ganon"));

    QObject::connect(teams, &TeamList::newTeamAppended, db, &SQLSaver::insertNewTeam);
    view->rootContext()->setContextProperty("teams", teams);
    view->rootContext()->setContextProperty("db", db);
    view->setSource(SailfishApp::pathTo("qml/SportTournament.qml"));
    view->show();


    return app->exec();
}
