/*
 * game_scene.h
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */

#ifndef BOMBERMAN_INCLUDE_GAME_SCENE_H_
#define BOMBERMAN_INCLUDE_GAME_SCENE_H_
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QTimer>
#include <iostream>

#include "piece.h"
#include "sprites.h"


class GameScene:public QGraphicsScene{
	Q_OBJECT
public:
	GameScene(QObject *_parent=NULL);
	GameScene(const QRectF &sceneRect, QObject *_parent = NULL);
	~GameScene();
	void add_item(Piece&,Sprites*);
	void setup(std::vector<Piece>&,Sprites*);
	//0=nothing, 1=left;2=up,3=right,4=down
	int walking_dir=0;
private:
	QGraphicsPixmapItem* player;
	std::vector<QGraphicsPixmapItem*> bombs;
	std::vector<QGraphicsPixmapItem*> enemies;
	std::vector<std::vector<std::vector<QGraphicsPixmapItem*>>> items;
	QTimer *timer;
	Q_SIGNALS:

	public Q_SLOTS:
	void tick();
};



#endif /* BOMBERMAN_INCLUDE_GAME_SCENE_H_ */
