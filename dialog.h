#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qdebug.h"
#include "QString"
#include "QStringListModel"
#include "QStringList"
#include "QListView"
#include "QTreeView"
#include "QTableView"
#include "QLabel"
#include "QPushButton"
#include "QInputDialog"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:

    void otvorenprozor();
    void dodavanje();
    void brisanje();

private:
    Ui::Dialog *ui;

    QStringListModel model;
    QStringList lista;
    QModelIndex index;

    QDialog *listViewDialog;
    QDialog *tableViewDialog;
    QDialog *treeViewDialog;

    QListView *listView;
    QTableView *tableView;
    QTreeView *treeView;

    QLabel *listViewLabel;
    QLabel *tableViewLabel;
    QLabel *treeViewLabel;

    QPushButton *addListView;
    QPushButton *removeListView;
    QPushButton *addTableView;
    QPushButton *removeTableView;
    QPushButton *addTreeView;
    QPushButton *removeTreeView;



};

#endif // DIALOG_H
