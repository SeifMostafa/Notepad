#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionText_Color_triggered();

   // void on_actionBackground_Color_triggered();

    void on_actionFont_triggered();

    void on_actionText_Background_Color_triggered();

    void on_actionReset_Text_Background_Color_triggered();

    void on_actionClose_triggered();

    void on_actionBackground_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
};

#endif // MAINWINDOW_H
