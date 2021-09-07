#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    listViewDialog = new QDialog(this);
    tableViewDialog = new QDialog(this);
    treeViewDialog = new QDialog(this);

    listView = new QListView(listViewDialog);
    tableView = new QTableView(tableViewDialog);
    treeView = new QTreeView(treeViewDialog);

    listViewDialog->setGeometry(1140,110,400,250);
    listView->setGeometry(10,35,350,140);
    listViewDialog->setWindowTitle("Dialog");

    treeViewDialog->setGeometry(1140,410,400,250);
    treeView->setGeometry(10,35,350,140);
    treeViewDialog->setWindowTitle("Dialog");

    tableViewDialog->setGeometry(1140,710,400,250);
    tableView->setGeometry(10,35,350,140);
    tableViewDialog->setWindowTitle("Dialog");

    //Definisanje Label-a
    listViewLabel = new QLabel(listViewDialog);
    listViewLabel->setText("ListView");
    listViewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
    listViewLabel->setGeometry(10,5,130,30);

    treeViewLabel = new QLabel(treeViewDialog);
    treeViewLabel->setText("TreeView");
    treeViewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
    treeViewLabel->setGeometry(10,5,130,30);

    tableViewLabel = new QLabel(tableViewDialog);
    tableViewLabel->setText("TableView");
    tableViewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
    tableViewLabel->setGeometry(10,5,130,30);

    //Konektovanje buttona sa prozorom
    connect(ui->listView_button,QPushButton::clicked,this,&Dialog::otvorenprozor);
    connect(ui->tableView_button,QPushButton::clicked,this,&Dialog::otvorenprozor);
    connect(ui->treeView_button,QPushButton::clicked,this,&Dialog::otvorenprozor);

    //Dodavanje buttona add i delete
    addListView = new QPushButton(listViewDialog);
    addListView->setText("Add");
    addListView->setGeometry(70,190,75,30);
    QObject::connect(addListView, SIGNAL(clicked()),this, SLOT(dodavanje()));

    removeListView = new QPushButton(listViewDialog);
    removeListView->setText("Remove");
    removeListView->setGeometry(230,190,75,30);
    removeListView->setObjectName("RemoveListView");
    QObject::connect(removeListView, SIGNAL(clicked()),this, SLOT(brisanje()));

    addTableView = new QPushButton(tableViewDialog);
    addTableView->setText("Add");
    addTableView->setGeometry(70,190,75,30);
    QObject::connect(addTableView, SIGNAL(clicked()),this, SLOT(dodavanje()));

    removeTableView = new QPushButton(tableViewDialog);
    removeTableView->setText("Remove");
    removeTableView->setGeometry(230,190,75,30);
    removeTableView->setObjectName("RemoveTableView");
    QObject::connect(removeTableView, SIGNAL(clicked()),this, SLOT(brisanje()));

    addTreeView = new QPushButton(treeViewDialog);
    addTreeView->setText("Add");
    addTreeView->setGeometry(70,190,75,30);
    QObject::connect(addTreeView, SIGNAL(clicked()),this, SLOT(dodavanje()));

    removeTreeView = new QPushButton(treeViewDialog);
    removeTreeView->setText("Remove");
    removeTreeView->setGeometry(230,190,75,30);
    removeTreeView->setObjectName("RemoveTreeView");
    QObject::connect(removeTreeView, SIGNAL(clicked()),this, SLOT(brisanje()));

    //Lista
    lista << "Azra Dzinovic" << "Kemal Gogic" << "Emir Morankic" << "Niko Tin Sablic" << "Nedina Omerovic" << "Izet Jahic" << "Sejla Sakovic" << "Djordje Djuric" << "Dzeneta Gutic" << "Berina Mrkonjic" << "Nermina Zukic";
    model.setStringList(lista);
    //Ubacivanje u prozor
    listView->setModel(&model);
    tableView->setModel(&model);
    treeView->setModel(&model);

    //Pozicioniranje elemenata u prozoru
    QGridLayout *gridListView = new QGridLayout(listViewDialog);
    gridListView->addWidget(listViewLabel,0,0,1,1);
    gridListView->addWidget(listView,1,0,1,0);
    gridListView->addWidget(addListView,2,0,1,1);
    gridListView->addWidget(removeListView,2,1,1,1);
    listViewDialog->setLayout(gridListView);

    QGridLayout *gridTableView = new QGridLayout(tableViewDialog);
    gridTableView->addWidget(tableViewLabel,0,0,1,1);
    gridTableView->addWidget(tableView,1,0,1,0);
    gridTableView->addWidget(addTableView,2,0,1,1);
    gridTableView->addWidget(removeTableView,2,1,1,1);
    tableViewDialog->setLayout(gridTableView);

    QGridLayout *gridTreeView = new QGridLayout(treeViewDialog);
    gridTreeView->addWidget(treeViewLabel,0,0,1,1);
    gridTreeView->addWidget(treeView,1,0,1,0);
    gridTreeView->addWidget(addTreeView,2,0,1,1);
    gridTreeView->addWidget(removeTreeView,2,1,1,1);
    treeViewDialog->setLayout(gridTreeView);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dodavanje() {

    int row=model.rowCount();
    model.insertRows(row,1);
    index=model.index(row);

    listView->setCurrentIndex(index);
    listView->edit(index);

    treeView->setCurrentIndex(index);
    treeView->edit(index);

    tableView->setCurrentIndex(index);
    tableView->edit(index);
}


void Dialog::brisanje() {

QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="RemoveListView") {
        QModelIndex index= listView->currentIndex();
        model.removeRow(index.row());
        }
    if (button->objectName()=="RemoveTableView") {
        QModelIndex index= tableView->currentIndex();
        model.removeRow(index.row());
        }
    if (button->objectName()=="RemoveTreeView") {
        QModelIndex index= treeView->currentIndex();
        model.removeRow(index.row());
        }
}

void Dialog::otvorenprozor () {

QPushButton *button = qobject_cast<QPushButton*>(sender());

    if(button->text()=="ListView") {
        listViewDialog->setVisible(true);
        }
    if(button->text()=="TableView") {
        tableViewDialog->setVisible(true);
        }
    if(button->text()=="TreeView") {
        treeViewDialog->setVisible(true);
        }
}


