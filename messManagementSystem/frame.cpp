#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
}

Frame::~Frame()
{
    delete ui;
}
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QStringList>

class MessBillGenerator : public QWidget {
    Q_OBJECT

public:
    MessBillGenerator(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *titleLabel = new QLabel("Mess Bill Generator");

        menuLabel = new QLabel("Menu:");
        breakfastCheckBox = new QCheckBox("Breakfast ($3.00)");
        lunchCheckBox = new QCheckBox("Lunch ($5.00)");
        dinnerCheckBox = new QCheckBox("Dinner ($4.50)");

        //QLabel *mealLabel = new QLabel("Number of Meals:");
        //mealEdit = new QLineEdit();

        QPushButton *generateButton = new QPushButton("Generate Bill");

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(titleLabel);
        layout->addWidget(menuLabel);
        layout->addWidget(breakfastCheckBox);
        layout->addWidget(lunchCheckBox);
        layout->addWidget(dinnerCheckBox);
        //layout->addWidget(mealLabel);
        //layout->addWidget(mealEdit);
        layout->addWidget(generateButton);

        setLayout(layout);

        connect(generateButton, SIGNAL(clicked()), this, SLOT(generateBill()));
    }

public slots:
    void generateBill() {
        QStringList selectedItems;
        double totalCost = 0.0;

        if (breakfastCheckBox->isChecked()) {
            selectedItems << "Breakfast ($3.00)";
            totalCost += 3.00;
        }
        if (lunchCheckBox->isChecked()) {
            selectedItems << "Lunch ($5.00)";
            totalCost += 5.00;
        }
        if (dinnerCheckBox->isChecked()) {
            selectedItems << "Dinner ($4.50)";
            totalCost += 4.50;
        }

        //QString mealStr = mealEdit->text();
        bool ok;
        //int numberOfMeals = mealStr.toInt(&ok);

        if (ok) {
            //totalCost *= numberOfMeals;
            QString billDetails = "Bill Details:\n";
            billDetails += "Selected Items:\n";
            billDetails += selectedItems.join("\n") + "\n";
            //billDetails += "Number of Meals: " + QString::number(numberOfMeals) + "\n";
            billDetails += "Total Cost: $" + QString::number(totalCost);

            QMessageBox::information(this, "Bill Generation", billDetails);
        } else {
            QMessageBox::warning(this, "Error", "Invalid input. Please enter a valid number of meals.");
        }
    }

private:
    QLabel *menuLabel;
    QCheckBox *breakfastCheckBox;
    QCheckBox *lunchCheckBox;
    QCheckBox *dinnerCheckBox;
    //QLineEdit *mealEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MessBillGenerator window;
    window.show();
    return app.exec();
}

#include "mainwindow.h"
