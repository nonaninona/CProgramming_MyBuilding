//
// Created by DongHoony on 2019-11-20.
//

#include "land.h"
#include "gotoyx.h"
#include <stdio.h>
#include <stdlib.h>
#include <wincon.h>
#include <winbase.h>

void show_set_cursor_disable(){
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
}

void show_land_info(Land l){

}
void show_gameboard(Land* gameboard){

}
void show_player_move(Land* gameboard, Player* p, int from, int to){
    int label = p->label;
    if (label == PLAYER){
        gotoyx_set_color(C_BLUE);
        gotoyx_print(gameboard[from].p_player.y, gameboard[from].p_player.x, "  ");
        gotoyx_print(gameboard[to].p_player.y, gameboard[to].p_player.x, "PL");
        gotoyx_set_color(C_WHITE);
    }
    else{
        gotoyx_set_color(C_RED);
        gotoyx_print(gameboard[from].p_bot.y, gameboard[from].p_bot.x, "  ");
        gotoyx_print(gameboard[to].p_bot.y, gameboard[to].p_bot.x, "PC");
        gotoyx_set_color(C_WHITE);
    }
}

void show_gameboard_grid(){
    printf("忙式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式忖\n"); //0
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //1
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //2
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //3
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //4
    printf("弛                戍式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式扣                弛\n"); //5
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //6
    printf("戍式式式式式式式式式式成式式式式式托式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式托式式式式式成式式式式式式式式式式扣\n"); //7
    printf("弛          弛     弛                                                                                                     弛     弛          弛\n"); //8
    printf("弛          弛     弛   忙式式式式式式式式式式式式式式式式式式式式式式忖                                               忙式式式式式式式式式式式式式式式式式式式式式式忖   弛     弛          弛\n"); //9
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //10
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //11
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //12
    printf("戍式式式式式式式式式式托式式式式式扣   弛                      弛                                               弛                      弛   戍式式式式式托式式式式式式式式式式扣\n"); //13
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //14
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //15
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //16
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //17
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //18
    printf("戍式式式式式式式式式式托式式式式式扣   弛                      弛                                               弛                      弛   戍式式式式式托式式式式式式式式式式扣\n"); //19
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //20
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //21
    printf("弛          弛     弛   弛                      弛                                               弛                      弛   弛     弛          弛\n"); //22
    printf("弛          弛     弛   戌式式式式式式式式式式式式式式式式式式式式式式戎                                               戌式式式式式式式式式式式式式式式式式式式式式式戎   弛     弛          弛\n"); //23
    printf("弛          弛     弛                                                                                                     弛     弛          弛\n"); //24
    printf("戍式式式式式式式式式式扛式式式式式托式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式托式式式式式扛式式式式式式式式式式扣\n"); //25
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //26
    printf("弛                戍式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式扣                弛\n"); //27
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //28
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //29
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //30
    printf("弛                弛                弛                弛                弛                弛                弛                弛                弛\n"); //31
    printf("戌式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式戎\n"); //32
    // 17 Spaces per Block in row
}

void show_test_gameboard(Land* gameboard){
    int i, y, x;
    // need to simplify below
    for(i = 0; i < 22; i++){

        y = gameboard[i].p_player.y;
        x = gameboard[i].p_player.x;
        gotoyx_print(y, x, "PL");
        y = gameboard[i].p_bot.y;
        x = gameboard[i].p_bot.x;
        gotoyx_print(y, x, "PC");

        if (i == START_LAND || i == ABANDONED_ISLAND || i == TRAVEL || i == FESTIVAL) continue;

        y = gameboard[i].p_b1.y;
        x = gameboard[i].p_b1.x;
        gotoyx_print(y, x, "SS");
        y = gameboard[i].p_b2.y;
        x = gameboard[i].p_b2.x;
        gotoyx_print(y, x, "MM");
        y = gameboard[i].p_b3.y;
        x = gameboard[i].p_b3.x;
        gotoyx_print(y, x, "LL");
    }
    gotoyx(35, 0);
    system("pause");
}

int show_build_building(Land* gameboard, Player* p, int pos, int level){
    int label, i, color;
    Point building_pos[3] = {gameboard[pos].p_b1, gameboard[pos].p_b2, gameboard[pos].p_b3};
    char* building_str[3] = {"SS", "MM", "LL"};
    label = p->label;
    color = (label == PLAYER ? C_BLUE : C_RED);
    gotoyx_set_color(color);
    for(i = 0; i < level; i++){
        gotoyx_print(building_pos[i].y, building_pos[i].x, building_str[i]);
    }
    gotoyx_set_color(C_WHITE);
    return 0;
}

Level show_choice_buliding(Land* land, Player* p){
    Level level = land->level;
    const int X_COR[] = {54, 61, 68, 75, 82};
    int lap = p->lap;
    int i, cur;
    cur = 0;

    gotoyx_set_color(C_GREEN);
    gotoyx_print(18, 50, "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    gotoyx_print(19, 50, "弛         SELECT BUILDING.          弛");
    gotoyx_print(20, 50, "弛                                   弛");
    gotoyx_print(21, 50, "弛   --     --     --     --     --  弛");
    gotoyx_print(22, 50, "弛  LAND   VILA   BLDG   HTEL   LMRK 弛");
    gotoyx_print(23, 50, "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
    for(i = 0; i < 5; i++){
        if (i > lap){
            gotoyx_set_color(C_RED);
            gotoyx_print(21, X_COR[i], "XX");
        }
        else if (level.building[i] == 1){
            gotoyx_set_color(C_GREEN)''
            gotoyx_print(21, X_COR[i], "OK");
        }

    }
}

void show_dice_roll(int dice_v1, int dice_v2){
    const char* Y[6] = {NULL, " 1 ", " 2 ", " 3 ", " 4 ", " 5 "};
    const int DICEY = 14;
    const int DICEX[2] = {63, 73};
    int k;
    int rand1, rand2;
    for(k = 20; k < 50; k++){
        rand1 = rand() % 5 + 1;
        rand2 = rand() % 5 + 1;
        gotoyx_print(DICEY, DICEX[0], Y[rand1]);
        gotoyx_print(DICEY, DICEX[1], Y[rand2]);
        _sleep(k);
    }
    gotoyx_print(DICEY, DICEX[0], Y[dice_v1]);
    gotoyx_print(DICEY, DICEX[1], Y[dice_v2]);
}

void show_dice_grid(){
    int i, x = 10;
    gotoyx_set_color(C_CYAN);
    for(i = 0; i < 2; i++){
        gotoyx_print(13, 60 + i*x, "忙式式式式式忖");
        gotoyx_print(14, 60 + i*x, "弛     弛");
        gotoyx_print(15, 60 + i*x, "戌式式式式式戎");
    }
    gotoyx_set_color(C_WHITE);
}
