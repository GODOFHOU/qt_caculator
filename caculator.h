#ifndef CACULATOR_H
#define CACULATOR_H

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
public:
    int a;
    int b;

    double
    
    result;
    QString string;
    int op;
    bool isOperator;

    void init();
    void cal();


private slots:
    void on_acButton_clicked();

    void on_cButton_clicked();

    void on_addButton_clicked();

    void on_subButton_clicked();

    void on_chengButton_clicked();

    void on_chuButton_clicked();

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_zeroButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_equalButton_clicked();

    void on_sinButton_clicked();

    void on_cosButton_clicked();

    void on_tanButton_clicked();

    void on_arcsinButton_clicked();

    void on_arccosButton_clicked();

    void on_arctanButton_clicked();

    void on_qiuyuButton_clicked();

    void on_qiugenButton_clicked();

    void on_lnButton_clicked();

    void on_eButton_clicked();

    void on_qiumiButton_clicked();

    void on_jueduiButton_clicked();

    void on_qiehuanButton_clicked();

    void on_pointButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // CACULATOR_H
