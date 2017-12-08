/*
 * game_scene.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */
#include "game_scene.h"

GameScene::GameScene(QObject *_parent) :
		QGraphicsScene(_parent) {
	player = NULL;
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
	timer->start(200);
}

GameScene::GameScene(const QRectF &sceneRect, QObject *_parent) :
		QGraphicsScene(sceneRect, _parent) {
	player = NULL;
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
	timer->start(1000);
}

GameScene::~GameScene() {

}

void GameScene::add_item(Piece& piece, Sprites* sprites) {
	QPixmap pixmap = sprites->get_pixmap(piece.pixmap);
	QGraphicsPixmapItem* graphic_pixmap = new QGraphicsPixmapItem(pixmap);
	graphic_pixmap->setPos((float) piece.x * pixmap.width(),
			(float) piece.y * pixmap.height());
	addItem(graphic_pixmap);
	update();
	if (piece.player) {
		player = graphic_pixmap;
		player->setFlag(QGraphicsItem::ItemIsMovable);
	}
}

void GameScene::setup(std::vector<Piece>& pieces, Sprites* sprites) {
	for (auto it = pieces.begin(); it != pieces.end(); it++) {
		add_item(*it, sprites);
	}

}

void GameScene::tick() {
	switch (walking_dir) {
	case (1): {
		player->moveBy((-width()/16)/4,0);
		break;
	}
	case (2): {
		player->moveBy(0,(-height()/13)/4);
		break;
	}
	case (3): {
		player->moveBy((width()/16)/4,0);
		break;
	}
	case (4): {
		player->moveBy(0,(height()/13)/4);
		break;
	}
	default:
		break;
	}
update();
}
