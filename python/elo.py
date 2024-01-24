#!/usr/bin/env python3

import random

'''
Simple impl of the ELO rating algorithm where use use base of 400 and K factor of 25
the expected win and lose scores are 1 and 0 respectively (winner gets 1 and loser 0).
The simulation prints the top 10 player ids and their ratings at the end.

Algorithm:
input:
    list of players (int based)
    initial ratings (1000 each)
    number of games
    number of players
algorithm:
    - repeat for the number of games:
        - find win probabability based on current rating using 1/(1+pow(10, (r1-r2)/400)).
        To do this there has to be a game event where 2 players compete.
        - based on the outcome of the match update the ratings as: 
        cur_rating += K * (ACTUAL(1 or 0) - probability found above
    - print top 10 players based on rating
'''
K = 25
B = 400
def update_rating(cur_rating, prob, score):
    return cur_rating + K * (score - prob)

def prob_win(r1, r2):
    return 1/(1 + pow(10, (r1-r2)/B)), 1/(1 + pow(10, (r2-r1)/B))


def simulate(num_players=100, num_games=1000, print_every_game=True):
    players = list(range(num_players))
    ratings = [1000]*num_players
    for game in range(num_games):
        p1 = random.choice(players)
        p2 = 0
        while True:
            p2 = random.choice(players)
            if p1 != p2:
                break
        prob1, prob2 = prob_win(ratings[p1], ratings[p2])
        result  = random.randint(0,2)   # 0 means first player loses
        r1, r2 = ratings[p1], ratings[p2]
        if result == 0:
            ratings[p1] = update_rating(r1, prob1, 0)
            ratings[p2] = update_rating(r2, prob2, 1)
        if result == 1:
            ratings[p1] = update_rating(r1, prob1, 1)
            ratings[p2] = update_rating(r2, prob2, 0)
        if print_every_game:
            print(sorted(enumerate(ratings), key=lambda x:x[1])[:89:-1])

    print(sorted(enumerate(ratings), key=lambda x:x[1])[:89:-1])

simulate(100, 1000, print_every_game=False)
        

