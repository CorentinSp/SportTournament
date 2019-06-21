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


    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Teams")
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Add Element")
                onClicked: createTeam.visible = true
            }
        }
        model: TeamModel { teamList: teams }
        delegate: DelegateTeam {  }
        VerticalScrollDecorator {}
    }

    Item {
        id: createTeam
        visible: false
        width: listView.width
        TextField {
            id: txtName
            width: parent.width / 2
            validator: TeamNameValidator { teams: listView.model.teamList.teams }
            Keys.onEnterPressed: function() {
                if(txtName.acceptableInput){
                    listView.model.newElement(txtName.text)
                    createTeam.visible = false
                }
            }
        }
        Button {
            id: btnValider
            text: qsTr("Valider")
            enabled: txtName.text !== ""
            onClicked: listView.model.newElement(txtName.text)
        }
        Button {
            id: btnAnnuler
            text: qsTr("Annuler")
            anchors.left: btnValider.right
            onClicked: listView.model.removeRow(index)
        }
    }
}
