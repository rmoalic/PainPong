#include "player.h"
#include "constantes.h"
#include <QtDebug>

Player::Player(Position boardPosition) {
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
    if (this->racketPosition + getRacketSize().width() + 10 < WINDOW_WIDTH)
        this->racketPosition += 10;
    else
        this->racketPosition = WINDOW_WIDTH - getRacketSize().width();
}

void Player::draw(QPainter* paint) {
    QPainterPath path;
    QRect rect = QRect(racketPosition, boardPosition == Player::TOP ? 2:WINDOW_HEIGHT - 22, 80, 20);
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
