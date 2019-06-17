import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property var team

    id: page

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
                    team.name = name.text;
                    pageStack.pop();
                }
            }
        }

    }
}
