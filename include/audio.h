/*
 * audio.h
 *
 *  Created on: Dec 2, 2017
 *      Author: martin
 */

#ifndef BOMBERMAN_INCLUDE_AUDIO_H_
#define BOMBERMAN_INCLUDE_AUDIO_H_

#include <QMediaPlayer>
#include <QSoundEffect>
#include <QObject>
#include <QUrl>
#include <iostream>
#include <vector>
#include <QString>

class Audio: public QObject{
	 Q_OBJECT
public:
	 Audio(QObject *_parent=NULL);
	 ~Audio();
	 void play_intro();
	 void play_theme();
	 Q_SIGNALS:
	 public Q_SLOTS:
private:
	 void play(const QString&);
	 QMediaPlayer* player;

};




#endif /* BOMBERMAN_INCLUDE_AUDIO_H_ */
