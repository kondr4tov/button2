#include <QtGui/QtGui>

#include <QApplication>
#include <QPushButton>

#include <QMediaPlayer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton *button = new QPushButton;
    auto *player = new QMediaPlayer();

    bool flag = false;

    button->show();
    button->setGeometry(500,500,200,200);

    button->setIcon(QIcon("/Users/andrejkondratov/Desktop/off.png"));
    button->setIconSize(QSize(200, 200));

    QObject::connect(button, &QPushButton::clicked, [&flag, &button, &player]()
    {
        if (flag) {
            flag = false;
            player->setMedia(QUrl::fromLocalFile("/Users/andrejkondratov/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
            player->play();
            button->setIcon(QIcon("/Users/andrejkondratov/Desktop/off.png"));
            button->setIconSize(QSize(200, 200));
        }
        else {
            flag = true;
            player->setMedia(QUrl::fromLocalFile("/Users/andrejkondratov/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
            player->play();
            button->setIcon(QIcon("/Users/andrejkondratov/Desktop/on.png"));
            button->setIconSize(QSize(200, 200));
        }
    });


    return a.exec();
}