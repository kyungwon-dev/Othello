#include "Model.h"
#include <iostream>
int Model::_map[8][8] =
{ { 0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0 },
{ 0,0,0,1,2,0,0,0 },
{ 0,0,0,2,1,0,0,0 },
{ 0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0 }
};
char Model::_stone[6][4] =
{ { "●" },{ "★" },{ "♠" },{ "♥" },{ "☎" },{ "돌" } };
char Model::_player1[10] = { "" };
char Model::_player2[10] = { "컴퓨터" };
int Model::_player1score = 0;
int Model::_player2score = 0;
int Model::_changestone = 0;
int Model::_choice = 0;
int Model::_next = 0;
int Model::_turn = 0;

