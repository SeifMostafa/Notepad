#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QDebug>
#include <QColor>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit_Note);
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete ui->file_path;
}

void MainWindow::on_actionNew_triggered()
{
    file_path = "";
      ui->textEdit_Note->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
      QFile file(file_name);
      file_path = file_name;
      if(!file.open(QFile::ReadOnly | QFile::Text)) {
          QMessageBox::warning(this,"..","file can't be opened!");
          return;
        }
      QTextStream in(&file);
      QString text = in.readAll();
      ui->textEdit_Note->setText(text);
      file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
      if(!file.open(QFile::WriteOnly | QFile::Text)) {
          QMessageBox::warning(this,"..","file can't be saved!\nNote: if this is 1st time to save notes in a file,\nYou have to choose where to save it");
          return;
        }
      QTextStream out(&file);
      QString text = ui->textEdit_Note->toPlainText();
      out << text;
      file.flush();
      file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"choose file to be saved to");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file can't be saved!");
        return;
      }
    QTextStream out(&file);
    QString text = ui->textEdit_Note->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCopy_triggered()
{
  ui->textEdit_Note->copy();
}

void MainWindow::on_actionCut_triggered()
{
  ui->textEdit_Note->cut();
}

void MainWindow::on_actionPaste_triggered()
{
  ui->textEdit_Note->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit_Note->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit_Note->redo();
}

void MainWindow::on_actionAbout_triggered()
{
    QString about_text="Author: Seif Mostafa\nDate: 23/07/2017\nThis is first version of Notepad,\nAuthor wish complete multimedia series in one program";
      QMessageBox::about(this,"About Notepad",about_text);
}

class QColorDialogNotepad : public QWidget
{
public:
  QColor onColor()
  {
     QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
           return color;
    }
    return Qt::black;
  }

};
class QFontDialogNotepad : public QWidget
{
public:
  QFont onFont()
  {
   QFont font1("Sans Serif",18,-1,false);
    bool ok;
    QFont font = QFontDialog::getFont(
                    &ok,
                    QFont( "Arial", 18 ),
                    this,
                    tr("Pick a font") );
    if( ok )
    {
    /*  qDebug() << "font           : " << font;
      qDebug() << "font weight    : " << font.weight();
      qDebug() << "font family    : " << font.family();
      qDebug() << "font style     : " << font.style();  //  StyleNormal = 0, StyleItalic = 1, StyleOblique = 2
      qDebug() << "font pointSize : " << font.pointSize();*/
        return font;
    }
    return font1;
  }

};
void MainWindow::on_actionText_Color_triggered()
{
    QColorDialogNotepad QCDN;
    QColor color = QCDN.onColor();
   // qDebug() << "Color Choosen : " << color.name();
    ui->textEdit_Note->setTextColor(color);
}

void MainWindow::on_actionFont_triggered()
{
QFontDialogNotepad QFDN;
QFont font = QFDN.onFont();
ui->textEdit_Note->setFont(font);

}

void MainWindow::on_actionText_Background_Color_triggered()
{
    QColorDialogNotepad QCDN;
    QColor color = QCDN.onColor();
   // qDebug() << "Color Choosen : " << color.name();
    ui->textEdit_Note->setTextBackgroundColor(color);
}

void MainWindow::on_actionReset_Text_Background_Color_triggered()
{
    ui->textEdit_Note->setTextBackgroundColor(ui->textEdit_Note->backgroundRole());

}

void MainWindow::on_actionClose_triggered()
{
 QApplication::quit();
}

void MainWindow::on_actionBackground_triggered()
{
    QColorDialogNotepad QCDN;
    QColor color = QCDN.onColor();
   // qDebug() << "Color Choosen : " << color.name();
    if(color.isValid()){
        ui->textEdit_Note->setAutoFillBackground(true);
        ui->textEdit_Note->setPalette( QColor(color));
        ui->textEdit_Note->update();
    }
}
