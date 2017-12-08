/*
 * score.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */

#include "score.h"

ScoreScene::ScoreScene(QObject *_parent) :
		QGraphicsScene(_parent) {
	setup();
}

ScoreScene::~ScoreScene() {

}

void ScoreScene::setup() {
	int id = QFontDatabase::addApplicationFont(":fonts/pixeled.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	font = new QFont(family);
	font->setPixelSize(20);
	time= addText("TIME 999",*font);
	qreal scene_width=672.0;
	time->setPos(0,40);
	points= addText("0",*font);
	points->setPos(scene_width/2-points->boundingRect().width()/2,40);
	lives= addText("LEFT 3",*font);
	lives->setPos(scene_width-lives->boundingRect().width(),40);

}
