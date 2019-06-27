# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = SportTournament

CONFIG += sailfishapp

SOURCES += src/SportTournament.cpp \
    src/tournament.cpp \
    src/game.cpp \
    src/match.cpp \
    src/team.cpp \
    src/teamlist.cpp \
    src/teammodel.cpp \
    src/teamnamevalidator.cpp \
    src/sqlsaver.cpp
DISTFILES += qml/SportTournament.qml \
    qml/cover/CoverPage.qml \
    rpm/SportTournament.changes.in \
    rpm/SportTournament.changes.run.in \
    rpm/SportTournament.spec \
    rpm/SportTournament.yaml \
    translations/*.ts \
    SportTournament.desktop \
    qml/pages/ListTeams.qml \
    qml/pages/FirstPage.qml \
    qml/delegate/DelegateTeam.qml \
    qml/pages/Team.qml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

QT += sql

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/SportTournament-de.ts

HEADERS += \
    src/tournament.hpp \
    src/game.hpp \
    src/match.hpp \
    src/team.hpp \
    src/teamlist.hpp \
    src/teammodel.hpp \
    src/teamnamevalidator.h \
    src/sqlsaver.hpp
