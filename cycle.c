//
// Created by DongHoony on 2019-11-29.
//
#include <stdlib.h>
#include <time.h>
#include "cycle.h"
#include "player.h"
#include "random.h"
#include "show.h"
#include "gotoyx.h"
#include "money.h"

// includes animation
int move_cycle(Land* gameboard, Player* p, Dice d){
    int i;
    for(i = 0; i < d.d1 + d.d2; i++){
        show_player_move(gameboard, p, p->position, (p->position + 1) % MAX_TILE);
        player_move_value(p, 1);

        if (p->position == MAX_TILE) {
            money_get_income(p);

            show_money_update(p);
            p->position = 0;
            p->lap++;
            show_player_move(gameboard, p,21, 0);
        }
        _sleep(150);
    }
    return p->position;
}

int land_cycle(Land* land, Player* p, Resident* res){
    int label = p->label;
    int land_type = land->land_type;
    int* selected_building = NULL;
    int i, predicted_price, land_owner;

    // 도착한 곳 확인 (출발, 무인도와 같은 특별 타일인지, 일반 땅 타일인지 확인)

    //도착한 곳이 땅 타일이면
    if (land_type == NORMAL_TYPE){
        land_owner = land->label;

        // 빈 땅, 내 땅, 남 땅 확인 및 통행료 지급

        // 빈 땅이거나 내 땅이면 사면 됨
        if (land_owner == NO_ONE || land_owner == label){
            // 합 및 현재금액 -> show_choice에서 비교함
            selected_building = show_choice_building(land, p);
            for(i = 0; i < 5; i++){
                if (selected_building[i] == 1){
//                        gotoyx_print(34, 0, "Attempt to buy..");
                    land_buy(p, land, res, i);
                    _sleep(300);
                    show_money_update(p);
                }
            }
            free(selected_building);
            money_spend(p, predicted_price);
            show_money_update(p);
        }

            // 남 땅이면 통행료 냄
        else if (land_owner != label && land_owner != NO_ONE){
        }
    }
    //도착한 곳이 특별 타일이면
    if (land_type == SPECIAL_TYPE) {

    }
    return 0;
}

int game_cycle(Land* gameboard, Player* p, Resident* res){
    int pos, land_owner, label, double_count = 0;
    int is_double = 0, lap, i, predicted_price = 0;

    Dice dice;

    show_money_update(p);
    srand((unsigned)time(NULL));

    // label indicates whose turn now
    label = p->label;

    while (1){
        // 주사위 굴리기
        dice = rand_dice_roll();

        //test for control dice

        gotoyx(33, 50);
        printf("DICE :         ");
        gotoyx(33, 57);
        scanf("%d %d", &dice.d1, &dice.d2);

       // show_dice_roll(dice.d1, dice.d2);

        is_double = determine_double(dice);
        double_count += is_double ? 1 : 0;

        // 더블 두 번인지 체크하기, 2회 이상이면 무인도행
        if (double_count >= 2) {
            show_player_move(gameboard, p, p->position, ABANDONED_ISLAND);
            player_move_toward(p, ABANDONED_ISLAND);
            return 1;
        }

        // 움직이기
        p->position = move_cycle(gameboard, p, dice);
        pos = p->position;

        //temporary added thing
        gotoyx(33,0);
        printf("NOW AT %02d", p->position);

        //LAND CYCLE
        land_cycle(&gameboard[pos], p, res);

        // 더블이 아니면 루프 탈출하기
        if (is_double == NOT_DOUBLE) break;
    }
    return 0;
}