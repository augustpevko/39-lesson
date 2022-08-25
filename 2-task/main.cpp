#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QRegExp>
#include <QRegularExpression>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window(nullptr);
    auto* qLineEditValid = new QLineEdit(&window);
    auto* qOkLabel = new QLabel(&window);
    QRegularExpression phoneNumberValid("^\\+\\d{11}");
    
    QObject::connect(qLineEditValid, &QLineEdit::textEdited, [qOkLabel, phoneNumberValid](QString currentText) {
        if (currentText == "") qOkLabel->setText("");
        else if (phoneNumberValid.match(currentText).hasMatch()) {
            qOkLabel->setText("OK");
            qOkLabel->setStyleSheet("QLabel {color: green;}");
        }
        else {
            qOkLabel->setText("Fail");
            qOkLabel->setStyleSheet("QLabel {color: red;}");
        }
    });

    auto* qVBoxlayout = new QVBoxLayout(&window);
    qVBoxlayout->addWidget(qLineEditValid);
    qVBoxlayout->addWidget(qOkLabel);


    window.setFixedSize(200, 250);
    window.move(1000, 500);
    window.show();
    return QApplication::exec();
}