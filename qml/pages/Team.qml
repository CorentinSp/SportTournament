import QtQuick 2.0
import Sailfish.Silica 1.0
import "../delegate"
Page {
    property var team

    id: page
    Connections {
        target: db
    }

    SilicaFlickable {
        anchors.fill: parent

        PageHeader {
            id: header
            title: team.name
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Modifier l'équipe")
            }
        }

        Column {
            anchors.top: header.bottom
            width: page.width

            TextField {
                id: name
                label: qsTr("Nom")
                text: team.name
                width: page.width / 2
            }

            Button {
                text: qsTr("Valider")
                onClicked: function() {
                    var oldVal = team.name
                    team.name = name.text;
                    db.updateTeam(oldVal, team);
                    pageStack.pop();
                }
            }
            SilicaListView {
                id: listView
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.bottom: parent.bottom

                model: team.players
                delegate: DelegatePlayer {  }
                VerticalScrollDecorator {}
            }
        }

    }
}
