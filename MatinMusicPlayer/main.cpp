#include <QApplication>
#include <QPushButton>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Matin Music Player");

    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *btnOpen = new QPushButton("Open Music File");
    layout->addWidget(btnOpen);

    QMediaPlayer *player = new QMediaPlayer;

    QObject::connect(btnOpen, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Music File", "", "Audio Files (*.mp3 *.wav)");
        if (!fileName.isEmpty()) {
            player->setMedia(QUrl::fromLocalFile(fileName));
            player->play();
        }
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
