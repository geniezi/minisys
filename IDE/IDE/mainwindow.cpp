#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDirModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include "newprojectwindow.h"
#include "settingwindow.h"
#include <QDebug>
#include "filehelper.h"
#include <QJsonObject>
#include "jsonhelper.h"
#include "project.h"
#include <QSpacerItem>
#include <QSignalMapper>
#include <QtCore>
#include <QtGui>
#include "generalproject.h"
QLabel *q;
QPushButton *tor;
void MainWindow::initUi(){

    ui->setupUi(this);
    q = new QLabel("Col:  Row: ");
    this->statusBar()->addWidget(q);

    tor = new QPushButton("");
    tor->setIcon(QIcon(":/icon/tor.png"));
    tor->setStyleSheet("color:white;border:none;background:rgba(51, 51, 51,0);");
    this->statusBar()->addWidget(tor);

    QFile qssfile(":/styles/base.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();


    //setWindowIcon(QIcon("logo.ico"));
    // this->setStyleSheet(qss);
    this->ui->textEdit->setReadOnly(true);
    this->setupEditor();


}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initUi();
    this->hasOpenFile=false;
    this->currentFilePath="";
    this->currentFileName="";
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(20);

    ui->textEdit->setFont(font);

    highlighter = new Highlighter(ui->textEdit->document());

    for(int i = 0;i<9;i++){
        QPushButton* editorTopB = new QPushButton("");
        editorTopB->setStyleSheet("background:rgba(0, 128, 255,0);color:rgb(255, 255, 255);width:100px;border:none;margin:0;padding:4px;margin-left:1px;");
        this->editorTop[i] = editorTopB;
        connect(editorTop[i], SIGNAL(clicked()), this->signalMapper, SLOT(map()));
    }
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onTopClicked(QString)));
    this->editorTop[0]->setStyleSheet("background:rgb(0, 128, 255);color:rgb(255, 255, 255);width:100x;border:none;margin:0;padding:4px;margin-left:1px;");
    this->editorTop[0]->setText("欢迎页");
    for (int i = 0;i<9;i++){
        this->ui->edit_title->addWidget(editorTop[i]);
    }

}

void MainWindow::on_actionNew_Project_triggered()
{
    NewProjectWindow newProjectWindow;
    newProjectWindow.show();
    newProjectWindow.exec();
}

void MainWindow::on_actionSetting_triggered()
{
    SettingWindow setting;
    setting.show();
    setting.exec();
}
void MainWindow::on_actionSave_triggered()
{
    if(this->hasOpenFile){
    QString filename=QFileDialog::getSaveFileName(this,tr("选择保存路径"),"Untitled","C File(*.c);;C++ File(*.cpp)");
            if(filename.isEmpty())
            {
                QMessageBox::information(this,"提示","文件路径不能为空");
                return;
            }
            else
            {
                QFile file(filename);//创建文件对象
                QString text = ui->textEdit->toPlainText();
//                ui->textEdit->insertPlainText(text +='\n');
                qDebug() << file.isOpen();//新增部分
                qDebug() << file.open(QIODevice::ReadWrite);
                qDebug()<<text;
                file.write(text.toUtf8());//将text内容转化为字节数组

                file.close();
                QStringList name_ls=filename.split("/");
                QString name=name_ls.back();
                qDebug()<<name;
                this->currentFileName=name;
                this->currentFilePath=filename;
                this->editorTop[0]->setText(this->currentFileName);

            }
     }
    else{
        QMessageBox::information(this,"提示","请先新建文件");
        return;
    }
}

void MainWindow::on_actionOpenFile_triggered()
{
    if(this->hasOpenFile){
        if(QMessageBox::Yes==  QMessageBox::question(this,"提示","打开新的文件前是否保存当前文件？"))
           {
            QString filename=QFileDialog::getSaveFileName(this,tr("选择保存路径"),"Untitled",tr("C File(*.c);;C++ File(*.cpp)"));
                    if(filename.isEmpty())
                    {
                        QMessageBox::information(this,"提示","文件路径不能为空");
                        return;
                    }
                    else
                    {
                        QFile file(filename);//创建文件对象
                        QString text = ui->textEdit->toPlainText();
        //                ui->textEdit->insertPlainText(text +='\n');
//                        qDebug() << file.isOpen();//新增部分
//                        qDebug() << file.open(QIODevice::ReadWrite);
                        file.write(text.toUtf8());//将text内容转化为字节数组

                        file.close();
                        QStringList name_ls=filename.split("/");
                        QString name=name_ls.back();
                        this->currentFileName=name;
                        this->currentFilePath=filename;
                    }
                    filename = QFileDialog::getOpenFileName(this, " 选择需要打开的文件 " , "" , " *.c *.cpp" );

                     //读取文件
                       QFile newfile(filename);//构建文件对象，对文件做相关操作
                       bool tag = newfile.open(QIODevice::ReadOnly);//只读方式打开文件
                       if(!tag)
                       {
                           QMessageBox::information(this,"提示","文件打开失败");
                           return;//文件打开失败
                       }

                       //创建数据流对象
                        QByteArray array =  newfile.readAll();
                       this->ui->textEdit->setText(QString(array));
                       QStringList name_ls=filename.split("/");
                       QString name=name_ls.back();
                       this->currentFileName=name;
                       this->currentFilePath=filename;
                       this->editorTop[0]->setText(this->currentFileName);
                       newfile.close();
           }
        else
        {
            QString filename = QFileDialog::getOpenFileName(this, " 选择需要打开的文件 " , "" , " *.c *.cpp" );

             //读取文件
               QFile file(filename);//构建文件对象，对文件做相关操作
               bool tag = file.open(QIODevice::ReadOnly);//只读方式打开文件
               if(!tag)
               {
                   QMessageBox::information(this,"提示","文件打开失败");
                   return;//文件打开失败
               }

               //创建数据流对象
               QByteArray array =file.readAll();
              this->ui->textEdit->setText(QString(array));
               QStringList name_ls=filename.split("/");
               QString name=name_ls.back();
               this->currentFileName=name;
               this->currentFilePath=filename;
               this->editorTop[0]->setText(this->currentFileName);
               file.close();
        }

    }
    else{
        QString filename = QFileDialog::getOpenFileName(this, " 选择需要打开的文件 " , "" , " *.c *.cpp" );

         //读取文件
           QFile file(filename);//构建文件对象，对文件做相关操作
           bool tag = file.open(QIODevice::ReadOnly);//只读方式打开文件
           if(!tag)
           {
               QMessageBox::information(this,"提示","文件打开失败");
               return;//文件打开失败
           }

           //创建数据流对象
           this->ui->textEdit->setReadOnly(false);
           QByteArray array =file.readAll();
          this->ui->textEdit->setText(QString(array));

           QStringList name_ls=filename.split("/");
           QString name=name_ls.back();
           this->currentFileName=name;
           this->currentFilePath=filename;
           this->editorTop[0]->setText(this->currentFileName);
           this->hasOpenFile=true;
           file.close();
    }
}

void MainWindow::on_actionOpen_Project_triggered()
{
    QFileDialog projectDialog;
    QString path = projectDialog.getOpenFileName(this, tr("Open Nide project"), ".", tr("Nide project Files(*.nproj)"));
    if(path.length() != 0) {
        QFile file(path);
        FileHelper fileHelper;
        JsonHelper jsonHelper;
        QString buffer =  fileHelper.loadFileToString(path);
        this->projectOBJ = jsonHelper.getJsonObjectFromString(buffer);

        this->pp =  new Project(this->projectOBJ);
        this->ui->projectName->setText(this->pp->getProjectName());
        this->ui->listView_undo->setModel(this->pp->getTaskUndo());
        this->ui->listView_doing->setModel(this->pp->getTaskDoing());
        this->ui->listView_done->setModel(this->pp->getTaskDone());
        this->ui->treeViewProject->setModel(this->pp->getProjectTree());



        this->projectPath = QFileInfo(path).absolutePath()+"/";
        projectDialog.close();

    }

}

int num = 0;
void MainWindow::on_textEdit_textChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    int ColNum = cursor.columnNumber();
    int RowNum = cursor.blockNumber();
    QString bottomS = "Col: "+QString::number(ColNum,10)+" Row: "+QString::number(RowNum,10);
    for(int i = 0;i<ColNum;i++){
        bottomS+="   ";
    }

    if(num == 1){
        tor->setIcon(QIcon(":/icon/tor_run.png"));
        num = 0;
    }else{
        tor->setIcon(QIcon(":/icon/tor.png"));
        num++;
    }

    q->setText(bottomS);
}
void MainWindow::EditAddFileTitle(QString filename){
    if(!this->editorManager.isFileOpened(filename,this->projectPath)){
        QPushButton* push = new QPushButton(filename);
        push->setStyleSheet("background:rgb(0, 128, 255);color:rgb(255, 255, 255);border:none;width:100px;margin:0;padding:4px;margin-left:1px;");
        this->ui->edit_title->addWidget(push,0);
    }
}


void MainWindow::onTopClicked(QString index){


    if(this->fileIndex!=""){
        FileHelper filehelper;
        if(!filehelper.saveFile(this->projectPath+this->fileIndex,this->ui->textEdit->toPlainText())){
            this->ui->textBrowser_output->setText(this->ui->textBrowser_output->toPlainText()+"\n"+"文件"+this->projectPath+this->fileIndex+"保存失败");
        }else{
            if(!this->fileManager.updateFileBuffer(this->fileIndex,this->ui->textEdit->toPlainText())){
                this->ui->textBrowser_output->setText(this->ui->textBrowser_output->toPlainText()+"\n"+"buffer"+this->projectPath+this->fileIndex+"更新失败");
            }
        }
        this->ui->textBrowser_output->setText(this->ui->textBrowser_output->toPlainText()+"\n"+"文件"+this->projectPath+this->fileIndex+"保存成功");

    }
    this->fileIndex = index;

    renderTitle(index);
    this->ui->textEdit->setText(fileManager.getBufferedFile(index,this->projectPath));
}

void MainWindow::on_actionAbout_triggered()
{

    QMessageBox msgBox;
      msgBox.setText("软件开发声明");
      msgBox.setInformativeText("本软件是用于东南大学计算机科学与工程学院CSE20计算机系统综合课程设计的IDE集成开发环境。\n如果你不幸用上了请勿向外流传！！！\n(运行过程中出现任何bug本人概不负责)");
      msgBox.setStandardButtons(QMessageBox::Yes);
      int ret = msgBox.exec();
}

void MainWindow::renderTitle(QString file){
    std::vector<QString> opened = this->editorManager.getOpenedFile();
    int finalcount = (opened.size()>=9 ? 9: opened.size());

    for(int i = 0; i<finalcount;i++){
        this->editorTop[i]->setText(opened.at(i));
        if(opened.at(i)==file){

            this->editorTop[i]->setStyleSheet("background:rgb(0, 128, 255);color:rgb(255, 255, 255);width:100px;border:none;margin:0;padding:4px;margin-left:1px;");
        }else{

            this->editorTop[i]->setStyleSheet("background:rgb(45, 45, 48);color:rgb(255, 255, 255);width:100px;border:none;margin:0;padding:4px;margin-left:1px;");
        }
        QString ff = editorTop[i]->text();
        this->signalMapper->setMapping(editorTop[i], ff);

    }

}


void MainWindow::on_treeViewProject_clicked(const QModelIndex &index)
{
    QString str;

    str = QStringLiteral("%1").arg(index.data().toString());

    if(str!="Sources"&&str!="Headers"){


        //this->EditAddFileTitle(str);
        this->editorManager.openFile(str,this->projectPath);
        if(this->fileIndex!=""){
            FileHelper filehelper;
            if(!filehelper.saveFile(this->projectPath+this->fileIndex,this->ui->textEdit->toPlainText())){
                this->ui->textBrowser_output->setText(this->ui->textBrowser_output->toPlainText()+"\n"+"文件"+this->projectPath+this->fileIndex+"保存失败");
            }else{
                if(!this->fileManager.updateFileBuffer(this->fileIndex,this->ui->textEdit->toPlainText())){
                    this->ui->textBrowser_output->setText(this->ui->textBrowser_output->toPlainText()+"\n"+"buffer"+this->projectPath+this->fileIndex+"更新失败");
                }
            }
            this->ui->textBrowser_output->setText(this->ui->textBrowser_output->toPlainText()+"\n"+"文件"+this->projectPath+this->fileIndex+"保存成功");
        }
        this->fileIndex = str;


        this->ui->textEdit->setFontPointSize(20);

        this->ui->textEdit->setText(fileManager.getBufferedFile(str,this->projectPath));
        if(this->projectPath!=""){
            this->ui->markList->setModel(this->pp->getMark(str));
        }
        renderTitle(str);

    }





}

void MainWindow::on_actionOpenFolder_triggered()
{
    QFileDialog projectDialog;
    QString path = projectDialog.getExistingDirectory(this,"打开目录","~/");
    if(path.length() != 0) {
        GeneralProject gen;
        this->ui->treeViewProject->setModel(gen.getCurrentForder(path));



    }
}
void MainWindow::on_actionNewFile_triggered()
{
//    this->ui->textEdit->append(QString("X轴角度:%1").arg(getDataangle(ACCEL_XOUT_H)));
//    this->ui->textEdit->append(QString("Y轴角度:%1").arg(getDataangle(ACCEL_YOUT_H)));
//    this->ui->textEdit->append(QString("Z轴角度:%1").arg(getDataangle(ACCEL_ZOUT_H)));
//    this->ui->textEdit->append(QString("X轴加速度:%1g").arg(getDataaccel(GYRO_XOUT_H)));
//    this->ui->textEdit->append(QString("Y轴加速度:%1g").arg(getDataaccel(GYRO_YOUT_H)));
//    this->ui->textEdit->append(QString("Z轴加速度:%1g").arg(getDataaccel(GYRO_ZOUT_H)));
//    this->ui->textEdit->append(QString("%1°C").arg(getDAtatemp(TEMP_OUT_H)));
//    this->ui->textEdit->append(" ");

    //创建成功
    if(!this->hasOpenFile)
    {
        this->ui->textEdit->setReadOnly(false);
        this->ui->textEdit->setText("");
        this->hasOpenFile=true;
        this->currentFileName="Untitled.c";
        this->editorTop[0]->setText(this->currentFileName);
    }
    else
    {
        int ret = QMessageBox::warning(this, tr("My IDE"),
                                        tr("当前文件已经发生更改.\n"
                                           "你是否想要保存现在的变更?"),
                                        QMessageBox::Save | QMessageBox::Discard
                                        | QMessageBox::Cancel,
                                        QMessageBox::Save);
        switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               break;
           case QMessageBox::Discard:
               // Don't Save was clicked
               this->ui->textEdit->setReadOnly(false);
               this->ui->textEdit->setText("");
               this->hasOpenFile=true;
               this->currentFileName="Untitled.c";
               this->editorTop[0]->setText(this->currentFileName);
               break;
           case QMessageBox::Cancel:
               // Cancel was clicked
               break;
           default:
               // should never be reached
               break;
         }
    }
}

void MainWindow::on_actionRun_triggered()
{
    if(this->hasOpenFile){
      if(this->currentFilePath.isEmpty())
    {
     QString filename=QFileDialog::getSaveFileName(this,tr("选择保存路径"),"Untitled",tr("C File(*.c);;C++ File(*.cpp)"));
                    if(filename.isEmpty())
                    {
                        QMessageBox::information(this,"提示","文件路径不能为空");
                        return;
                    }
                    else
                    {
                        QFile file(filename);//创建文件对象
                        QString text = ui->textEdit->toPlainText();
        //                ui->textEdit->insertPlainText(text +='\n');
//                        qDebug() << file.isOpen();//新增部分
//                        qDebug() << file.open(QIODevice::ReadWrite);
                        file.write(text.toUtf8());//将text内容转化为字节数组

                        file.close();
                        QStringList name_ls=filename.split("/");
                        QString name=name_ls.back();
                        this->currentFileName=name;
                        this->currentFilePath=filename;
                    }
    }
     else{
          QFile file(this->currentFilePath);//创建文件对象
          QString text = ui->textEdit->toPlainText();
//                ui->textEdit->insertPlainText(text +='\n');
//          qDebug() << file.isOpen();//新增部分
//          qDebug() << file.open(QIODevice::ReadWrite);
          file.write(text.toUtf8());//将text内容转化为字节数组

          file.close();

      }
    qDebug() <<"ccc"<< this->currentFilePath;
//    QString text = ui->textEdit->toPlainText();
//    QStringList  strs= text.split("#include",QString::SkipEmptyParts);
//    QStringList  cList;
    QStringList  asmList;
    QString str = QApplication::applicationDirPath();
//    qDebug() << str;
//    cList.append(this->currentFilePath);
//    int index=0;
//    asmList.append(str+"/asm_out/result"+QString::number(index)+ ".asm");
//    index++;


//    for (int i = 0;i < strs.size();i ++)
//    {
//        if(i+1!=strs.size())
//        {

//           QString s = strs[i].simplified();
//           if(s.isEmpty())continue;
//           qDebug() << s;
//           s.remove(QRegExp("^\\\""));
//           s.remove(QRegExp("\\\"$"));
//           QDir temDir(s);
//           QString absDir = temDir.absolutePath();
//           cList.append(absDir);
//           qDebug() << absDir;
//           asmList.append(str+"/asm_out/result"+QString::number(index)+ ".asm");
//           index++;
//        }
//        else
//        {
//            QString s = strs[i].simplified();
//            s=s.split("\"",QString::SkipEmptyParts)[0];
//            if(s.isEmpty()||s[0]!="\"")
//            {
//                break;
//            }
//            else
//            {
//                s.replace(QRegExp("^\""), "");
//                s.replace(QRegExp("\\$"), "");
//                QDir temDir(s);
//                QString absDir = temDir.absolutePath();
//                cList.append(absDir);
//                qDebug() << absDir;
//                asmList.append(str+"/asm_out/result"+QString::number(index)+ ".asm");
//                index++;
//            }

//        }


//    }
    QProcess compiler;
    QDir c("../IDE/compiler/release/MyCompiler.exe");
    QString c_cmd = c.absolutePath();
//    c_cmd="../IDE/compiler/release/MyCompiler.exe";
    qDebug()<<c_cmd;
//    for(int i=0;i<index;i++)
//    {

//        QStringList c_args;
//        c_args.append(cList[i]);
//        c_args.append(asmList[i]);
//        qDebug() << c_cmd;
//        qDebug()<<c_args;
//        compiler.start(c_cmd,c_args);
//        compiler.waitForFinished();
//        qDebug() << "编译执行："<<i;
//    }
    QStringList c_args;
    qDebug()<<this->currentFilePath;
    c_args.append(this->currentFilePath);
    QDir ad("../asm_result/");
    QString asmDir = ad.absolutePath();
    qDebug() << asmDir;
    c_args.append(asmDir);
    compiler.start(c_cmd,c_args);
    compiler.waitForFinished();
    qDebug() << "编译执行";




    ad.setFilter(QDir::Files);
    ad.setSorting(QDir::Name);
    QStringList filter;
    filter.append("*.asm");
    ad.setNameFilters(filter);
    asmList = ad.entryList();

//    for(int i=0;i<asmList.size();i++)
//    {
//        qDebug()<<asmDir+"/"+asmList[i];
//    }


//    return ;

    QProcess assembler;
//    QString a_cmd = str+"/assembler/dist/assembler/assembler.exe";
    QDir a("../IDE/assembler/dist/assembler/assembler.exe");
    QString a_cmd = a.absolutePath();
    qDebug() << "编译执行："<<a_cmd;
    QStringList a_args;
    for(int i=0;i<asmList.size();i++)
    {
        a_args.append(asmDir+"/"+asmList[i]);
    }
    QDir res("../coe_result/");
    QString resDir = res.absolutePath();
    a_args.append(resDir);
    assembler.start(a_cmd,a_args);
    assembler.waitForFinished();




    //删除所有的asm中间文件
    QDir m_dir(asmDir);
     if(m_dir.isEmpty())
     {
         qDebug() << "临时文件文件夹" << asmDir << "为空";
         m_dir.removeRecursively();
         return;
     }

     // 第三个参数是QDir的过滤参数，这三个表示收集所有文件和目录，且不包含"."和".."目录。
     // 因为只需要遍历第一层即可，所以第四个参数填QDirIterator::NoIteratorFlags
     QDirIterator DirsIterator(asmDir, QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);
     while(DirsIterator.hasNext())
     {
         if (!m_dir.remove(DirsIterator.next())) // 删除文件操作如果返回否，那它就是目录
         {
             QDir(DirsIterator.filePath()).removeRecursively(); // 删除目录本身以及它下属所有的文件及目录
         }
     }

     m_dir.removeRecursively();


    //显示log
     QDir d("../IDE/compiler/release/MyCompiler.log");
     QString filename = d.absolutePath();
     QFile newfile(filename);//构建文件对象，对文件做相关操作
     bool tag = newfile.open(QIODevice::ReadOnly);//只读方式打开文件
     if(!tag)
     {
         QMessageBox::information(this,"提示","文件打开失败");
         return;//文件打开失败
     }

     //创建数据流对象
      QByteArray array =  newfile.readAll();
      QString o_message(array);
      QMessageBox::information(this,"提示信息",o_message);

   }
    return;
}

void MainWindow::on_actionCompiler_triggered()
{

}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{

}

void MainWindow::on_actionExit_2_triggered()
{
    if(QMessageBox::Yes==  QMessageBox::question(this,"提示","确认退出？"))
        this->close();
}

