#include "player.h"
#include "constantes.h"
#include <QtDebug>

Player::Player(Position boardPosition) {
    this->boardPosition = boardPosition;
    this->racketPosition = 0;
}

void Player::moveLeft() {
    this->racketPosition -= 10;
}

void Player::moveRight() {
    this->racketPosition += 10;
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
