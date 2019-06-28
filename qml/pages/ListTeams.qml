import QtQuick 2.0
import Sailfish.Silica 1.0
import TeamModel 1.0
import "../delegate"
import TeamNameValidator 1.0

Page {
    Connections {
        target: teams
    }

    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaFlickable {

        anchors.fill: parent

        PageHeader {
            id: title
            title: qsTr("Teams")
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Ajouter une équipe")
                onClicked: function() {
                    txtName.forceActiveFocus()
                    createTeam.visible = true
                    listView.state = "Creation"
                }
            }
        }

        Column {
            id: createTeam
            visible: false
            width: parent.width
            anchors.top: title.bottom
            TextField {
                id: txtName
                width: parent.width / 2
                validator: TeamNameValidator { teams: listView.model.teamList.teams }
                EnterKey.onClicked: {
                    if(txtName.acceptableInput){
                        listView.model.newElement(txtName.text)
                        createTeam.visible = false
                        listView.state = "Normal"
                        txtName.text = ""
                    }
                }
            }
            Label {
                text: "Nom invalide."
                visible: !txtName.acceptableInput
                color: "red"
            }
            Button {
                id: btnAnnuler
                text: qsTr("Annuler")
                onClicked: function() {
                    listView.state = "Normal"
                    txtName.text = ""
                    createTeam.visible = false
                }
            }
        }

        SilicaListView {
            id: listView
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            state: "Normal"

            states: [
                State {
                    name: "Normal"
                    AnchorChanges {
                        target: listView
                        anchors.top: title.bottom
                    }
                },
                State {
                    name: "Creation"
                    AnchorChanges {
                        target: listView
                        anchors.top: createTeam.bottom
                    }
                }
            ]

            model: TeamModel { teamList: teams }
            delegate: DelegateTeam {  }
            VerticalScrollDecorator {}
        }
    }
}
