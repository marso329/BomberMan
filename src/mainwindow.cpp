#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {

	ui->setupUi(this);
	scaled_pixmap_width = ui->gameArea->width() / 16;
	scaled_pixmap_height = ui->gameArea->height() / 13;

	sprites = new Sprites(this);
	sprites->load_sprites(scaled_pixmap_width, scaled_pixmap_height);
	audio = new Audio(this);

	//intro screen
	scene_intro = new QGraphicsScene(ui->introArea);
	ui->introArea->setScene(scene_intro);
	scene_intro->addItem(new QGraphicsPixmapItem(sprites->intro_screen));
	scene_intro->update();
	ui->introArea->fitInView(scene_intro->itemsBoundingRect(),
			Qt::KeepAspectRatio);
	ui->introArea->show();
	ui->main->setCurrentIndex(1);

	//main game screen
	scene_main = new GameScene(ui->gameArea);
	ui->gameArea->setScene(scene_main);
	ui->gameArea->setAlignment(Qt::AlignLeft);
	ui->gameArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->gameArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//score screen
	scene_score = new ScoreScene(ui->scoreArea);
	ui->scoreArea->setScene(scene_score);
	ui->scoreArea->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	ui->scoreArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->scoreArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	init_board();
	scene_main->update();
	ui->gameArea->show();

	// audio->play_intro();
}

void MainWindow::init_board() {
	std::vector<Piece> board;
	for (unsigned int i = 0; i < 16; i++) {
		board.push_back(Piece(i, 0, "rock"));
		board.push_back(Piece(i, 12, "rock"));
	}
	for (unsigned int i = 0; i < 13; i++) {
		board.push_back(Piece(0, i, "rock"));
		board.push_back(Piece(15, i, "rock"));
	}
	for (unsigned int i = 1; i < 16; i += 2) {
		for (unsigned int j = 2; j < 13; j += 2) {
			board.push_back(Piece(i, j, "rock"));
		}
	}
	Piece temp = Piece(5, 5, "player_down_1");
	temp.player = true;
	board.push_back(temp);
	scene_main->setup(board, sprites);

}

void MainWindow::resizeEvent(QResizeEvent* event) {
	ui->introArea->fitInView(scene_intro->itemsBoundingRect(),
			Qt::KeepAspectRatio);
	ui->introArea->show();
	QMainWindow::resizeEvent(event);
}
void MainWindow::showEvent(QShowEvent *event) {
	ui->introArea->fitInView(scene_intro->itemsBoundingRect(),
			Qt::KeepAspectRatio);
	ui->introArea->show();
	QMainWindow::showEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_W) {
		scene_main->walking_dir = 2;
	} else if (event->key() == Qt::Key_A) {
		scene_main->walking_dir = 1;
	} else if (event->key() == Qt::Key_D) {
		scene_main->walking_dir = 3;
	} else if (event->key() == Qt::Key_S) {
		scene_main->walking_dir = 4;
	}
	event->accept();

	//QMainWindow::keyPressEvent(event);

}
void MainWindow::keyReleaseEvent(QKeyEvent* event) {
	if (event->isAutoRepeat()){
		event->accept();
		return;
	}
	if (event->key() == Qt::Key_A) {
		scene_main->walking_dir = 0;
	} else if (event->key() == Qt::Key_A) {
		scene_main->walking_dir = 0;
	} else if (event->key() == Qt::Key_D) {
		scene_main->walking_dir = 0;
	} else if (event->key() == Qt::Key_S) {
		scene_main->walking_dir = 0;
	}
	event->accept();
//	QMainWindow::keyReleaseEvent(event);

}



MainWindow::~MainWindow() {

}

