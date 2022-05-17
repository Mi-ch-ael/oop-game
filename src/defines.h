#ifndef DEFINES_H
#define DEFINES_H

#define FIELD_WIDTH 4
#define FIELD_HEIGHT 3
#define BLOCK_SIZE 4
#define SOURCE "./blocks"

#define OBJECT_COUNT 7

#define ENTRANCE 0
#define EXIT 1
#define YELLOW 2
#define PURPLE 3
#define BONUS 4
#define CHESTRANGE 5
#define CHESTLIM 6

#define COUNT 3

#define PLAYER_STEPS_DEFAULT 40
#define PLAYER_RANGE_DEFAULT 1

#define ENTR_X 0
#define ENTR_Y 11
#define EXIT_X 15
#define EXIT_Y 0

//Enemy behaviour

#define WANDERING 0
#define SEARCHING 1
#define STUPID 2

//Game file extension

#define SAVED_PLAYER_PARAMS 5
#define SAVED_ENEMY_PARAMS 6

#define EXT "lvl"
#define PREFIX "LVL"

#define ENTRANCE_CHAR '^'
#define EXIT_CHAR 'E'
#define BONUS_CHAR '*'
#define YELLOW_CHAR 'Y'
#define PURPLE_CHAR 'P'
#define CHESTLIM_CHAR 'L'
#define CHESTRANGE_CHAR 'R'
#define SPARE_CHAR '.'
#define WALL_CHAR '#'

#endif // DEFINES_H
