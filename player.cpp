#include "player.h"

Player::Player(Position boardPosition) {
    this->boardPosition = boardPosition;
    this->racketPosition = 150;
}

void Player::draw(QPainter* paint) {
#if false
    QPainterPath path;
    QRect rect(racketPosition, boardPosition == Player::BOTTOM ? 10:1500, );
    path.addRect(QRect());
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(Qt::black));
#endif
}

Player::Position Player::getBoardPosition() {
    return boardPosition;
}

int Player::getRacketPosition() {
    return racketPosition;
}
