#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr);
    ~Frame();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_breakfast_stateChanged(int arg1);

    void on_checkBox_lunch_stateChanged(int arg1);

    void on_checkBox_dinner_stateChanged(int arg1);

    void on_pushButton_total_clicked();

private:
    Ui::Frame *ui;
};

#endif // FRAME_H
