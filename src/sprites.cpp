/*
 * sprites.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */
#include "sprites.h"

Sprites::Sprites(QObject *_parent) :
		QObject(_parent) {
}
Sprites::~Sprites() {

}
void Sprites::load_sprites(unsigned scaled_width,unsigned scaled_height){
	QImage image;
	image.load(":images/sprites.png");
	QPixmap pixmap = QPixmap::fromImage(image);
	intro_screen = pixmap.copy(0, 258, 237, 176);
	map["intro_screen"]=intro_screen;
	player_down_1= pixmap.copy(0, 2, 16, 16).scaled(scaled_width,scaled_height);
	map["player_down_1"]=player_down_1;
	rock=pixmap.copy(0, 241, 15, 16).scaled(scaled_width,scaled_height);
	map["rock"]=rock;
	green=pixmap.copy(180, 0, 16, 16).scaled(scaled_width,scaled_height);
	map["green"]=green;
}

QPixmap Sprites::get_pixmap(const std::string& key){
	if (map.find(key)==map.end()){
		return QPixmap();
	}
	return map[key];
}
