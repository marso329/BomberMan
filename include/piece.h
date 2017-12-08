/*
 * piece.h
 *
 *  Created on: Dec 3, 2017
 *      Author: martin
 */

#ifndef BOMBERMAN_INCLUDE_PIECE_H_
#define BOMBERMAN_INCLUDE_PIECE_H_
#include <string>

class Piece{
public:
	Piece(unsigned,unsigned,const std::string&);
	~Piece();
	bool player=false;
	bool bomb=false;
	bool enemy=false;
	unsigned x;
	unsigned y;
	std::string pixmap;
private:
};




#endif /* BOMBERMAN_INCLUDE_PIECE_H_ */
