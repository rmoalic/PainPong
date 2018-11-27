#include "player.h"
#include "constantes.h"
#include <QtDebug>

Player::Player(Position boardPosition, QSize window_size) {
    this->window_size = window_size;
    this->boardPosition = boardPosition;
    this->racketPosition = 0;
}

void Player::moveLeft() {
    if (this->racketPosition - 10 >= 0)
        this->racketPosition -= 10;
    else
        this->racketPosition = 0;
}

void Player::moveRight() {
    if (this->racketPosition + getRacketSize().width() + 10 < window_size.width())
        this->racketPosition += 10;
    else
        this->racketPosition = window_size.width() - getRacketSize().width();
}

void Player::draw(QPainter* paint) {
    QPainterPath path;
    QRect rect = QRect(racketPosition, boardPosition == Player::TOP ? 0:window_size.height() - 20, 80, 20);
    path.addRect(rect);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(Qt::black));
}

Player::Position Player::getBoardPosition() {
    return boardPosition;
}

int Player::getRacketPosition() {
    return racketPosition;
}

QSize Player::getRacketSize() {
    return QSize(80, 20);
}
