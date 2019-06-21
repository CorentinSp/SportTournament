import QtQuick 2.0
import Sailfish.Silica 1.0
import TeamModel 1.0;
import "../delegate"

Page {
    id: page
    Connections {

        target: teams
    }


    // The effective value will be restricted by ApplicationWindow.allowedOrientations

    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Teams")
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Add Element")
                onClicked: listView.model.newElement()
            }
        }
        model: TeamModel { list: teams }
        delegate: DelegateTeam { }
        VerticalScrollDecorator {}


    }
}
