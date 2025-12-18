/********************************************************************************
** Form generated from reading UI file 'search_filter_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SEARCH_FILTER_DIALOG_H
#define SEARCH_FILTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *searchTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *searchGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *searchFieldLabel;
    QComboBox *searchFieldComboBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *caseSensitiveCheckBox;
    QCheckBox *exactMatchCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *searchButton;
    QPushButton *clearSearchButton;
    QSpacerItem *verticalSpacer;
    QWidget *filterTab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *filterGroupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *statusLabel;
    QComboBox *statusComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *typeLabel;
    QComboBox *typeComboBox;
    QGroupBox *dateRangeGroupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *fromDateLabel;
    QDateEdit *fromDateEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *toDateLabel;
    QDateEdit *toDateEdit;
    QGroupBox *priceRangeGroupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *minPriceLabel;
    QSpinBox *minPriceSpinBox;
    QLabel *maxPriceLabel;
    QSpinBox *maxPriceSpinBox;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *applyFilterButton;
    QPushButton *resetFilterButton;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SearchFilterDialog)
    {
        if (SearchFilterDialog->objectName().isEmpty())
            SearchFilterDialog->setObjectName(QString::fromUtf8("SearchFilterDialog"));
        SearchFilterDialog->resize(600, 458);
        verticalLayout = new QVBoxLayout(SearchFilterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(SearchFilterDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        searchTab = new QWidget();
        searchTab->setObjectName(QString::fromUtf8("searchTab"));
        verticalLayout_2 = new QVBoxLayout(searchTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        searchGroupBox = new QGroupBox(searchTab);
        searchGroupBox->setObjectName(QString::fromUtf8("searchGroupBox"));
        verticalLayout_3 = new QVBoxLayout(searchGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchLabel = new QLabel(searchGroupBox);
        searchLabel->setObjectName(QString::fromUtf8("searchLabel"));

        horizontalLayout->addWidget(searchLabel);

        searchLineEdit = new QLineEdit(searchGroupBox);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchFieldLabel = new QLabel(searchGroupBox);
        searchFieldLabel->setObjectName(QString::fromUtf8("searchFieldLabel"));

        horizontalLayout_2->addWidget(searchFieldLabel);

        searchFieldComboBox = new QComboBox(searchGroupBox);
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->setObjectName(QString::fromUtf8("searchFieldComboBox"));

        horizontalLayout_2->addWidget(searchFieldComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        caseSensitiveCheckBox = new QCheckBox(searchGroupBox);
        caseSensitiveCheckBox->setObjectName(QString::fromUtf8("caseSensitiveCheckBox"));

        verticalLayout_3->addWidget(caseSensitiveCheckBox);

        exactMatchCheckBox = new QCheckBox(searchGroupBox);
        exactMatchCheckBox->setObjectName(QString::fromUtf8("exactMatchCheckBox"));

        verticalLayout_3->addWidget(exactMatchCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        searchButton = new QPushButton(searchGroupBox);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_3->addWidget(searchButton);

        clearSearchButton = new QPushButton(searchGroupBox);
        clearSearchButton->setObjectName(QString::fromUtf8("clearSearchButton"));

        horizontalLayout_3->addWidget(clearSearchButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addWidget(searchGroupBox);

        tabWidget->addTab(searchTab, QString());
        filterTab = new QWidget();
        filterTab->setObjectName(QString::fromUtf8("filterTab"));
        verticalLayout_4 = new QVBoxLayout(filterTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        filterGroupBox = new QGroupBox(filterTab);
        filterGroupBox->setObjectName(QString::fromUtf8("filterGroupBox"));
        verticalLayout_5 = new QVBoxLayout(filterGroupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        statusLabel = new QLabel(filterGroupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        horizontalLayout_4->addWidget(statusLabel);

        statusComboBox = new QComboBox(filterGroupBox);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName(QString::fromUtf8("statusComboBox"));

        horizontalLayout_4->addWidget(statusComboBox);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        typeLabel = new QLabel(filterGroupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        horizontalLayout_5->addWidget(typeLabel);

        typeComboBox = new QComboBox(filterGroupBox);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));

        horizontalLayout_5->addWidget(typeComboBox);


        verticalLayout_5->addLayout(horizontalLayout_5);

        dateRangeGroupBox = new QGroupBox(filterGroupBox);
        dateRangeGroupBox->setObjectName(QString::fromUtf8("dateRangeGroupBox"));
        verticalLayout_6 = new QVBoxLayout(dateRangeGroupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        fromDateLabel = new QLabel(dateRangeGroupBox);
        fromDateLabel->setObjectName(QString::fromUtf8("fromDateLabel"));

        horizontalLayout_6->addWidget(fromDateLabel);

        fromDateEdit = new QDateEdit(dateRangeGroupBox);
        fromDateEdit->setObjectName(QString::fromUtf8("fromDateEdit"));
        fromDateEdit->setCalendarPopup(true);

        horizontalLayout_6->addWidget(fromDateEdit);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        toDateLabel = new QLabel(dateRangeGroupBox);
        toDateLabel->setObjectName(QString::fromUtf8("toDateLabel"));

        horizontalLayout_7->addWidget(toDateLabel);

        toDateEdit = new QDateEdit(dateRangeGroupBox);
        toDateEdit->setObjectName(QString::fromUtf8("toDateEdit"));
        toDateEdit->setCalendarPopup(true);

        horizontalLayout_7->addWidget(toDateEdit);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_5->addWidget(dateRangeGroupBox);

        priceRangeGroupBox = new QGroupBox(filterGroupBox);
        priceRangeGroupBox->setObjectName(QString::fromUtf8("priceRangeGroupBox"));
        verticalLayout_7 = new QVBoxLayout(priceRangeGroupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        minPriceLabel = new QLabel(priceRangeGroupBox);
        minPriceLabel->setObjectName(QString::fromUtf8("minPriceLabel"));

        horizontalLayout_8->addWidget(minPriceLabel);

        minPriceSpinBox = new QSpinBox(priceRangeGroupBox);
        minPriceSpinBox->setObjectName(QString::fromUtf8("minPriceSpinBox"));
        minPriceSpinBox->setMaximum(999999999);

        horizontalLayout_8->addWidget(minPriceSpinBox);

        maxPriceLabel = new QLabel(priceRangeGroupBox);
        maxPriceLabel->setObjectName(QString::fromUtf8("maxPriceLabel"));

        horizontalLayout_8->addWidget(maxPriceLabel);

        maxPriceSpinBox = new QSpinBox(priceRangeGroupBox);
        maxPriceSpinBox->setObjectName(QString::fromUtf8("maxPriceSpinBox"));
        maxPriceSpinBox->setMaximum(999999999);

        horizontalLayout_8->addWidget(maxPriceSpinBox);


        verticalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(priceRangeGroupBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        applyFilterButton = new QPushButton(filterGroupBox);
        applyFilterButton->setObjectName(QString::fromUtf8("applyFilterButton"));

        horizontalLayout_9->addWidget(applyFilterButton);

        resetFilterButton = new QPushButton(filterGroupBox);
        resetFilterButton->setObjectName(QString::fromUtf8("resetFilterButton"));

        horizontalLayout_9->addWidget(resetFilterButton);


        verticalLayout_5->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        verticalLayout_4->addWidget(filterGroupBox);

        tabWidget->addTab(filterTab, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(SearchFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SearchFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SearchFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SearchFilterDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SearchFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchFilterDialog)
    {
        SearchFilterDialog->setWindowTitle(QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m v\303\240 L\341\273\215c", nullptr));
        searchGroupBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m th\303\264ng tin", nullptr));
        searchLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253 kh\303\263a:", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchFilterDialog", "Nh\341\272\255p t\341\273\253 kh\303\263a t\303\254m ki\341\272\277m...", nullptr));
        searchFieldLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\303\254m theo:", nullptr));
        searchFieldComboBox->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "T\341\272\245t c\341\272\243", nullptr));
        searchFieldComboBox->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "M\303\243", nullptr));
        searchFieldComboBox->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "T\303\252n", nullptr));
        searchFieldComboBox->setItemText(3, QCoreApplication::translate("SearchFilterDialog", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i", nullptr));
        searchFieldComboBox->setItemText(4, QCoreApplication::translate("SearchFilterDialog", "Email", nullptr));

        caseSensitiveCheckBox->setText(QCoreApplication::translate("SearchFilterDialog", "Ph\303\242n bi\341\273\207t ch\341\273\257 hoa/th\306\260\341\273\235ng", nullptr));
        exactMatchCheckBox->setText(QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m ch\303\255nh x\303\241c", nullptr));
        searchButton->setText(QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m", nullptr));
        clearSearchButton->setText(QCoreApplication::translate("SearchFilterDialog", "X\303\263a", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(searchTab), QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m", nullptr));
        filterGroupBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "B\341\273\231 l\341\273\215c", nullptr));
        statusLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Tr\341\272\241ng th\303\241i:", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "T\341\272\245t c\341\272\243", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "\304\220ang ho\341\272\241t \304\221\341\273\231ng", nullptr));
        statusComboBox->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "Kh\303\264ng ho\341\272\241t \304\221\341\273\231ng", nullptr));

        typeLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Lo\341\272\241i:", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "T\341\272\245t c\341\272\243", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "Lo\341\272\241i 1", nullptr));
        typeComboBox->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "Lo\341\272\241i 2", nullptr));
        typeComboBox->setItemText(3, QCoreApplication::translate("SearchFilterDialog", "Lo\341\272\241i 3", nullptr));

        dateRangeGroupBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "Kho\341\272\243ng th\341\273\235i gian", nullptr));
        fromDateLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253 ng\303\240y:", nullptr));
        toDateLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n ng\303\240y:", nullptr));
        priceRangeGroupBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "Kho\341\272\243ng gi\303\241", nullptr));
        minPriceLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253:", nullptr));
        maxPriceLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n:", nullptr));
        applyFilterButton->setText(QCoreApplication::translate("SearchFilterDialog", "\303\201p d\341\273\245ng", nullptr));
        resetFilterButton->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\267t l\341\272\241i", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(filterTab), QCoreApplication::translate("SearchFilterDialog", "L\341\273\215c", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchFilterDialog: public Ui_SearchFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SEARCH_FILTER_DIALOG_H
