/*
 * sprites.h
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */

#ifndef BOMBERMAN_INCLUDE_SPRITES_H_
#define BOMBERMAN_INCLUDE_SPRITES_H_
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include <map>

class Sprites:public QObject{
	Q_OBJECT
public:
	Sprites(QObject *_parent=NULL);
	~Sprites();
	void load_sprites(unsigned width,unsigned height);
	QPixmap get_pixmap(const std::string&);
	QPixmap intro_screen;
	QPixmap player_down_1;
	QPixmap rock;
	QPixmap green;
	std::map<std::string,QPixmap> map;
};




#endif /* BOMBERMAN_INCLUDE_SPRITES_H_ */
