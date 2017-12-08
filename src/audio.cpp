/*
 * audio.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: martin
 */
#include "audio.h"

Audio::Audio(QObject *_parent):QObject(_parent){
	player=new QMediaPlayer(this);
	player->setVolume(50);
}

Audio::~Audio(){

}

void Audio::play(const QString& resource){
	player->stop();
	player->setMedia(QUrl(resource));
	player->play();
}

void Audio::play_intro(){
	play("qrc:/audio/intro.mp3");
}

void Audio::play_theme(){
	play("qrc:/audio/theme.mp3");
}




