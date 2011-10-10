#pragma once
#ifndef CARD_H_
#define CARD_H_


#ifdef __cplusplus
extern "C" {
#endif

typedef int Priority;
struct RobotAction;
struct Robot;

typedef struct Card Card;

Card *Card_create(struct RobotAction *, Priority);
void Card_destroy(Card *);
void Card_apply(Card *, struct Robot *);

#ifdef __cplusplus
}
#endif

#endif /* CARD_H_ */
