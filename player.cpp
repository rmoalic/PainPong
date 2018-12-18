#include "player.h"
#include "constantes.h"
#include "imageloader.h"
#include <QtDebug>
#define PAS 5

Player::Player(Position boardPosition, QSize window_size) {
    this->window_size = window_size;
    this->boardPosition = boardPosition;
    this->racketPosition = 0;
    this->player_size = QSize(80, 20);
    this->player_sprite = loadImage(":/player.png");
}

void Player::moveLeft() {
    if (this->racketPosition - PAS >= 0)
        this->racketPosition -= PAS;
    else
        this->racketPosition = 0;
}

void Player::moveRight() {
    if (this->racketPosition + getRacketSize().width() + PAS < window_size.width())
        this->racketPosition += PAS;
    else
        this->racketPosition = window_size.width() - getRacketSize().width();
}

void Player::draw(QPainter* paint) {
    QRect rect = QRect(racketPosition, boardPosition == Player::TOP ? 0:window_size.height() - player_size.height(), player_size.width(), player_size.height());
    paint->drawImage(rect, *this->player_sprite);
}

Player::Position Player::getBoardPosition() {
    return boardPosition;
}

int Player::getRacketPosition() {
    return racketPosition;
}

QSize Player::getRacketSize() {
    return this->player_size;
}
