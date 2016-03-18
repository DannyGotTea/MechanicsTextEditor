#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();

    QFont customFont("Arial", 35, QFont::Bold);
    ui->mainTextEdit->setFont(customFont);
    symbolScrollArea = new QScrollArea;

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(symbolScrollArea, "Symbols");

    QGridLayout *symbolLayout = new QGridLayout;
    symbolScrollArea->setLayout(symbolLayout);

    symbolSelection = new ScientificNotationSelection(this);

    QStringList capitalGreekList = symbolSelection->getCapitalGreekList();
    capitalGreekButtons = symbolSelection->generateWidgets(capitalGreekList, symbolScrollArea);

    QStringList mathematicalList = symbolSelection->getBasicMathematicalList();
    mathematicalButtons = symbolSelection->generateWidgets(mathematicalList, symbolScrollArea);

    row = 0, column = 0;

    addButtons(mathematicalButtons, symbolScrollArea, symbolLayout);
    addButtons(capitalGreekButtons, symbolScrollArea, symbolLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNotationClicked()
{
   QString text = ((QPushButton*)sender())->text();
   qDebug() << "TEXT OUTPUT: " << text;
   ui->mainTextEdit->insertPlainText(text);
   ui->mainTextEdit->setFocus();
}

void MainWindow::addButtons(QVector<QPushButton *> &buttonList, QScrollArea *buttonArea, QGridLayout *layout)
{
    foreach(symbolButton, buttonList)
    {
        if(column == 5)
        {
            column = 0; row++;
        }
        else
            column++;

        symbolButton->setMinimumHeight(buttonArea->height() / 8);

        qDebug() << "Adding " << symbolButton << " to: row " << row << ", column " << column;
        layout->addWidget(symbolButton, row, column);

        connect(symbolButton, SIGNAL(clicked()), this, SLOT(onNotationClicked()));
    }
}






















