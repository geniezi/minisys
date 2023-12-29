#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "highlighttype.h"
#include <map>
#include "highlighter.h"
#include <QJsonObject>
#include "projectentity.h"
#include "filemanager.h"
#include "editor.h"
#include "project.h"
#include <QPushButton>
#include <QSignalMapper>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

     void on_actionNew_Project_triggered();

     void on_actionSetting_triggered();

     void on_actionOpen_Project_triggered();

     void on_textEdit_textChanged();

     void on_treeViewProject_clicked(const QModelIndex &index);

     void onTopClicked(QString index);
     void on_actionAbout_triggered();
     void on_actionSave_triggered();
     void on_actionOpenFile_triggered();
     void on_actionOpenFolder_triggered();
     void on_actionNewFile_triggered();
     void on_actionRun_triggered();
     void on_actionCompiler_triggered();
     void on_tabWidget_2_currentChanged(int index);
     void on_actionExit_2_triggered();
private:
    Ui::MainWindow *ui;

    std::map<QString,HighLightType> codeTable;
    std::map<HighLightType,QColor>* codeColor;
    std::map<int,std::map<HighLightType,std::map<int,int>>>* allHighLightTable;

     Highlighter* highlighter;

    void initUi();

    void  setupEditor();

    void renderTitle(QString file);

    QPushButton* editorTop[9];

    QJsonObject projectOBJ;
    ProjectEntity project;

    Project* pp;

    FileManager fileManager;
    EditorManager editorManager;
    QString projectPath = "";
    bool hasOpenFile;
    QString currentFilePath;
    QString currentFileName;
    QSignalMapper *signalMapper = new QSignalMapper(this);



    void EditAddFileTitle(QString filename);

    QString fileIndex = "";

    int topIndex = 0;


};

#endif // MAINWINDOW_H
