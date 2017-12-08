
#ifndef MAINWINDOW_
#define MAINWINDOW_

//own includes
#include "ui_mainwindow.h"
#include "audio.h"
#include "sprites.h"
#include "game_scene.h"
#include "score.h"
#include "piece.h"

//QT includes
#include <QPainter>
#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>

//std includes
#include <iostream>

class MainWindow: public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();
private:
	void init_board();
	Ui::MainWindow* ui;
	QGraphicsScene* scene_intro;

	GameScene* scene_main;
	QGraphicsScene* scene_score;
	Sprites* sprites;
	Audio* audio;
	int scaled_pixmap_width;
	int scaled_pixmap_height;
protected:
Q_SIGNALS:

public Q_SLOTS:
void resizeEvent(QResizeEvent* event);
void showEvent(QShowEvent *event);
void keyPressEvent(QKeyEvent*);
void keyReleaseEvent(QKeyEvent*);

};
#endif
