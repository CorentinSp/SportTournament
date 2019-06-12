import QtQuick 2.0
import Sailfish.Silica 1.0
import TeamModel 1.0;
import "../delegate"

Page {
    Connections {

        target: teams
    }

    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Teams")
        }
        model: TeamModel { list: teams }
        delegate: DelegateTeam {  }
        VerticalScrollDecorator {}
    }
}
