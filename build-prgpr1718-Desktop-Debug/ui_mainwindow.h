/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_2;
    QPushButton *Button_start;
    QPushButton *Button_stop;
    QPushButton *Button_clear;
    QLabel *Label_universe_size;
    QSpinBox *SpinBox_universe_size;
    QLabel *Label_cell_mode;
    QComboBox *ComboBox_cells_mode;
    QLabel *Label_universe_mode;
    QComboBox *ComboBox_universe_mode;
    QLabel *Label_generation_intervall;
    QSpinBox *SpinBox_generation_intervall;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_load;
    QPushButton *Button_save;
    QPushButton *Button_select_color;
    QPushButton *Button_radom_color;
    QPushButton *Button_go;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 600);
        MainWindow->setMinimumSize(QSize(960, 600));
        MainWindow->setMaximumSize(QSize(960, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(600, 10, 351, 581));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Button_start = new QPushButton(formLayoutWidget);
        Button_start->setObjectName(QStringLiteral("Button_start"));

        gridLayout_2->addWidget(Button_start, 0, 0, 1, 1);

        Button_stop = new QPushButton(formLayoutWidget);
        Button_stop->setObjectName(QStringLiteral("Button_stop"));

        gridLayout_2->addWidget(Button_stop, 0, 1, 1, 1);

        Button_clear = new QPushButton(formLayoutWidget);
        Button_clear->setObjectName(QStringLiteral("Button_clear"));

        gridLayout_2->addWidget(Button_clear, 0, 2, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout_2);

        Label_universe_size = new QLabel(formLayoutWidget);
        Label_universe_size->setObjectName(QStringLiteral("Label_universe_size"));
        Label_universe_size->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_universe_size->sizePolicy().hasHeightForWidth());
        Label_universe_size->setSizePolicy(sizePolicy);
        Label_universe_size->setSizeIncrement(QSize(0, 0));
        Label_universe_size->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, Label_universe_size);

        SpinBox_universe_size = new QSpinBox(formLayoutWidget);
        SpinBox_universe_size->setObjectName(QStringLiteral("SpinBox_universe_size"));
        SpinBox_universe_size->setMinimum(3);
        SpinBox_universe_size->setMaximum(100);
        SpinBox_universe_size->setSingleStep(10);
        SpinBox_universe_size->setValue(50);
        SpinBox_universe_size->setDisplayIntegerBase(10);

        formLayout->setWidget(3, QFormLayout::FieldRole, SpinBox_universe_size);

        Label_cell_mode = new QLabel(formLayoutWidget);
        Label_cell_mode->setObjectName(QStringLiteral("Label_cell_mode"));
        Label_cell_mode->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, Label_cell_mode);

        ComboBox_cells_mode = new QComboBox(formLayoutWidget);
        ComboBox_cells_mode->setObjectName(QStringLiteral("ComboBox_cells_mode"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ComboBox_cells_mode);

        Label_universe_mode = new QLabel(formLayoutWidget);
        Label_universe_mode->setObjectName(QStringLiteral("Label_universe_mode"));
        Label_universe_mode->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, Label_universe_mode);

        ComboBox_universe_mode = new QComboBox(formLayoutWidget);
        ComboBox_universe_mode->setObjectName(QStringLiteral("ComboBox_universe_mode"));

        formLayout->setWidget(7, QFormLayout::FieldRole, ComboBox_universe_mode);

        Label_generation_intervall = new QLabel(formLayoutWidget);
        Label_generation_intervall->setObjectName(QStringLiteral("Label_generation_intervall"));
        Label_generation_intervall->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, Label_generation_intervall);

        SpinBox_generation_intervall = new QSpinBox(formLayoutWidget);
        SpinBox_generation_intervall->setObjectName(QStringLiteral("SpinBox_generation_intervall"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SpinBox_generation_intervall->sizePolicy().hasHeightForWidth());
        SpinBox_generation_intervall->setSizePolicy(sizePolicy1);
        SpinBox_generation_intervall->setBaseSize(QSize(0, 0));
        SpinBox_generation_intervall->setMinimum(100);
        SpinBox_generation_intervall->setMaximum(1000);
        SpinBox_generation_intervall->setSingleStep(100);
        SpinBox_generation_intervall->setValue(1000);

        formLayout->setWidget(9, QFormLayout::FieldRole, SpinBox_generation_intervall);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Button_load = new QPushButton(formLayoutWidget);
        Button_load->setObjectName(QStringLiteral("Button_load"));

        horizontalLayout->addWidget(Button_load);

        Button_save = new QPushButton(formLayoutWidget);
        Button_save->setObjectName(QStringLiteral("Button_save"));

        horizontalLayout->addWidget(Button_save);


        formLayout->setLayout(10, QFormLayout::FieldRole, horizontalLayout);

        Button_select_color = new QPushButton(formLayoutWidget);
        Button_select_color->setObjectName(QStringLiteral("Button_select_color"));

        formLayout->setWidget(11, QFormLayout::FieldRole, Button_select_color);

        Button_radom_color = new QPushButton(formLayoutWidget);
        Button_radom_color->setObjectName(QStringLiteral("Button_radom_color"));

        formLayout->setWidget(12, QFormLayout::FieldRole, Button_radom_color);

        Button_go = new QPushButton(formLayoutWidget);
        Button_go->setObjectName(QStringLiteral("Button_go"));

        formLayout->setWidget(13, QFormLayout::FieldRole, Button_go);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 581, 581));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Button_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        Button_stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        Button_clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        Label_universe_size->setText(QApplication::translate("MainWindow", "Universe Size", Q_NULLPTR));
        SpinBox_universe_size->setSuffix(QApplication::translate("MainWindow", " Cells", Q_NULLPTR));
        Label_cell_mode->setText(QApplication::translate("MainWindow", "Cells Mode", Q_NULLPTR));
        Label_universe_mode->setText(QApplication::translate("MainWindow", "Universe Mode", Q_NULLPTR));
        ComboBox_universe_mode->clear();
        ComboBox_universe_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Game of Life", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Snake", Q_NULLPTR)
        );
        Label_generation_intervall->setText(QApplication::translate("MainWindow", "Generation Intervall (in milliseconds)", Q_NULLPTR));
        SpinBox_generation_intervall->setSuffix(QApplication::translate("MainWindow", " ms", Q_NULLPTR));
        Button_load->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        Button_save->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        Button_select_color->setText(QApplication::translate("MainWindow", "Select color for cells", Q_NULLPTR));
        Button_radom_color->setText(QApplication::translate("MainWindow", "Random Color", Q_NULLPTR));
        Button_go->setText(QApplication::translate("MainWindow", "GO!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
