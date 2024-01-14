#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>
#include <QVBoxLayout>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

double totalCost = 0.0;
QStringList selectedItems;

void SecDialog::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setMinimumSize(2000,4000);

    if(ui->checkBox->isChecked()){
        selectedItems << "Breakfast (₹30)";
        totalCost+=30;
    }
    if(ui->checkBox_2->isChecked()){
        selectedItems << "Lunch (₹100)";
        totalCost+=100;
    }
    if(ui->checkBox_3->isChecked()){
        selectedItems << "Dinner (₹150)";
        totalCost+=150;
    }
    if(ui->checkBox_4->isChecked()){
        selectedItems << "Veg";
    }
    if(ui->checkBox_5->isChecked()){
        selectedItems << "Non-Veg";
    }


    QString billDetails = "Bill Details:\n";
    billDetails += "Selected Items:\n";
    billDetails += selectedItems.join("\n") + "\n";
    billDetails += "Total Cost: ₹" + QString::number(totalCost);
    billDetails += "\nThank You !";
    msgBox.about(this, "Bill Generation", billDetails);
}



