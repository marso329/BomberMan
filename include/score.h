/*
 * score.h
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */

#ifndef BOMBERMAN_INCLUDE_SCORE_H_
#define BOMBERMAN_INCLUDE_SCORE_H_

#include <QObject>
#include <QGraphicsScene>
#include <QFontDatabase>
#include <QFont>
#include <QGraphicsTextItem>
#include <iostream>

class ScoreScene:public QGraphicsScene{
public:
	ScoreScene(QObject *_parent=NULL);
	~ScoreScene();
	void setup();

private:
	QFont* font;
	 QGraphicsTextItem * time;
	 QGraphicsTextItem * points;
	 QGraphicsTextItem * lives;
};




#endif /* BOMBERMAN_INCLUDE_SCORE_H_ */
