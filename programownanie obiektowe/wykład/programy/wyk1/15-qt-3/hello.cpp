#include <QApplication>
#include <QPushButton>
#include <QDial>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");
    hello.resize(100, 30);
    hello.setFont(QFont("Arial", 18, QFont::Bold));
    hello.setGeometry(400, 200 , 180, 40);

    QDial dial;
    dial.show();

    hello.show();
    return app.exec();
}
