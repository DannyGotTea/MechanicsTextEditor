#ifndef SCIENTIFICNOTATIONSELECTION_H
#define SCIENTIFICNOTATIONSELECTION_H

#include <QObject>
#include <QScrollArea>
#include <QPushButton>
#include <QStringList>
#include <QVector>
#include <QPoint>
#include <cstdlib>
#include <QSharedPointer>
#include <QTextEdit>

enum SymbolType {
    LowerCaseGreek,
    CapitalGreek
};

class ScientificNotationSelection : public QObject
{
    Q_OBJECT
public:
    explicit ScientificNotationSelection(QObject *parent = 0);
    ~ScientificNotationSelection();

    QVector<QPushButton *> generateWidgets(QStringList &symbols, QScrollArea *parent = 0);

    QStringList generateSelectionList(SymbolType type = CapitalGreek);


private:
    SymbolType  symbolType;
    QScrollArea symbolScrollArea;
    QStringList capitalGreekList;

protected:

    QVector<QPushButton*> *notationWidgetCollection;

public slots:
};

#endif // SCIENTIFICNOTATIONSELECTION_H
